import sqlite3 as lite

DB_NAME = 'outletify.db'

def connect(name=DB_NAME):
    con = lite.connect(name)
    cur = con.cursor()
    return (con, cur)

def close_handle(dbhandle):
    dbhandle[0].close()

def create_outletify_tables(dbhandle=None):
    if dbhandle is None:
        close_con = True
        con, cur = connect()
    else:
        close_con = False
        con, cur = dbhandle

    cur.execute("CREATE TABLE `usage_stats`(`timestamp` INT, `usage` INT);")

    if close_con:
        con.close()

def dump_contents(dbhandle=None):
    if dbhandle is None:
        close_con = True
        con, cur = connect()
    else:
        close_con = False
        con, cur = dbhandle

    def rows_to_array(rows):
        ret = []
        for r in rows.fetchall():
            ret.append(r)
        return ret

    ret = []
    rows = rows_to_array(cur.execute("SELECT * FROM sqlite_master"))
    ret.append('length_1: {}'.format(len(rows)))
    for x in rows:
        ret.append(x)
    rows = rows_to_array(cur.execute("SELECT * FROM usage_stats;"))
    ret.append('length_2: {}'.format(len(rows)))
    for x in rows:
        ret.append(x)

    if close_con:
        con.close()
    return ret

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
    '''
    Returns usage entries for the given timestamp(s)

    timestamp is either an int or (int, int) representing an inclusive range of
    timestamps.
    '''
    if dbhandle is None:
        close_con = True
        con, cur = connect()
    else:
        close_con = False
        con, cur = dbhandle

    if type(timestamp) == int:
        cur.execute("SELECT * FROM usage_stats WHERE timestamp = ?;", (int(timestamp),))
        ret = cur.fetchall()
    elif type(timestamp) == tuple:
        cur.execute("SELECT * FROM usage_stats WHERE timestamp >= ? AND timestamp <= ?;", (int(timestamp[0]), int(timestamp[1])))
        ret = cur.fetchall()

    if close_con:
        con.close()
    return ret

