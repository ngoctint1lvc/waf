local _M = {}

function _M.init()
    local ssl = require "ngx.ssl"
    local debug = require("common").debug
    local domain, _ = ssl.server_name()
    debug("ssl", "set ssl certificate for domain: " .. domain)

    -- check if ssl certificate of this domain is existed in redis
    local is_root_domain, err = require("domain_checker").is_root_domain(domain)
    if err then
        debug("ssl", err)
        return err
    end
    debug("ssl", "domain " .. domain .. (is_root_domain and " is" or " is not") .. " a root level domain")

    return nil
end

return _M