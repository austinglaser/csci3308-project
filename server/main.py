## @file
# Contains the entry point for the uwsgi server

import request_handler as handler

cached_files = {}
##
# @param filename Name of the file to fetch
# @return The contents of the cached file or, if the file isn't cached, the
# contents of the file on disk
def get_cached_file(filename):
    if filename in cached_files:
        return cached_files[filename]
    contents = open(filename).read()
    cached_files[filename] = contents
    return contents

##
# @param replacements An iterable object containing tuples where the first
# element is an identifier and the second is the value with which that
# identifier is replaced.
# @param template A string representing a template. Substrings like ##...## are
# replaced with the corresponding value in replacements
# @return The template with all replacements made
def untemplateify(template, *replacements):
    '''
    replacements is a list of tuples where the first element is an identifier
    and the second is the value with which that identifier is replaced. In the
    template, ##ID## is replaced with the value corresponding to ID.
    '''
    for p in replacements:
        template = template.replace('##{}##'.format(p[0]), p[1], 1)
    return template

##
# The entry point for the uwsgi server
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

