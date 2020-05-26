const rawHttp = require("./raw-http.js");
const utils = require("./utils.js");
const yargs = require("yargs");
const cliProgress = require("cli-progress");
const { Worker } = require("worker_threads");

global._argv = yargs
    .command("csic-transform <url>", "Transform CSIC 2010 dataset")
    .command("ecml-transform <url>", "Transform ECML PKDD dataset")
    .count("verbose")
    .describe("verbose", "change verbose level with -v -vv or -vvv")
    .alias("v", "verbose")
    .help()
    .alias("help", "h").argv;

function* readCSICDataset(filePath, hostName) {
    let httpFile = utils.readTxtFile(filePath);

    let currentRequest = "";
    let ignoreLine = false;
    for (let line of httpFile) {
        if (
            line.search(
                /^(GET|PUT|POST|DELETE|OPTIONS|TRACE|HEAD|CONNECT|PATCH) /m
            ) === 0
        ) {
            // Begin of new request, check for previous request
            if (currentRequest) {
                yield currentRequest;
            }
            ignoreLine = false;
            currentRequest = "";
            line = line.replace(/http:\/\/localhost:8080/m, "");
        }

        if (
            line.match(/^Start - Id: \d+/m) ||
            line.match(/^End - Id: \d+/m) ||
            line.match(/^class: \w+/m)
        ) {
            debug(3, `Ignore line: ${line}`);
            ignoreLine = true;
        }

        if (!ignoreLine) {
            currentRequest +=
                line.replace(/^Host: .*$/m, `Host: ${hostName}`) + "\n";
        }
    }

    if (currentRequest) {
        yield currentRequest;
    }
}

function* readECMLDataset(filePath, hostName) {
    let httpFile = utils.readTxtFile(filePath);

    let currentRequest = "";
    let isAttack = false;
    let ignoreLine = false;

    for (let line of httpFile) {
        ignoreLine = false;

        if (line.match(/^End - Id: \d+/m)) {
            // Begin of new request, check for previous request
            if (currentRequest) {
                yield currentRequest;
            }

            // reset some metrics
            currentRequest = "";
        }

        // check if this request is attack or normal
        let matchedData = line.match(/^class: (.*)$/m);
        if (matchedData) {
            isAttack = matchedData[1] != "Valid";
        }

        if (
            line.match(/^Start - Id: \d+/m) ||
            line.match(/^End - Id: \d+/m) ||
            line.match(/^class: .*$/m) ||
            line.match(/^----: /) ||
            line.match(/^~~~~~: /)
        ) {
            debug(3, `Ignore line: ${line}`);
            ignoreLine = true;
        }

        if (!ignoreLine) {
            currentRequest +=
                line.replace(/^Host: .*$/m, `Host: ${hostName}`) + "\n";
            if (line.match(/^Host: .*$/m)) {
                // append X-WAF-Mode header after Host header
                currentRequest +=
                    "X-WAF-Mode: " +
                    (isAttack ? "LEARNING_ATTACK" : "LEARNING_NORMAL") +
                    "\n";
            }
        }
    }

    if (currentRequest) {
        yield currentRequest;
    }
}

const csicData = [
    {
        payloadFile: "./data/cisc_anomalousTraffic_test.txt",
        type: "CSIC anomalous traffic test",
        isAttack: true,
    },
    {
        payloadFile: "./data/cisc_normalTraffic_test.txt",
        type: "CSIC normal traffic test",
        isAttack: false,
    },
    {
        payloadFile: "./data/cisc_normalTraffic_train.txt",
        type: "CSIC normal traffic training",
        isAttack: false,
    },
];

const ecmlData = [
    {
        payloadFile: "./data/xml_test.txt",
        type: "Traffic test",
    },
    {
        payloadFile: "./data/xml_train.txt",
        type: "Traffic train",
    },
];

function debug(level, msg) {
    _argv.verbose >= level && console.log(`[${level}] ${msg}`);
}

async function countNumRequests(datasetFile) {
    return parseInt(
        await utils.shell(
            `grep -P '^(GET|POST|PUT|DELETE|PATCH|OPTION|HEAD) ' ${datasetFile} | wc -l`
        )
    );
}

async function sendRequests(httpRequests, port, numRequests) {
    const bar = new cliProgress.SingleBar(
        {},
        cliProgress.Presets.shades_classic
    );
    bar.start(numRequests, 0);

    for (let httpRequest of httpRequests) {
        debug(3, httpRequest);
        let data = await rawHttp.sendRequest(
            "openresty.docker",
            port,
            httpRequest
        );
        data && debug(3, data.toString());
        bar.increment();
    }
    bar.stop();
}

async function sendRequestsMultithread(httpRequests, port, numRequests) {
    const bar = new cliProgress.SingleBar(
        {},
        cliProgress.Presets.shades_classic
    );
    bar.start(numRequests, 0);

    let buffer = [];
    let maxBufferSize = 50;

    let workerPool = [];
    for (let i = 0; i < maxBufferSize; i++) {
        const worker = new Worker("./request-worker.js", {
            workerData: port,
        });
        workerPool.push(worker);
    }

    while (true) {
        let { value, done } = httpRequests.next();

        if (done || buffer.length === maxBufferSize) {
            await Promise.all(
                buffer.map((httpRequest, idx) => {
                    return new Promise((resolve, reject) => {
                        const worker = workerPool[idx];
                        worker.postMessage(httpRequest);
                        worker.removeAllListeners();
                        worker.on("message", (value) => {
                            if (!value.success) console.log(value.data);
                            resolve(value);
                        });
                        worker.on("error", reject);
                    }).catch(console.error);
                })
            );

            bar.increment(buffer.length);
            buffer = [];
            if (done) {
                bar.stop();
                break;
            }
        } else {
            buffer.push(value);
        }
    }
}

(async function () {
    let command = _argv._;
    if (command == "csic-transform") {
        for (let item of csicData) {
            if (item.isAttack) {
                debug(1, `Change WAF mode to LEARNING_ATTACK`);
                await utils.shell(
                    "inv config-update -p csic -m learning_attack"
                );
            } else {
                debug(1, `Change WAF mode to LEARNING_NORMAL`);
                await utils.shell(
                    "inv config-update -p csic -m learning_normal"
                );
            }
            console.log(`Transforming ${item.type}`);

            let numRequests = await countNumRequests(item.payloadFile);
            debug(0, `Number of requests: ${numRequests}`);

            let payloadFilePath = utils.getAbsolutePath(item.payloadFile);
            let url = _argv.url;
            const host = utils.hostFromUrl(url);
            const port = utils.portFromUrl(url);
            let httpRequests = readCSICDataset(payloadFilePath, host);

            // await sendRequests(httpRequests, port, numRequests);
            await sendRequestsMultithread(httpRequests, port, numRequests);
        }
    } else if (command == "ecml-transform") {
        debug(1, `Change WAF mode to LEARNING_ATTACK`);
        await utils.shell("inv config-update -p ecml -m learning_attack");

        for (let item of ecmlData) {
            console.log(`Transforming ${item.type}`);

            let numRequests = await countNumRequests(item.payloadFile);
            debug(0, `Number of requests: ${numRequests}`);

            let payloadFilePath = utils.getAbsolutePath(item.payloadFile);
            let url = _argv.url;
            const host = utils.hostFromUrl(url);
            const port = utils.portFromUrl(url);
            let httpRequests = readECMLDataset(payloadFilePath, host);

            await sendRequestsMultithread(httpRequests, port, numRequests);
        }
    } else {
        yargs.showHelp();
    }
})();
