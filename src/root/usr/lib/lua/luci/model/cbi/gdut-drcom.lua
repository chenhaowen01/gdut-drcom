--[[
LuCI - Lua Configuration Interface

Copyright 2010 Jo-Philipp Wich <xm@subsignal.org>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0
]]--

require("luci.sys")

m = Map("gdut_drcom", translate("gdut-drcom Client"), translate("Configure gdut-drcom client."))

s = m:section(TypedSection, "gdut_drcom", "")
s.addremove = false
s.anonymous = true

enable = s:option(Flag, "enable", translate("Enable"))
remote_ip = s:option(Value, "remote_ip", translate("Remote ip"))
keep_alive_flag = s:option(Value, "keep_alive1_flag", translate("Keep alive1 flag"))

local apply = luci.http.formvalue("cbi.apply")
if apply then
	io.popen("echo gdut-drcom apply >> /root/gdut-drcom.log")
end

return m

