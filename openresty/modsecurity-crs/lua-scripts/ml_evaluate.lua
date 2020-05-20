package.path = package.path .. ";/opt/modsecurity-crs/lua-scripts/?.lua"
local util = require("util")

function main()
    util.waf_debug(m, "Starting script execution")
    local rules = m.getTriggeredRules()
    util.waf_debug(m, "triggered rules", rules)
    util.waf_debug(m, "lua package path", package.path)

    local num_rules = #rules
    util.waf_debug(m, "Number of triggered rules: " .. num_rules)
    -- if num_rules > 0 then
    --     return 1
    -- end
    -- don't block anything

    return nil
end
