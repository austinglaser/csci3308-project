Sensor Interface
================

Currently a sensor can log usage data by sending a post request to the root of
the server where the body of the message is in json format. A message to log
a single data point has the form:

    {
        "function": "insert",
        "timestamp": 0,
        "usage": 1
    }

To log a point using curl:

    curl -X POST -d '{ "function": "insert", "timestamp": 0, "usage": 1 }' 127.0.0.1:9090

