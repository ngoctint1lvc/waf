import csv

class CSVWriter():

    def __init__(self, fileName):
        self.numTest = 0
        self.numTestPass = 0
        self.currentTest = None
        
        self._fd = open(fileName, 'w')
        self.writer = csv.DictWriter(self._fd, fieldnames = [
            'id',
            'description',
            'test_result',
            'expect_behavior',
            'url',
            'data',
            'log_message'
        ])
        self.writer.writeheader()
    
    def __del__(self):
        self._fd.close()

    def append(self, data):
        self.writer.writerow(data)
        self._fd.flush()
        self.numTest += 1
        if data['test_result'] == 'OK':
            self.numTestPass += 1