import sqlite3
from urlparse import parse_qs
import matplotlib.pyplot as plt
import db_interface as db
import plot
import json

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

def untemplateify(template, *replacements):
    '''
    replacements is a list of tuples where the first element is an identifier
    and the second is the value with which that identifier is replaced. In the
    template, ##ID## is replaced with the value corresponding to ID.
    '''
    for p in replacements:
        template = template.replace('##{}##'.format(p[0]), p[1], 1)
    return template

def handle_file_request(env):
    req_uri = env['REQUEST_URI']
    if len(req_uri) > 1 and '?' not in req_uri:
        filename = req_uri[1:]
        try:
            ret = open(filename).read()
        except:
            ret = ''
        return (True, ret)
    return (False, None)

def handle_get_request(env):
    queries = parse_qs(env['QUERY_STRING'])
    if dict_contains(queries, 'insert', 'timestamp', 'usage'):
        ts = queries['timestamp'][0]
        usage = queries['usage'][0]
        db.add_row(ts, usage)
        ret = '<p>Inserted row: timestamp = {}, usage = {}</p>'.format(ts, usage)
        return (True, ret)
    elif dict_contains(queries, 'query', 'timestamp'):
        query = db.query_by_timestamp(int(queries['timestamp'][0]))
        timestamps = []
        usage = []
        for val in query:
            timestamps.append(int(val[0]))
            usage.append(int(val[1]))
        plot.make_plot(timestamps, usage)
        ret = "<img src='{}' alt='plot' />".format(TMP_PLOT_NAME)
        return (True, ret)
    return (False, None)

def handle_post_request(env):
    try:
        req_body_length = int(env.get('CONTENT_LENGTH', 0))
    except (ValueError):
        req_body_length = 0
    if req_body_length:
        req_body = json.loads(env['wsgi.input'].read(req_body_length))
        return (True, req_body)
    return (False, None)


def application(env, start_response):
    start_response('200 OK', [('Content-Type', 'text/html')])

    valid, ret = handle_file_request(env)
    if valid:
        return ret

    f = get_cached_file('index.html')

    valid, val = handle_get_request(env)
    if valid:
        return untemplateify(f, ('VAL', val))

    valid, val = handle_post_request(env)
    if valid:
        return untemplateify(f, ('VAL', str(val)))

    return untemplateify(f, ('VAL', ''))

