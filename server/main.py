import sqlite3
from urlparse import parse_qs
import matplotlib.pyplot as plt
import db_interface as db
import plot

def dict_contains(d, *args):
    for arg in args:
        if arg not in d:
            return False
    return True

TMP_PLOT_NAME = 'Usage_Plot.png'

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
    if dict_contains(queries, 'insert', 'timestamp', 'usage'):
        ts = queries['timestamp'][0]
        usage = queries['usage'][0]
        db.add_row(ts, usage)
        ret = '<p>Inserted row: timestamp = {}, usage = {}</p>'.format(ts, usage)
    elif dict_contains(queries, 'query', 'timestamp'):
        query = db.query_by_timestamp(queries['timestamp'][0])
        timestamps = []
        usage = []
        for val in query:
            timestamps.append(int(val[0]))
            usage.append(int(val[1]))
        plot.make_plot(timestamps, usage)
        ret = "<img src='{}' alt='plot' />".format(TMP_PLOT_NAME)
    return get_cached_file('index.html').replace('##VAL##', ret, 1)

