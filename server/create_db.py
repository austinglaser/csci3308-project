import sqlite3

con = sqlite3.connect('test.db')
cur = con.cursor()
cur.execute("CREATE TABLE MyTable(Id INT, Field TEXT);")
con.close()
