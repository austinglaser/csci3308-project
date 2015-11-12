from urlparse import parse_qs
import db_interface as db
import plot
import json

TMP_PLOT_NAME = 'Usage_Plot.png'

def dict_contains(d, *args):
    ''' return True if all args are in d '''
    for arg in args:
        if arg not in d:
            return False
    return True

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
        try:
            if req_body['function'] == 'insert':
                usage = req_body['usage']
                ts = req_body['timestamp']
                db.add_row(ts, usage)
        except:
            pass
        finally:
            return (True, req_body)
    return (False, None)

