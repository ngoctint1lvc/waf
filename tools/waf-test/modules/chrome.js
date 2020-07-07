const pretty = require("pretty");
const cookie = require("cookie");
const puppeteer = require("puppeteer-extra");
const StealthPlugin = require("puppeteer-extra-plugin-stealth");
puppeteer.use(StealthPlugin());

/**
 *
 * @param {{ headless: boolean }} headless
 * @param {{ ignoreDialog: boolean }} options
 * @param {{ proxy_server: string }} proxy_server
 */
async function openBrowser(
    options = {
        headless: true,
        ignoreDialog: true,
        proxy_server: null,
    }
) {
    console.log(
        `Running test with headless is ${options.headless ? "on" : "off"}`
    );
    global.browser = await puppeteer.launch({
        headless: options.headless,
        args: options.proxy_server? [
            `--proxy-server=${options.proxy_server}`
        ]: null
    });
    global.page = await browser.newPage();

    page.on("dialog", async (dialog) => {
        if (options.ignoreDialog) {
            setTimeout(() => {
                dialog.dismiss();
            }, 1000);
        } else {
            dialog.dismiss();
        }
    });
}

async function closeBrowser() {
    await browser.close();
}

/**
 *
 * @param {Array<{selector,payload}>} inputs
 * @param {*} submitSelector
 */
async function submit(inputs, submitSelector) {
    await Promise.all(
        inputs.map((item) => page.waitForSelector(item.selector))
    );

    await page.evaluate(
        (inputs, submitSelector) => {
            inputs.forEach((item) => {
                document.querySelector(item.selector).value = item.payload;
            });
            document.querySelector(submitSelector).click();
        },
        inputs,
        submitSelector
    );
}

async function clearSiteData() {
    const client = await page.target().createCDPSession();
    await client.send("Network.clearBrowserCookies");
    await client.send("Network.clearBrowserCache");
}

/**
 *
 * @param {string} url
 */
async function goTo(url) {
    let response = await page.goto(url).catch(console.error);
    return response;
}

/**
 *
 * @param {integer} timeout
 * @returns {Promise<*>}
 */
function getResponseHeader(timeout = 7000) {
    return new Promise((resolve, reject) => {
        const onResponse = (response) => {
            page.removeListener("response", onResponse);
            resolve(response.headers());
        };

        page.on("response", onResponse);
        setTimeout(() => {
            page.removeListener("response", onResponse);
            resolve([]);
        }, timeout);
    });
}

/**
 *
 * @param {Array<{name, value}> | {name, value} | string } cookies
 */
async function setCookie(cookies) {
    if (typeof cookies === "string") {
        cookies = cookie.parse(cookies);
        cookies = Object.keys(cookies).map((key) => {
            return {
                name: key,
                value: cookies[key],
            };
        });
    } else if (!Array.isArray(cookies)) cookies = [cookies];

    await Promise.all(
        cookies.map((i) => {
            return page.setCookie({
                name: i.name,
                value: i.value,
            });
        })
    );
}

module.exports = {
    submit,
    goTo,
    clearSiteData,
    openBrowser,
    closeBrowser,
    getResponseHeader,
    setCookie
};
