module("luci.controller.gdut-drcom", package.seeall)

function index()
	entry({"admin", "network", "gdut-drcom"}, cbi("gdut-drcom"), _("gdut-drcom client"), 100)
	end
