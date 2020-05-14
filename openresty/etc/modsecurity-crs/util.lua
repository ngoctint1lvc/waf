local cjson = require("cjson")
local util = {}

function util.print_table(node)
    local cache, stack, output = {}, {}, {}
    local depth = 1
    local output_str = "{\n"

    while true do
        local size = 0
        for k, v in pairs(node) do
            size = size + 1
        end

        local cur_index = 1
        for k, v in pairs(node) do
            if (cache[node] == nil) or (cur_index >= cache[node]) then
                if (string.find(output_str, "}", output_str:len())) then
                    output_str = output_str .. ",\n"
                elseif not (string.find(output_str, "\n", output_str:len())) then
                    output_str = output_str .. "\n"
                end

                -- This is necessary for working with HUGE tables otherwise we run out of memory using concat on huge strings
                table.insert(output, output_str)
                output_str = ""

                local key
                if (type(k) == "number" or type(k) == "boolean") then
                    key = "[" .. tostring(k) .. "]"
                else
                    key = "['" .. tostring(k) .. "']"
                end

                if (type(v) == "number" or type(v) == "boolean") then
                    output_str = output_str .. string.rep("\t", depth) .. key .. " = " .. tostring(v)
                elseif (type(v) == "table") then
                    output_str = output_str .. string.rep("\t", depth) .. key .. " = {\n"
                    table.insert(stack, node)
                    table.insert(stack, v)
                    cache[node] = cur_index + 1
                    break
                else
                    output_str = output_str .. string.rep("\t", depth) .. key .. " = '" .. tostring(v):gsub("%z", "") .. "'"
                end

                if (cur_index == size) then
                    output_str = output_str .. "\n" .. string.rep("\t", depth - 1) .. "}"
                else
                    output_str = output_str .. ","
                end
            else
                -- close the table
                if (cur_index == size) then
                    output_str = output_str .. "\n" .. string.rep("\t", depth - 1) .. "}"
                end
            end

            cur_index = cur_index + 1
        end

        if (size == 0) then
            output_str = output_str .. "\n" .. string.rep("\t", depth - 1) .. "}"
        end

        if (#stack > 0) then
            node = stack[#stack]
            stack[#stack] = nil
            depth = cache[node] == nil and depth + 1 or depth - 1
        else
            break
        end
    end

    -- This is necessary for working with HUGE tables otherwise we run out of memory using concat on huge strings
    table.insert(output, output_str)
    output_str = table.concat(output)

    return output_str
end

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
    local arg = {...}

    -- m.log(9, "[WAF][args] Num of arguments: " .. tostring(#arg))

    if #arg >= 2 then
        local tag, msg = arg[1], arg[2]
        m.log(9, "[WAF][" .. tag .. "] " .. msg)
    elseif #arg == 1 then
        local msg = arg[1]
        m.log(9, "[WAF] " .. msg)
    else
        m.log(9, "[WAF] Empty message")
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