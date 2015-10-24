import sqlite3 as lite

DB_NAME = 'outletify.db'

def connect():
    con = lite.connect(DB_NAME)
    cur = con.cursor()
    return (con, cur)

def add_row(timestamp, usage, dbhandle=None):
    if dbhandle is None:
        close_con = True
        con, cur = connect()
    else:
        close_con = False
        con, cur = dbhandle

    cur.execute("INSERT INTO usage_stats VALUES (?, ?);", (int(timestamp), int(usage)))
    con.commit()

    if close_con:
        con.close()

def query_by_timestamp(timestamp, dbhandle=None):
    if dbhandle is None:
        close_con = True
        con, cur = connect()
    else:
        close_con = False
        con, cur = dbhandle

    cur.execute("SELECT * FROM usage_stats WHERE timestamp = ?;", (int(timestamp),))
    ret = cur.fetchall()

    if close_con:
        con.close()
    return ret

