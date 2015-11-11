import urllib2

URL = "http://127.0.0.1:9090"

def post(data, url=URL):
    req = urllib2.Request(url, data, {'Content-Type': 'application/json'})
    return urllib2.urlopen(req).read()

