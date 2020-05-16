local _M = {}

function _M.init()
    local ssl = require "ngx.ssl"
    local debug = require("common").debug
    local domain, _ = ssl.server_name()
    debug("ssl", "set ssl certificate for domain: " .. domain)

    -- check if ssl certificate of this domain is existed in redis
    
end

return _M