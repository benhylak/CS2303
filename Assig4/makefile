all: dtest

dtest: dtest.o
	gcc -g dtest.o -o dtest

dtest.o: dtest.c
	gcc -g -c dtest.c

clean:
	rm -f *.o dtest

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig4
