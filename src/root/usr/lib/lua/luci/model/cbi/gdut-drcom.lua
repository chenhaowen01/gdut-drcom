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

--[[enabledial = s:option(Flag, "enabledial", translate("Enable PPPoE Dial"))
enabledial.default = enabledial.enabled

ifname = s:option(ListValue, "ifname", translate("Interface name"))
ifname:depends("enabledial", "1")
for k, v in ipairs(luci.sys.net.devices()) do
	if string.sub(v,0,3) == "eth" then
		ifname:value(v)
	end
end

username = s:option(Value, "username", translate("Username"))
username:depends("enabledial", "1")
password = s:option(Value, "password", translate("Password"))
password:depends("enabledial", "1")
password.password = true
]]--
macaddr = s:option(Value, "macaddr", translate("Mac address"))
macaddr.datatype="macaddr"
remote_ip = s:option(Value, "remote_ip", translate("Remote ip"))
remote_ip.datatype="ipaddr"
keep_alive_flag = s:option(Value, "keep_alive1_flag", translate("Keep alive1 flag"))

local apply = luci.http.formvalue("cbi.apply")
if apply then
	io.popen("/etc/init.d/gdut-drcom restart")
end

return m

