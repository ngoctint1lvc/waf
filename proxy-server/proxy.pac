var FindProxyForURL = (function (init, profiles) {
    return function (url, host) {
        "use strict";
        var result = init,
            scheme = url.substr(0, url.indexOf(":"));
        do {
            result = profiles[result];
            if (typeof result === "function")
                result = result(url, host, scheme);
        } while (typeof result !== "string" || result.charCodeAt(0) === 43);
        return result;
    };
})("+luanvan", {
    "+luanvan": function (url, host, scheme) {
        "use strict";
        if (
            /^127\.0\.0\.1$/.test(host) ||
            /^::1$/.test(host) ||
            /^localhost$/.test(host) ||
            /^clients4\.google\.com$/.test(host) ||
            /^overleaf\.com$/.test(host) ||
            /\.overleaf\.com$/.test(host)
        )
            return "DIRECT";
        switch (scheme) {
            case "http":
                return "PROXY localhost:3004";
            case "https":
                return "PROXY localhost:3004";

            default:
                return "DIRECT";
        }
    },
});
