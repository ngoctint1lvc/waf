local _M = {}

local debug = require("common").debug

function _M.run()
    -- debug("ngx.status", ngx.status)
    -- debug("ngx.req.raw_header", ngx.req.raw_header())
    -- debug("ngx.resp.get_headers", ngx.resp.get_headers(0, true))

    local raw_request = ngx.req.raw_header()

    debug("RAW REQUEST", raw_request)
end

return _M