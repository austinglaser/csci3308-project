With virtualenv installed, navigate to /bin
$ source activate

To run the webserver, navigate to /bin/site/mysite
$ python manage.py runserver

To run tests, navigate to /bin/site/mysite
$ python manage.py test

When the server is running, you can access admin function at localhost:8000/admin
The default login is admin/admin

The index.html file has been integrated as a template and can be viewed at localhost:8000/figure

If changes are made, you can view them with
$ python manage.py migrate

To actually commit the changes use
$ python manage.py makemigrations

If the admin page requires login, it is set as
admin/admin
