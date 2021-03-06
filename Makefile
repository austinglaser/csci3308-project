.PHONY: all clean dep test doc

all:
	$(MAKE) -C uwsgi-2.0.11.2

clean:
	rm -rf doc/html/
	rm -rf doc/latex/
	$(MAKE) -C uwsgi-2.0.11.2 clean

# follow instructions in sensor/README.md, probably.
dep:
	sudo apt-get install python-matplotlib
	sudo pip install django==1.8.6
	cd server && python create_db.py && python populate_test_db.py

test: all
	./run_tests

doc:
	doxygen Doxyfile
