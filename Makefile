.PHONY: all clean dep test doc

all:
	$(MAKE) -C uwsgi-2.0.11.2

clean:
	rm -rf doc/html/
	rm -rf doc/latex/
	$(MAKE) -C uwsgi-2.0.11.2 clean

# follow instructions in sensor/README.md, probably.
dep:

test:
	./run_tests

doc:
	doxygen Doxyfile
