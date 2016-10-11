all: gntest gnCalc

gnCalc: gnCalc.o GeneralNumber.o gnparse.o
	g++ -g gnCalc.o GeneralNumber.o gnparse.o -o gnCalc

gntest: gntest.o GeneralNumber.o gnparse.o
	g++ -g gntest.o GeneralNumber.o gnparse.o -o gntest

gnCalc.o: gnCalc.cpp GeneralNumber.h
	g++ -g -std=c++11 -c gnCalc.cpp

gntest.o: gntest.cpp GeneralNumber.h
	g++ -g -c gntest.cpp

GeneralNumber.o: GeneralNumber.cpp GeneralNumber.h
	g++ -g -c GeneralNumber.cpp

gnparse.o: gnparse.cpp
	g++ -g -std=c++11 -c gnparse.cpp

clean:
	rm -f *.o gntest

docs:
	doxygen
	chmod a+r,a-x html/*
	cp -p html/* ~/public_html/cs2303assig5

