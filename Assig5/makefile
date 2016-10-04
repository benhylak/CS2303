all: gntest

gntest: gntest.o GeneralNumber.o gnparse.o
	g++ -g gntest.o GeneralNumber.o gnparse.o -o gntest

gntest.o: gntest.cpp GeneralNumber.h
	g++ -g -c gntest.cpp

GeneralNumber.o: GeneralNumber.cpp GeneralNumber.h
	g++ -g -c GeneralNumber.cpp

gnparse.o: gnparse.cpp
	g++ -g -c gnparse.cpp

clean:
	rm -f *.o gntest

docs:
	doxygen
	chmod a+r,a-x html/*
	cp -p html/* ~/public_html/cs2303assig5

