const utils = require("./utils.js");
let chrome = require("./chrome.js");
const chalk = require("chalk");
const path = require("path");

/**
 *
 * @param {{url, payloadFile, type, isAttack: boolean, testLocation: {selector, submit}, constValues: Array<{selector,value}> }} options
 */
async function test(options, manifestPath, outputPath) {
    let payloadFilePath = utils.getAbsolutePath(
        options.payloadFile,
        manifestPath
    );
    let payloads = utils.readTxtFile(payloadFilePath);

    let outputFilePath = path.join(outputPath, `${options.type} - output.csv`);
    utils.removeFileIfExists(outputFilePath);

    const CSVHeaders = [
        { id: "url", title: "URL" },
        { id: "payload", title: "Payload" },
        { id: "expect", title: "Expect" },
        { id: "result", title: "Result" },
    ];

    let total = 0;
    let passed = 0;

    for (let payload of payloads) {
        total++;
        console.log("Testing", payload);

        let isBlocked = false;
        try {
            // await chrome.clearSiteData();
            // await login();
            // await setSecurityLevel("low");
            if (global._argv.cookie.length > 0) {
                await chrome.setCookie(global._argv.cookie);
            }

            const execURL = global._argv.url + options.url;
            await chrome.goTo(execURL);

            let formInput = [
                {
                    selector: options.testLocation.selector,
                    payload: payload,
                },
            ].concat(
                options.constValues.map((item) => ({
                    selector: item.selector,
                    payload: item.value,
                }))
            );

            await chrome.submit(formInput, options.testLocation.submit);
            // let headers = await chrome.getResponseHeader();

            await page.waitForNavigation({ waitUntil: "load" });

            let pageHtml = await page.evaluate(() => {
                return document.documentElement.outerHTML;
            });

            global._argv.verbose >= 2 && console.log(chalk.yellow(pageHtml));

            if (isBlockedByFirewall(pageHtml)) {
                console.log(chalk.green(`=> ✓ ✓ ✓ Blocked by firewall\n`));
                isBlocked = true;
            } else {
                console.log(chalk.red("=> X X X Bypass firewall success\n"));
            }

            headers = "";
            let result = "FAILED";
            const expect = "BLOCK";

            if (isBlocked) {
                result = "PASSED";
                passed++;
            }

            const url = options.url;
            const data = {
                url,
                payload,
                expect,
                result,
            };

            await utils.appendCSV(outputFilePath, CSVHeaders, data);
        } catch (err) {
            console.error(err);
        }
    }

    // Summary
    const summaryHeaders = [
        { id: "time", title: "Test Time" },
        { id: "type", title: "Attack Type" },
        { id: "passed", title: "Passed" },
        { id: "failed", title: "Failed" },
        { id: "total", title: "Total" },
    ];
    const failed = total - passed;
    const { type } = options;
    const passedPercent = utils.round((passed * 100) / total);
    const failedPercent = utils.subtract(100, passedPercent);

    const summaryData = {
        time: new Date(),
        type,
        passed: `${passed} (${passedPercent}%)`,
        failed: `${failed} (${failedPercent}%)`,
        total,
    };
    global._argv.verbose >= 1 && console.log(summaryData);

    const summaryOutput = path.join(outputPath, `Summary - output.csv`);

    await utils.appendCSV(summaryOutput, summaryHeaders, summaryData);
}

async function reset() {
    let currentUrl = await page.evaluate(() => {
        return location.href;
    });
    await chrome.clearSiteData();
    await login();
    await setSecurityLevel("low");
    await chrome.goTo(currentUrl);
}

async function setSecurityLevel(level = "low") {
    await page.setCookie({
        name: "security",
        value: level,
    });
}

async function login(username = "admin", password = "password") {
    await chrome.goTo(global._argv.url);

    await chrome.submit(
        [
            { selector: ".loginInput[type=text]", payload: username },
            { selector: ".loginInput[type=password]", payload: password },
        ],
        ".submit > input"
    );

    await page.waitForNavigation({ waitUntil: "load" });
}

function isBlockedByFirewall(html) {
    return html.indexOf(global._argv.blockstring) >= 0;
}

async function testDVWA({ config, ignoreDialog, verbose, headless, proxy }) {
    verbose >= 1 && console.log("[+] Initializing chromium browser ...");
    await chrome.openBrowser({
        headless,
        ignoreDialog,
        proxy_server: proxy,
    });
    verbose >= 1 && console.log("[+] Chromium opened");

    const manifest = utils.getAbsolutePath(config);

    let testData = require(manifest);
    const outputPath = utils.getAbsolutePath(global._argv.output);

    //Remove summary file if exist
    const summaryOutput = path.join(outputPath, `Summary - output.csv`);
    utils.removeFileIfExists(summaryOutput);
    utils.createFolderIfNotExist(outputPath);

    await login();
    await setSecurityLevel("low");

    for (let item of testData) {
        console.log(
            `-------------Begin of test [${item.type}] ----------------`
        );
        // TODO: Add performed time to output folder, each perform in one folder
        try {
            await test(item, path.dirname(manifest), outputPath);
        } catch (err) {
            console.log(err);
        }
        console.log(`-------------End of test [${item.type}] ----------------`);
    }

    if (headless) {
        verbose >= 1 && console.log("[+] Closing browser ...");
        await chrome.closeBrowser();
    }
}

module.exports = {
    setSecurityLevel,
    login,
    test,
    reset,
    testDVWA,
};
