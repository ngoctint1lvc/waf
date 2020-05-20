local _M = {}
local debug = require("common").debug

function _M.is_root_domain(domain)
    local tldomain = _M.get_tldomain(domain)

    if not tldomain then
        return false, "invalid domain"
    end

    debug("ssl", "Top level domain of " .. domain .. " is " .. tldomain)

    -- remove suffix and check domain not contains . character
    -- Note: find . character, we need to disable regex
    return not domain:sub(1, -#tldomain - 2):find(".", 1, true), nil
end

function _M.get_tldomain(domain)
    local file = io.open("/usr/local/openresty/nginx/lua-nginx/public_suffix_list.txt", "rb")
    local tldomain = ""

    -- find the longest top level domain of this domain
    for line in file:lines() do
        if #line > #tldomain and domain:sub(-#line - 1) == "." .. line then
            tldomain = line
        end
    end

    file:close()

    return #tldomain > 0 and tldomain or nil
end

return _M