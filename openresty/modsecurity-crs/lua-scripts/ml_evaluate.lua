package.path = package.path .. ";/opt/modsecurity-crs/lua-scripts/?.lua"
local util = require("util")

function should_block(rules)
    -- TODO: Apply ML model
    return #rules >= 1
end

function main()
    util.waf_debug(m, "Starting script execution")
    local rules = m.getTriggeredRules()
    -- util.waf_debug(m, "triggered rules", rules)
    -- util.waf_debug(m, "lua package path", package.path)

    util.waf_debug(m, "Number of triggered rules: " .. #rules)

    -- waf_mode is one of the following
    -- In 'LEARNING_ATTACK' mode, waf will not block any request but will store them in waf.attack_log
    -- In 'LEARNING_NORMAL' mode, waf will not block any request and will store traffic in waf.normal_log
    -- In 'LEARNING_UNKNOWN' mode, waf will block attack requests and store all requests in log
    -- In 'PRODUCTION' mode, waf will block attack requests but not store any requests log
    local waf_mode = m.getvar("TX.WAF_MODE") or 'PRODUCTION'

    -- request may be blocked in 'LEARNING_UNKNOWN' and 'PRODUCTION' mode
    if waf_mode == 'LEARNING_UNKNOWN' or waf_mode == 'PRODUCTION' then
        if should_block(rules) then
            m.setvar("TX.WAF_REQUEST_BLOCKED", "1")
            return 1
        end
    end

    m.setvar("TX.WAF_REQUEST_BLOCKED", "0")
    return nil
end
