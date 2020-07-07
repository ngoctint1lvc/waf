require("dotenv").config();

const dvwa = require("./modules/dvwa.js");
const yargs = require("yargs");

global._argv = yargs
    .command("dvwa <url>", "Test WAF with dvwa web page", {
        headless: {
            description: "run headless mode or not",
            type: "boolean",
            default: false,
        },
        blockstring: {
            description: "block string return from server",
            type: "string",
            default: "403 Forbidden",
        },
        config: {
            description: "configuration file location",
            type: "string",
            default: "test.json",
            alias: "c",
        },
        cookie: {
            description: "set cookie (overwrite existing cookies)",
            type: "string",
            default: "",
        },
        "no-reset": {
            description: "do not reset after each test",
            type: "boolean",
            default: false,
        },
        "ignore-dialog": {
            description: "ignore xss dialog",
            type: "boolean",
            default: false,
        },
        proxy: {
            description: "proxy server",
            type: "string",
            default: "http://localhost:3004",
        },
    })
    .count("verbose")
    .describe("verbose", "verbose")
    .alias("v", "verbose")
    .option("output", {
        description: "output directory",
        type: "string",
        alias: "o",
        default: "./outputs",
    })
    .help()
    .alias("help", "h").argv;

const {
    config,
    "ignore-dialog": ignoreDialog,
    verbose,
    headless,
    proxy
} = global._argv;


if (global._argv._ == "dvwa") {
    dvwa.testDVWA({
        config,
        ignoreDialog,
        verbose,
        headless,
        proxy
    });
}
else {
    yargs.showHelp();
}

