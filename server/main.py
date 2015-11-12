import request_handler as handler

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

def application(env, start_response):
    start_response('200 OK', [('Content-Type', 'text/html')])

    valid, ret = handler.handle_file_request(env)
    if valid:
        return ret

    f = get_cached_file('index.html')

    valid, val = handler.handle_get_request(env)
    if valid:
        return untemplateify(f, ('VAL', val))

    valid, val = handler.handle_post_request(env)
    if valid:
        return untemplateify(f, ('VAL', str(val)))

    return untemplateify(f, ('VAL', ''))

