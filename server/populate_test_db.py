import sqlite3 as lite
import random

values = []
for i in range(0, 100):
    for _ in range(0, random.randint(5, 20)):
        values.append((i, random.randint(0, 2000)))

con = lite.connect('test.db')
cur = con.cursor()
cur.executemany("INSERT INTO MyTable VALUES (?, ?)", values)
con.commit()
con.close()
