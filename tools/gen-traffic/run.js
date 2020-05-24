const rawHttp = require("./raw-http.js");
const utils = require("./utils.js");
const yargs = require("yargs");
const cliProgress = require('cli-progress');

global._argv = yargs
    .command("csic-transform <url>", "Transform CSIC 2010 dataset")
    .command("csic-test <url>", "Test CSIC 2010 dataset", {
        output: {
            description: "output directory",
            type: "string",
            alias: "o",
            default: "./outputs",
        },
    })
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
                /^(GET|PUT|POST|DELETE|OPTIONS|TRACE|HEAD|CONNECT|PATCH) /
            ) === 0
        ) {
            // Begin of new request, check for previous request
            if (currentRequest) {
                yield currentRequest;
            }
            ignoreLine = false;
            currentRequest = "";
            line = line.replace(/http:\/\/localhost:8080/m, '');
        }

        if (line.match(/^Start - Id: \d+/m) || line.match(/^End - Id: \d+/m) || line.match(/^class: \w+/m)) {
            debug(3, `Ignore line: ${line}`);
            ignoreLine = true;
        }

        if (!ignoreLine) {
            currentRequest += line.replace(/^Host: .*$/m, `Host: ${hostName}`) + "\n";
        }
            
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

function debug(level, msg) {
    _argv.verbose >= level && console.log(`[${level}] ${msg}`);
}

(async function () {
    let command = _argv._;
    if (command == "csic-transform") {
        for (let item of csicData) {
            if (item.isAttack) {
                debug(1, `Change WAF mode to LEARNING_ATTACK`);
                await utils.shell("inv waf-mode-update learning_attack");
            }
            else {
                debug(1, `Change WAF mdoe to LEARNING_NORMAL`);
                await utils.shell('inv waf-mode-update learning_normal');
            }
            console.log(`Transforming ${item.type}`);
            let numRequests = parseInt(await utils.shell(`grep -P '^(GET|POST|PUT|DELETE|PATCH|OPTION|HEAD) ' ${item.payloadFile} | wc -l`));

            debug(0, `Number of requests: ${numRequests}`);
            const bar = new cliProgress.SingleBar({}, cliProgress.Presets.shades_classic);
            bar.start(numRequests, 0);

            let payloadFilePath = utils.getAbsolutePath(item.payloadFile);
            let url = _argv.url;
            const host = utils.hostFromUrl(url);
            const port = utils.portFromUrl(url);
            let httpRequests = readCSICDataset(payloadFilePath, host);

            for (let httpRequest of httpRequests) {
                debug(3, httpRequest);
                let data = await rawHttp.sendRequest('openresty.docker', port, httpRequest);
                data && debug(3, data.toString());
                bar.increment();
            }

            bar.stop();
        }
    } else if (command == "csic-test") {
        for (let item of csicData) {
            console.log(`[+] Testing ${item.type}`);
        }
    }
    else {
        yargs.showHelp();
    }
})();
