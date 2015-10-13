import sqlite3
from urlparse import parse_qs
import matplotlib.pyplot as plt

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

TMP_PLOT_NAME = 'tmp_plot.png'

def make_tmp_plot(ys):
    fig, ax = plt.subplots(nrows=1, ncols=1)
    ax.plot(list(range(0, len(ys))), ys)
    fig.savefig(TMP_PLOT_NAME)
    plt.close(fig)

cached_files = {}
def get_cached_file(filename):
    if filename in cached_files:
        return cached_files[filename]
    contents = open(filename).read()
    cached_files[filename] = contents
    return contents

def application(env, start_response):
    start_response('200 OK', [('Content-Type', 'text/html')])
    ret = ''

    req_uri = env['REQUEST_URI']
    if len(req_uri) > 1 and '?' not in req_uri:
        filename = req_uri[1:]
        try:
            return open(filename).read()
        except:
            return []

    queries = parse_qs(env['QUERY_STRING'])
    if dict_contains(queries, 'insert', 'id', 'field'):
        ident = queries['id'][0]
        field = queries['field'][0]
        add_row(ident, field)
        ret = '<p>Inserted row: Id = {}, Field = {}</p>'.format(ident, field)
    elif dict_contains(queries, 'query', 'id'):
        query = query_by_id(queries['id'][0])
        ints = []
        for val in query:
            ints.append(int(val[1]))
        make_tmp_plot(ints)
        ret = "<img src='{}' alt='plot' />".format(TMP_PLOT_NAME)
    return get_cached_file('index.html').replace('##VAL##', ret, 1)

