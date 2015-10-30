#import sqlite3 as lite
import db_interface as db
import random

dbhandle = db.connect()
try:
    for i in range(0, 100):
        for _ in range(0, random.randint(5, 20)):
            db.add_row(i, random.randint(0, 2000), dbhandle)
finally:
    db.close_handle(dbhandle)
