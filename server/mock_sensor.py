## @package mock_sensor
# Mock sensor for testing the server
import urllib2

URL = "http://127.0.0.1:9090"

##
# @param url The url to which the message is sent
# @param data The body of the message to be sent to the url
def post(data, url=URL):
    req = urllib2.Request(url, data, {'Content-Type': 'application/json'})
    return urllib2.urlopen(req).read()

