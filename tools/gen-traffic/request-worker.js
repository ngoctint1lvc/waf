const { parentPort, workerData } = require("worker_threads");
const rawHttp = require("./raw-http");
const port = workerData;

parentPort.on("message", httpRequest => {
    rawHttp.sendRequest('openresty.docker', port, httpRequest).then(data => {
        parentPort.postMessage({
            success: true,
            data
        });
    }).catch(err => {
        let msg = "\nInvalid request!\n---------BEGIN----------\n" + httpRequest + "\n---------END----------\n";
        parentPort.postMessage({
            success: false,
            data: msg
        });
    });
});