browser.runtime.onInstalled.addListener((details) => {
    console.log("previousVersion", details.previousVersion);
});

browser.browserAction.setBadgeText({
    text: `'Allo`,
});


const filter = {
    "urls": [
        "http://*/*",
        "https://*/*",
        "ws://*/*",
        "wss://*/*"
    ]
}


chrome.webRequest.onBeforeRequest.addListener(details => {
    console.dir(details);

    const captureHostRegex = /(?<=:\/\/)[\w.-]+\b(?=[?#\/]?)/;
    // const host = url.match(captureHostRegex)[0];
    // let modifiedHeaders = details.requestHeaders;

    // console.log(details.requestHeaders);

    // modifiedHeaders.push({
    //     name: "Host",
    //     value: host
    // });

    console.log("url", details.url.replace(captureHostRegex, 'localhost'));

    return {
        redirectUrl: details.url, //.replace(captureHostRegex, 'localhost'),
        requestHeaders: [
            {
                name: "Host",
                value: "google.com"
            }
        ]
    }
}, filter, ["blocking", "extraHeaders", "requestBody"]);

console.log(`'Allo 'Allo! Event Page for Browser Action`);
