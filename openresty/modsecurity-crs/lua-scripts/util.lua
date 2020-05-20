package.path = package.path .. ";/usr/local/openresty/nginx/lua-nginx/?.lua"

local cjson = require("cjson")
local print_table = require("common").print_table
local util = {}

function util.tablelength(T)
    local count = 0
    for _ in pairs(T) do
        count = count + 1
    end
    return count
end

local char_to_hex = function(c)
    return string.format("%%%02X", string.byte(c))
end

function util.urlencode(url)
    if url == nil then
        return
    end
    url = url:gsub("\n", "\r\n")
    url = url:gsub("([^%w ])", char_to_hex)
    url = url:gsub(" ", "+")
    return url
end

function util.waf_debug(m, ...)
    if not os.getenv("DEBUG") then
        return
    end

    local arg = {...}

    -- m.log(1, "[WAF][args] Num of arguments: " .. tostring(#arg))

    if #arg >= 2 then
        local tag, msg = arg[1], arg[2]
        if type(msg) == 'table' then
            msg = print_table(msg)
        end
        m.log(1, "[WAF][" .. tag .. "] " .. msg)
    elseif #arg == 1 then
        local msg = arg[1]
        if type(msg) == 'table' then
            msg = print_table(msg)
        end
        m.log(1, "[WAF] " .. msg)
    else
        m.log(1, "[WAF] Empty message")
    end
end

function util.strtohex(str)
    if type(str) ~= 'string' then
        return str
    end

    return (str:gsub('.', function (c)
        return string.format('%02X', string.byte(c))
    end))
end

function util.hextostr(str)
    if type(str) ~= 'string' then
        return str
    end

    return (str:gsub('..', function (cc)
        return string.char(tonumber(cc, 16))
    end))
end

return util