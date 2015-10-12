import sqlite3
from urlparse import parse_qs

def connect():
    con = sqlite3.connect('test.db')
    cur = con.cursor()
    return (con, cur)

def add_row(ident, field):
    con, cur = connect()
    cur.execute("INSERT INTO MyTable VALUES (?, ?);", (int(ident), str(field)))
    con.commit()
    con.close()

def query_by_id(ident):
    con, cur = connect()
    cur.execute("SELECT * FROM MyTable WHERE Id = ?;", (int(ident),))
    ret = cur.fetchall()
    con.close()
    return ret

def dict_contains(d, *args):
    for arg in args:
        if arg not in d:
            return False
    return True

def application(env, start_response):
    start_response('200 OK', [('Content-Type', 'text/html')])
    ret = ''
    queries = parse_qs(env['QUERY_STRING'])
    if dict_contains(queries, 'insert', 'id', 'field'):
        ident = queries['id'][0]
        field = queries['field'][0]
        add_row(ident, field)
        ret = 'Inserted row: Id = {}, Field = {}'.format(ident, field)
    elif dict_contains(queries, 'query', 'id'):
        ret = str(query_by_id(queries['id'][0]))
    return ["Hello World<br><p>{}</p>".format(ret)]

