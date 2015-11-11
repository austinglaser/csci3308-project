import unittest
import mock_sensor
import db_interface as db
import subprocess
from time import sleep

class TestMockSensor(unittest.TestCase):
    ''' Test the sensor interface to the server. Requires that the server be
    running. '''
    def setUp(self):
        cmdline = ['./uwsgi', '--http', ':9090', '--wsgi-file', 'main.py']
        self.proc = subprocess.Popen(cmdline, stderr=subprocess.PIPE, stdout=subprocess.PIPE)
        sleep(2)
    def tearDown(self):
        self.proc.kill()
    def test_post_insert(self):
        q1 = db.query_by_timestamp(0)
        mock_sensor.post('{"function": "insert", "usage": 1, "timestamp": 0}')
        q2 = db.query_by_timestamp(0)
        q1.append((0, 1))
        self.assertEqual(q1, q2)
    def test_post_insert_invalid_usage(self):
        q1 = db.query_by_timestamp(0)
        mock_sensor.post('{"function": "insert", "usage": "asdf", "timestamp": 0}')
        q2 = db.query_by_timestamp(0)
        self.assertEqual(q1, q2)
    def test_post_insert_invalid_timestamp(self):
        q1 = db.query_by_timestamp(0)
        mock_sensor.post('{"function": "insert", "usage": 1, "timestamp": "asdf"}')
        q2 = db.query_by_timestamp(0)
        self.assertEqual(q1, q2)

if __name__ == '__main__':
    unittest.main()

