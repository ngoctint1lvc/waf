package.path = package.path .. ";/opt/modsecurity-crs/lua-scripts/?.lua"
local util = require("util")
local cjson = require("cjson")

local MONGODB_SERVER = os.getenv("MONGODB_SERVER")
local MONGODB_USER = util.urlencode(os.getenv("MONGODB_USER"))
local MONGODB_PASSWORD = util.urlencode(os.getenv("MONGODB_PASSWORD"))

local mongo = require("mongo")
local client = mongo.Client('mongodb://' .. MONGODB_USER .. ':' .. MONGODB_PASSWORD .. "@" .. MONGODB_SERVER .. "/admin")
local waf_log_collection = client:getCollection('waf', 'traffic_log')

function main()
    util.waf_debug(m, "Log transaction run!")

    local request_headers = {}
    for i, header in ipairs(m.getvars("REQUEST_HEADERS")) do
        request_headers[header.name:sub(#"REQUEST_HEADERS:" + 1)] = header.value
    end
    util.waf_debug(m, "headers", request_headers)

    local response_headers = {}
    for i, header in ipairs(m.getvars("RESPONSE_HEADERS")) do
        response_headers[header.name:sub(#"RESPONSE_HEADERS:" + 1)] = header.value
    end
    util.waf_debug(m, "headers", response_headers)
    
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

    waf_log_collection:insert(cjson.encode(transaction))
end