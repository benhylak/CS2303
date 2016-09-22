all:ctest secondMain

# Executable depends on the two object files
ctest: ctest.o mystring.o 
	gcc -g ctest.o mystring.o -o ctest

# Object file depends on source and header files
ctest.o: ctest.c mystring.h 
	gcc -g -c ctest.c

# Object file depends on source and header files
mystring.o: mystring.c mystring.h 
	gcc -g -c mystring.c

clean: 
	rm -f *.o ctest secondMain

secondMain: secondMain.o StructHelper.o mystring.o
	gcc -g secondMain.o StructHelper.o mystring.o -o secondMain

secondMain.o: secondMain.c StructHelper.h mystring.h
	gcc -g -c secondMain.c

StructHelper.o: StructHelper.c StructHelper.h
	gcc -g -c StructHelper.c

# Typing "make docs" will generate Doxygen files, set proper permissions,
# and copy into ~/public_html/cs2301assig3 .
docs:
	doxygen
	chmod a+r html/*
	cp -p html/* ~/public_html/cs2303assig3


#add all files and commit to git
git:
	git add -A  
	git commit -m "$m" #usage: make git m="comment"
	
