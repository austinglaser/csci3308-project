import sqlite3 as lite

con = lite.connect('outletify.db')
cur = con.cursor()
rows = cur.execute("SELECT * FROM sqlite_master;")
for x in rows.fetchall():
    print(x)

print('')

rows = cur.execute("SELECT * FROM usage_stats;")
for x in rows.fetchall():
    print(x)
con.close()
