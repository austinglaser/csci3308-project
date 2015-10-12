# About
This is Alan's proposal for a simple server stack.

# uWSGI
uWSGI can be used as both a web server and a python interface. Assuming our
server will only have to deal with very light loads, this should be sufficient.
If for whatever reason we decide we need a more standard web server, we could
use something like nginx, but uWSGI would still be necessary as the python
interface.

## Installation
There are packages for standard Linux distributions, but it's easier if we have
a known, consistent starting point by building from source:

```
wget http://projects.unbit.it/downloads/uwsgi-latest.tar.gz
tar xvzf uwsgi-latest.tar.gz
cd <dir>
make
```

This will produce a uwsgi binary in the build directory---this is the binary
that will be referenced later.

# Python
Currently, the scripts assume Python 2 is used, though supporting 3 as well
is trivial. We should decide on a version soon. main.py contains the function
application, which is the entry point for the server. This is specified in the
uwsgi invocation given below.

# The Database
We all are at least somewhat familiar with SQL now. I'd suggest using sqlite3,
because the Python standard distribution provides an sqlite3 module, making
setup very simple.

To create the test database:
```
python create_db.py
```

# Running the Server
```
uwsgi --http :9090 --wsgi-file main.py --stats 127.0.0.1:9191
```
The web server is listening on port 9090. In a browser, navigate to
127.0.0.1:9090. If all is well, you should see "Hello World". Information about
the running server can be found at 127.0.0.1:9191.

The server provides a very simple API that allows for creating and querying
rows in test.db (in a very limited manner).

To create a new row, navigate to
127.0.0.1:9090/?insert=1&id=*id*&field=*field*, where *id* and *field* are an
int and a string, respectively. For example, to insert a row with Id 2 and
Field "fieldtwo", navigate to 127.0.0.1:9090/?insert=1&id=2&field=fieldtwo. If
it works, the bottom of the page should say "Inserted row: Id = 2, Field =
fieldtwo".

To query a row by Id, navigate to 127.0.0.1:9090/?query=1&id=*id*, where *id*
is an int. If it works, the bottom of the page should display the row added by
the insert command above.

