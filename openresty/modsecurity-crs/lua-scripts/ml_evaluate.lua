package.path = package.path .. ";/opt/modsecurity-crs/lua-scripts/?.lua"
package.cpath = package.cpath .. ";/opt/modsecurity-crs/lua-scripts/ml-model/?.so"
local util = require("util")
-- local ml_model = require("decision_tree")
local ml_model = require("random_forest")

function should_block(m, rules)
    local features = {
        '944130',
        '943110',
        '942100',
        '942101',
        '921110',
        '942110',
        '921120',
        '942120',
        '921130',
        '941100',
        '941101',
        '942130',
        '941110',
        '942140',
        '921150',
        '921151',
        '941120',
        '942150',
        '921160',
        '941130',
        '942160',
        '944210',
        '941140',
        '921180',
        '941150',
        '942180',
        '921190',
        '941160',
        '920170',
        '942190',
        '944240',
        '941170',
        '920180',
        '942200',
        '944250',
        '941180',
        '942210',
        '941190',
        '942220',
        '941200',
        '942230',
        '941210',
        '920220',
        '942240',
        '941220',
        '920230',
        '942250',
        '942251',
        '944300',
        '941230',
        '920240',
        '942260',
        '941240',
        '942270',
        '941250',
        '920260',
        '942280',
        '941260',
        '920270',
        '920271',
        '920274',
        '942290',
        '934100',
        '941270',
        '942300',
        '941280',
        '942310',
        '941290',
        '920300',
        '933100',
        '942320',
        '941300',
        '933110',
        '933111',
        '942330',
        '911100',
        '941310',
        '920320',
        '933120',
        '932100',
        '942340',
        '941320',
        '932105',
        '933130',
        '933131',
        '932106',
        '932110',
        '942350',
        '941330',
        '932115',
        '933140',
        '942360',
        '932120',
        '942361',
        '931100',
        '941340',
        '933150',
        '933151',
        '953120',
        '920350',
        '942370',
        '932130',
        '931110',
        '941350',
        '933160',
        '933161',
        '932140',
        '942380',
        '931120',
        '941360',
        '933170',
        '930100',
        '932150',
        '942390',
        '931130',
        '941370',
        '933180',
        '930110',
        '932160',
        '942400',
        '200002',
        '941380',
        '933190',
        '930120',
        '942410',
        '951120',
        '930130',
        '942420',
        '942421',
        '950100',
        '933210',
        '942430',
        '942431',
        '942432',
        '932190',
        '920420',
        '942440',
        '942450',
        '920440',
        '942460',
        '950140',
        '942470',
        '920460',
        '942480',
        '920470',
        '942490',
        '942500',
        '942510',
        '942511',
        '920500',
        '951240',
        '944100',
        '944110',
        '944120',
        'request_method_GET',
        'request_method_HEAD',
        'request_method_OPTIONS',
        'request_method_POST',
        'request_method_PUT',
    }

    local request_method = m.getvar("REQUEST_METHOD")

    local features_arr = {}

    for i, v in ipairs(features) do
        for k, rule in pairs(rules) do
            if tostring(rule["id"]) == v then
                features_arr[i] = 1
                goto continue
            end
        end

        if v:sub(0, #"request_method") == "request_method" and v:sub(#"request_method_" + 1) == request_method then
            features_arr[i] = 1
        else
            features_arr[i] = 0
        end
        
        ::continue::
        if features_arr[i] == 1 then
            util.waf_debug(m, "ml_feature", v .. " = " .. features_arr[i])
        end
    end

    -- util.waf_debug(m, "features", features)
    -- util.waf_debug(m, "features_arr", features_arr)

    -- util.waf_debug(m, "decision_tree", ml_model)

    -- local ok, ml_result = pcall(function ()
    --     return ml_model.predict(features_arr)
    -- end)
    local ml_result = ml_model.predict(features_arr)

    if ml_result > 0 then
        local is_false_positive = true

        -- all features is 0 except for request_method
        for i=1, #features do
            if features_arr[i] == 1 and features[i]:sub(0, #"request_method") ~= "request_method" then
                is_false_positive = false
                break
            end
        end
        
        if is_false_positive then
            util.debug(m, "False positive in ml model")
            ml_result = 0
        end
    end

    -- util.waf_debug(m, "ok", ok)
    util.waf_debug(m, "ml_result", ml_result)
    return ml_result > 0
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
    -- In 'PRODUCTION' mode, waf will block attack requests and store all requests in production log
    local waf_mode = m.getvar("TX.WAF_MODE") or 'PRODUCTION'

    -- request may be blocked in 'LEARNING_UNKNOWN' and 'PRODUCTION' mode
    if waf_mode == 'LEARNING_UNKNOWN' or waf_mode == 'PRODUCTION' then
        if should_block(m, rules) then
            m.setvar("TX.WAF_REQUEST_BLOCKED", "1")
            return 1
        end
    end

    m.setvar("TX.WAF_REQUEST_BLOCKED", "0")
    return nil
end
