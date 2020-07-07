const lineByLine = require('n-readlines');
const fs = require('fs');
const path = require('path');
const csvWriter = require('csv-writer');

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
    const liner = new lineByLine(filePath);
    while (line = liner.next()) {
        yield line.toString();
    }
}

function* readHttpRequests(filePath, delim, hostName) {
    let httpFile = readTxtFile(filePath);

    let currentRequest = '';
    let ignoreLine = false;
    for (let line of httpFile) {
        if (line.search(/^(GET|PUT|POST|DELETE|OPTIONS|TRACE|HEAD|CONNECT|PATCH) /) === 0) {
            if (currentRequest) {
                yield currentRequest;
            }
            ignoreLine = false;
            currentRequest = '';
        }

        if (delim && line.search(delim) === 0) {
            ignoreLine = true;
        }

        if (!ignoreLine)
            currentRequest += line.replace(/^Host: .*$/m, `Host: ${hostName}`) + "\n";
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
    readHttpRequests,
    appendCSV,
    createFolderIfNotExist,
    getAbsolutePath,
    hostFromUrl,
    removeFileIfExists,
    removeProtocol,
    round,
    subtract
};
