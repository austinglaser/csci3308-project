import sqlite3

con = sqlite3.connect('outletify.db')
cur = con.cursor()
cur.execute("CREATE TABLE `usage_stats`(`timestamp` INT, `usage` INT);")
con.close()
