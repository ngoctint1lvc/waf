const net = require('net');
const utils = require('./utils.js');
const chalk = require('chalk');

function writeSocket(client, content) {
    return new Promise((resolve, reject) => {
        client.write(content, 'utf8', () => {
            resolve();
        });
    });
}

function connectSocket(host = 'localhost', port = 80) {
    return new Promise((resolve, reject) => {
        const client = new net.Socket();
        client.connect(port, host, function () {
            resolve(client);
        });

        client.on('error', err => {
            console.error(chalk.red('[x] Fail to connect socket'), err);
        });
    });
}

function waitForData(client, timeout = 7000) {
    return new Promise((resolve, reject) => {
        client.on('data', data => {
            resolve(data.toString());
        });

        client.setTimeout(timeout);

        client.on('timeout', () => {
            reject('timeout!');
        })
    })
}

/**
 * 
 * @param {string} host 
 * @param {integer} port 
 * @param {string} request 
 */
async function sendRequest(host, port, request) {
    let socket = await connectSocket(host, port);
    await writeSocket(socket, request);
    let data = await waitForData(socket).catch(err => {
        console.log("\nInvalid request!\n---------BEGIN----------\n" + request + "\n---------END----------\n");
        console.log(err);
    })
    socket.end();
    return data;
}

module.exports = {
    writeSocket,
    connectSocket,
    waitForData,
    sendRequest
}
