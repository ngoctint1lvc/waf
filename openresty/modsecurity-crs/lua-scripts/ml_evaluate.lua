package.path = package.path .. ";/opt/modsecurity-crs/lua-scripts/?.lua"
local util = require("util")

function main()
    util.waf_debug(m, "Starting script execution")
    local rules = m.getTriggeredRules()
    util.waf_debug(m, "triggered rules", rules)
    util.waf_debug(m, "lua package path", package.path)

    local num_rules = #rules
    util.waf_debug(m, "Number of triggered rules: " .. num_rules)

    -- waf_mode is 'LEARNING_ATTACK' or 'LEARNING_NORMAL' or 'NORMAL'
    -- In 'LEARNING_ATTACK' mode, waf will not block any request but will store them in waf.attack_log
    -- In 'LEARNING_NORMAL' mode, waf will not block any request and will store traffic in waf.normal_log
    -- In 'NORMAL' mode, waf will block any request which trigger >= 1 rules
    local waf_mode = m.getvar("TX.WAF_MODE")

    -- util.waf_debug(m, "Waf mode is " .. tostring(waf_mode))
    if waf_mode == 'LEARNING_ATTACK' or waf_mode == 'LEARNING_NORMAL' then
        return nil
    end

    if waf_mode ~= 'NORMAL' then
        m.log("Invalid waf mode: " .. tostring(waf_mode))
    end
    
    if num_rules > 0 then
        m.setvar("TX.WAF_REQUEST_BLOCKED", "1")
        return 1
    end

    -- -- TODO: Apply ML model

    m.setvar("TX.WAF_REQUEST_BLOCKED", "0")
    return nil
end
