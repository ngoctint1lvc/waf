const lineByLine = require('n-readlines');
const fs = require('fs');
const path = require('path');
const csvWriter = require('csv-writer');
const childProcess = require('child_process');

async function shell(cmd) {
    return new Promise((resolve, reject) => {
        childProcess.exec(cmd, {
            stdio: 'inherit',
            shell: true
        }, (err, stdout, stderr) => {
            if (err) return reject(err);
            return resolve(stdout);
        });
    });
}

function createFolderIfNotExist(folder) {
    if (!fs.existsSync(folder)) {
        fs.mkdirSync(folder);
    }
}

function removeFilesInFolder(directory) {
    fs.readdir(directory, (err, files) => {
        if (err) throw err;

        for (const file of files) {
            fs.unlink(path.join(directory, file), err => {
                if (err) throw err;
            });
        }
    });
}

function removeFileIfExists(filePath) {
    if (fs.existsSync(filePath)) {
        fs.unlinkSync(filePath);
    }
}

function* readTxtFile(filePath) {
    let line;
    const liner = new lineByLine(filePath, {
        readChunk: 1024*1024
    });

    while (line = liner.next()) {
        yield line.toString();
    }
}

/**
 *
 * @param {Array<*>} headers
 * @param {Array<*> | Object} data
 */
async function appendCSV(filePath, headers, data) {
    const createCsvWriter = Array.isArray(data) ? csvWriter.createArrayCsvWriter : csvWriter.createObjectCsvWriter;

    if (!fs.existsSync(filePath)) {
        const csvWriter = createCsvWriter({
            path: filePath,
            header: headers,
        });
        await csvWriter.writeRecords([]);
    }

    const csvRecordWriter = createCsvWriter({
        path: filePath,
        header: headers,
        append: true,
    });

    await csvRecordWriter.writeRecords([data]).then(() => {
        global._argv.verbose >= 1 && console.log('...Done');
    });
}

function getAbsolutePath(currentPath, baseDir = '') {
    baseDir = baseDir ? baseDir : process.cwd();
    return path.isAbsolute(currentPath) ? currentPath : path.join(baseDir, currentPath);
}

function hostFromUrl(url) {
    return url.replace(/https?:\/\//, '');
}

function portFromUrl(url) {
    return parseInt(url.match(/https?:\/\/[\w\-.]+(:(\d+))?\\??/)[2]) || ((url.indexOf("https") == 0)? 443: 80);
}

function removeProtocol(url) {
    return url.replace(/(^\w+:|^)\/\//, '');
}

function round(number, decimal = 2) {
    return +(Math.round(number + `e+${decimal}`) + `e-${decimal}`);
}

function subtract(a, b, multiplier = 100) {
    return (a * multiplier - b * multiplier) / multiplier;
}

module.exports = {
    readTxtFile,
    removeFilesInFolder,
    appendCSV,
    createFolderIfNotExist,
    getAbsolutePath,
    hostFromUrl,
    removeFileIfExists,
    removeProtocol,
    round,
    subtract,
    portFromUrl,
    shell
};
