all: objstacktest objqueuetest treetest treetestrand

objstacktest: objstacktest.o objstack.o foo.o
	g++ -g objstacktest.o objstack.o foo.o -o objstacktest

objqueuetest: objqueuetest.o objqueue.o
	g++ -g objqueuetest.o objqueue.o -o objqueuetest

treetest: TreeTest.o tree.o Tnode.o 
	g++ -g TreeTest.o tree.o Tnode.o -o treetest

treetestrand: TreeTestRand.o tree.o Tnode.o mystring.o
	g++ -g TreeTestRand.o tree.o Tnode.o mystring.o -o treetestrand

objstack.o: objstack.cpp objstack.h
	g++ -g -c objstack.cpp

objqueue.o: objqueue.cpp objqueue.h 
	g++ -g -c objqueue.cpp

Tnode.o: Tnode.cpp Tnode.h
	g++ -g -c Tnode.cpp

tree: tree.cpp tree.h
	g++ -g -c tree.cpp

objstacktest.o: objstacktest.cpp objstack.h foo.h
	g++ -g -c objstacktest.cpp

objqueuetest.o: objqueuetest.cpp objqueue.h
	g++ -g -c objqueuetest.cpp 

TreeTest.o: TreeTest.cpp tree.h Tnode.h 
	g++ -g -c TreeTest.cpp

TreeTestRand.o: TreeTestRand.cpp mystring.h tree.h Tnode.h
	g++ -g -c TreeTestRand.cpp 

mystring.o: mystring.h mystring.c
	g++ -g -c mystring.c

foo.o: foo.cpp foo.h
	g++ -g -c foo.cpp

docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig6

clean:
	rm -f *.o
	rm -f objstacktest objqueuetest
