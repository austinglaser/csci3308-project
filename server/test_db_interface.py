import unittest
import db_interface as db
import random
import string
import math
import os

def rand_str(n):
    return ''.join(random.SystemRandom().choice(string.ascii_uppercase + string.digits) for _ in range(n))

def rand_db():
    return rand_str(8) + '.db'

def usage_from_timestamp(timestamp):
    return int(math.sin(timestamp) * 100)

def run_with_outletify_db(f):
    dbname = rand_db()
    handle = db.connect(dbname)
    try:
        db.create_outletify_tables(handle)
        f(handle)
    finally:
        db.close_handle(handle)
        os.remove(dbname)

class TestDBMethods(unittest.TestCase):
    def test_create_db(self):
        def runtest(dbhandle):
            rows = db.dump_contents(dbhandle)
            self.assertEqual(rows[0], 'length_1: 1')
            self.assertEqual(rows[1], (u'table', u'usage_stats', u'usage_stats', 2, u'CREATE TABLE `usage_stats`(`timestamp` INT, `usage` INT)'))
            self.assertEqual(rows[2], 'length_2: 0')
        run_with_outletify_db(runtest)

    def test_add_query(self):
        def runtest(dbhandle):
            for i in range(100):
                db.add_row(i, usage_from_timestamp(i), dbhandle)
            q1 = db.query_by_timestamp(10, dbhandle)
            self.assertEqual(q1, [(10, usage_from_timestamp(10))])

            q2 = db.query_by_timestamp((5, 15), dbhandle)
            expected_usages = []
            for i in range(5, 16):
                expected_usages.append((i, usage_from_timestamp(i)))
            for pair in zip(q2, expected_usages):
                self.assertEqual(pair[0], pair[1])
        run_with_outletify_db(runtest)

if __name__ == '__main__':
    unittest.main()

