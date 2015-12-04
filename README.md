Project for CSCI 3308
=====================

Outletify
---------
Outletify is the simplest way to manage and monitor all the household
technology you depend on. Lower your bills, reduce your environmental
footprint, and make your life easier by leaving menial tasks to the machines.

Repo layout
-----------
doc/
    Contains a project description, and is also where auto-doc output goes
ENV/
    Contains the Django/server environment
part1\_src/
    Contains source for the Part 1 pdf
Part3\_Excel\_UAT/
    Contains User Acceptance Test template for Part 3
part3\_src/
    Contains source for the Part 3 pdf
sensor/
    Contains source that runs on microcontrollers ("sensors", which monitor
    power usage and run automation tasks)
server/
    Contains source for a lightweight uwsgi server that handles simple
    logging requests
uwsgi-2.0.11.2/
    Contains source for uwsgi
Doxyfile
    Configuration file for Doxygen
Makefile
    Provides commands:
        make
        make clean
        make dep
        make test
        make doc
    which work on the entire project
Outletify\_Part\_1.pdf
    Part 1 submission
Outletify\_Part\_3.pdf
    Part 3 submission
README.md
    This file
run\_tests
    Runs all tests. Invoked by "make test"
run\_server
    Run the Django server
