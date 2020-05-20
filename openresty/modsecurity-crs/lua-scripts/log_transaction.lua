package.path = package.path .. ";/opt/modsecurity-crs/lua-scripts/?.lua"
local util = require("util")
local cjson = require("cjson")

-- connect redis
-- local redis = require("redis")
-- local redis_client = redis.connect("redis", 6379)

local MONGODB_SERVER = os.getenv("MONGODB_SERVER")
local MONGODB_USER = util.urlencode(os.getenv("MONGODB_USER"))
local MONGODB_PASSWORD = util.urlencode(os.getenv("MONGODB_PASSWORD"))

local mongo = require("mongo")
local client = mongo.Client('mongodb://' .. MONGODB_USER .. ':' .. MONGODB_PASSWORD .. "@" .. MONGODB_SERVER .. "/admin")
local waf_normal_collection = client:getCollection('waf', 'normal_log')
local waf_attack_collection = client:getCollection('waf', 'attack_log')

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

    -- remove Server header from response
    response_headers["Server"] = nil
    
    local transaction = {
        ["matched_rules"] = m.getTriggeredRules(),
        ["remote_ip"] = m.getvar("REMOTE_ADDR"),
        ["uri"] = m.getvar("REQUEST_URI"),
        ["request_method"] = m.getvar("REQUEST_METHOD"),
        ["request_headers"] = request_headers,
        ["request_body"] = m.getvar("REQUEST_BODY") or '',
        ["response_status"] = tonumber(m.getvar("RESPONSE_STATUS")),
        ["response_headers"] = response_headers,
        -- ["response_body"] = m.getvar("RESPONSE_BODY") or '' -- Need to fix gzip Content-Encoding
    }
    util.waf_debug(m, "transaction", transaction)

    local waf_mode = m.getvar("TX.WAF_MODE")
    util.waf_debug(m, "Current waf mode: " .. tostring(waf_mode))

    if waf_mode == 'LEARNING_NORMAL' then
        waf_normal_collection:insert(cjson.encode(transaction))
    elseif waf_mode == 'LEARNING_ATTACK' then
        waf_attack_collection:insert(cjson.encode(transaction))
    end

    local is_blocked = m.getvar("TX.WAF_REQUEST_BLOCKED") == "1"
    if not is_blocked then
        waf_normal_collection:insert(cjson.encode(transaction))
    else
        waf_attack_collection:insert(cjson.encode(transaction))
    end
end