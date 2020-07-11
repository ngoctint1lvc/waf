from configparser import Error
from ftw import logchecker, testrunner
import datetime
import pytest
import re
import os
from testwriter import CSVWriter
import time

def test_crs(ruleset, test, logchecker_obj, csv_writer):
    runner = testrunner.TestRunner()
    for stage in test.stages:
        result, log_data = False, ''
        error = None
        try:
            result, log_data = runner.run_stage(stage, logchecker_obj)
        except Exception as e:
            error = e

        # write expect
        expect = ""
        if stage.output.log_contains_str:
            expect += f"- log contains: {stage.output.log_contains_str.pattern}\n"
        if stage.output.expect_error:
            expect += f"- error: {stage.output.expect_error}\n"
        if stage.output.no_log_contains_str:
            expect += f"- log not contains: {stage.output.no_log_contains_str.pattern}\n"
        if stage.output.response_contains_str:
            expect += f"- response contains: {stage.output.response_contains_str.pattern}\n"
        if stage.output.status:
            if type(stage.output.status) is list:
                expect += f"- status code: {' or '.join(map(lambda i: str(i), stage.output.status))}\n"
            else:
                expect += f"- status code: {stage.output.status}\n"

        test_data = {
            'id': f"{ruleset.meta['name']}-{csv_writer.numTest}",
            'description': test.test_title,
            'test_result': "OK" if result else "FAILED",
            'expect_behavior': expect,
            'url': stage.input.uri,
            'data': stage.input.data,
            'log_message': log_data
        }

        csv_writer.append(test_data)
        if error:
            raise error
        assert result


class FooLogChecker(logchecker.LogChecker):
    def __init__(self, config):
        super(FooLogChecker, self).__init__()
        self.log_location = config['log_location_linux']
        self.log_date_regex = config['log_date_regex']
        self.log_date_format = config['log_date_format']

    def reverse_readline(self, filename):
        with open(filename) as f:
            f.seek(0, os.SEEK_END)
            position = f.tell()
            line = ''
            while position >= 0:
                f.seek(position)
                next_char = f.read(1)
                if next_char == "\n":
                    yield line[::-1]
                    line = ''
                else:
                    line += next_char
                position -= 1
            yield line[::-1]

    def get_logs(self):
        pattern = re.compile(r'%s' % self.log_date_regex)
        our_logs = []
        
        for lline in self.reverse_readline(self.log_location):
            # Extract dates from each line
            match = re.match(pattern, lline)
            if match:
                log_date = match.group(1)
                log_date = datetime.datetime.strptime(
                    log_date, self.log_date_format)
                # NGINX doesn't give us microsecond level by detail, round down.
                if r"%f" not in self.log_date_format:
                    ftw_start = self.start.replace(microsecond=0)
                else:
                    ftw_start = self.start
                ftw_end = self.end
                if log_date <= ftw_end and log_date >= ftw_start:
                    our_logs.append(lline)
                # If our log is from before FTW started stop
                if log_date < ftw_start:
                    break
        return our_logs


@pytest.fixture(scope='session')
def logchecker_obj(config):
    return FooLogChecker(config)


@pytest.fixture(scope='session')
def csv_writer(pytestconfig):
    return CSVWriter(pytestconfig.getoption("output"))
