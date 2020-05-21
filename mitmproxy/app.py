from mitmproxy import proxy, options
from mitmproxy.tools.dump import DumpMaster
from mitmproxy.addons import core


class AddHeader:
    def __init__(self):
        self.num = 0

    def response(self, flow):
        self.num = self.num + 1
        print(self.num)
        flow.response.headers["count"] = str(self.num)


addons = [
    AddHeader()
]

opts = options.Options(listen_host='127.0.0.1', listen_port=8080)
pconf = proxy.config.ProxyConfig(opts)

m = DumpMaster(None)
m.server = proxy.server.ProxyServer(pconf)
# print(m.addons)
m.addons.add(addons)
# m.addons.add(core.Core())

try:
    m.run()
except KeyboardInterrupt:
    m.shutdown()