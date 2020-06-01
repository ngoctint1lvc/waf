package.path = package.path .. ";/opt/modsecurity-crs/lua-scripts/?.lua"
local util = require("util")
local cjson = require("cjson")

-- connect redis
-- local redis = require("redis")
-- local redis_client = redis.connect("redis", 6379)

local MONGODB_SERVER = os.getenv("MONGODB_SERVER")
local MONGODB_USER = util.urlencode(os.getenv("MONGODB_USER"))
local MONGODB_PASSWORD = util.urlencode(os.getenv("MONGODB_PASSWORD"))
local collection_prefix = (#os.getenv("COLLECTION_PREFIX") > 0) and (os.getenv("COLLECTION_PREFIX") .. '_') or ''

local mongo = require("mongo")
local client = mongo.Client('mongodb://' .. MONGODB_USER .. ':' .. MONGODB_PASSWORD .. "@" .. MONGODB_SERVER .. "/admin")

util.waf_debug(m, 'Current collection prefix: ' .. collection_prefix)
local waf_normal_collection = client:getCollection('waf', collection_prefix .. 'normal_log')
local waf_attack_collection = client:getCollection('waf', collection_prefix .. 'attack_log')
local waf_maybe_normal_collection = client:getCollection('waf', collection_prefix .. 'maybe_normal_log')
local waf_maybe_attack_collection = client:getCollection('waf', collection_prefix .. 'maybe_attack_log')
local waf_production_collection = client:getCollection('waf', collection_prefix .. 'production_log')

function main()
    util.waf_debug(m, "Log transaction run!")

    local request_headers = {}
    for i, header in ipairs(m.getvars("REQUEST_HEADERS")) do
        request_headers[header.name:sub(#"REQUEST_HEADERS:" + 1)] = header.value
    end

    local response_headers = {}
    for i, header in ipairs(m.getvars("RESPONSE_HEADERS")) do
        response_headers[header.name:sub(#"RESPONSE_HEADERS:" + 1)] = header.value
    end
    
    local transaction = {
        ["matched_rules"] = m.getTriggeredRules(),
        ["remote_ip"] = m.getvar("REMOTE_ADDR"),
        ["uri"] = m.getvar("REQUEST_URI"),
        ["request_method"] = m.getvar("REQUEST_METHOD"),
        ["request_headers"] = request_headers,
        ["request_body"] = m.getvar("REQUEST_BODY") or '',
        ["response_status"] = tonumber(m.getvar("RESPONSE_STATUS")),
        ["response_headers"] = response_headers
    }
    util.waf_debug(m, "transaction", transaction)

    -- Allow single request to overwrite WAF mode
    local waf_mode = request_headers["X-WAF-Mode"] or m.getvar("TX.WAF_MODE")
    util.waf_debug(m, "Current waf mode: " .. tostring(waf_mode))

    local is_blocked = m.getvar("TX.WAF_REQUEST_BLOCKED") == "1"
    util.waf_debug(m, "TX.WAF_REQUEST_BLOCKED = " .. tostring(m.getvar("TX.WAF_REQUEST_BLOCKED")))

    if waf_mode == 'LEARNING_NORMAL' then
        waf_normal_collection:insert(cjson.encode(transaction))
        util.waf_debug(m, "Added transaction to normal database")
    elseif waf_mode == 'LEARNING_ATTACK' then
        waf_attack_collection:insert(cjson.encode(transaction))
        util.waf_debug(m, "Added transaction to attack database")
    elseif waf_mode == 'LEARNING_UNKNOWN' then
        if is_blocked then
            waf_maybe_attack_collection:insert(cjson.encode(transaction))
            util.waf_debug(m, "Added transaction to maybe attack database")
        else
            waf_maybe_normal_collection:insert(cjson.encode(transaction))
            util.waf_debug(m, "Added transaction to maybe normal database")
        end
    elseif waf_mode == 'PRODUCTION' then
        transaction.is_blocked = is_blocked
        waf_production_collection:insert(cjson.encode(transaction))
        util.waf_debug(m, "Added transaction to production database")
    else
        util.waf_debug(m, "Invalid waf mode " .. tostring(waf_mode))
    end

    return 1
end