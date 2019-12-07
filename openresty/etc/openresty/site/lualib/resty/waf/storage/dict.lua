local _M = {}

local base    = require "resty.waf.base"
local cjson   = require "cjson"
local logger  = require "resty.waf.log"
local storage = require "resty.waf.storage"

_M.version = base.version

_M.col_prefix = storage.col_prefix

function _M.initialize(waf, storage, col)
	if not waf._storage_zone then
		logger.fatal_fail("No storage_zone configured for memory-based persistent storage")
	end

	local col_name = _M.col_prefix .. col

	local altered, serialized, shm
	shm        = ngx.shared[waf._storage_zone]
	serialized = shm:get(col_name)
	altered    = false

	if not serialized then
		if waf._debug == true then ngx.log(waf._debug_log_level, '[', waf.transaction_id, '] ', "Initializing an empty collection for " .. col) end
		storage[col] = {}
	else
		local data = cjson.decode(serialized)

		-- because we're serializing out the contents of the collection
		-- we need to roll our own expire handling. lua_shared_dict's
		-- internal expiry can't act on individual collection elements
		for key in pairs(data) do
			if not key:find("__", 1, true) and data["__expire_" .. key] then
				if waf._debug == true then ngx.log(waf._debug_log_level, '[', waf.transaction_id, '] ', "checking " .. key) end
				if data["__expire_" .. key] < ngx.now() then
					if waf._debug == true then ngx.log(waf._debug_log_level, '[', waf.transaction_id, '] ', "Removing expired key: " .. key) end
					data["__expire_" .. key] = nil
					data[key] = nil
					altered = true
				end
			end
		end

		storage[col] = data
	end

	storage[col]["__altered"] = altered
end

function _M.persist(waf, col, data)
	if not waf._storage_zone then
		logger.fatal_fail("No storage_zone configured for memory-based persistent storage")
	end

	local shm        = ngx.shared[waf._storage_zone]
	local serialized = cjson.encode(data)

	if waf._debug == true then ngx.log(waf._debug_log_level, '[', waf.transaction_id, '] ', 'Persisting value: ' .. tostring(serialized)) end

	local col_name = _M.col_prefix .. col

	local ok, err = shm:set(col_name, serialized)

	if not ok then
		logger.warn(waf, "Error adding key to persistent storage, increase the size of the lua_shared_dict " .. waf._storage_zone)
	end
end


return _M
