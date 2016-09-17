all: at at2 at3

at3: at3.o print_arrays.o ArrayHelper.o
	gcc -g at3.o print_arrays.o ArrayHelper.o -o at3

at3.o: at3.c ArrayHelper.h print_arrays.h
	gcc -g -c at3.c print_arrays.h ArrayHelper.h

at2: at2.o print_arrays.o ArrayHelper.o
	gcc -g --std=gnu99 at2.o print_arrays.o ArrayHelper.o -o at2

at2.o: at2.c print_arrays.h ArrayHelper.h
	gcc -g --std=gnu99 -c at2.c

at: at.o print_arrays.o
	gcc -g --std=gnu89 at.o print_arrays.o -o at

at.o: at.c print_arrays.h
	gcc -g --std=gnu89 -c at.c print_arrays.h

print_arrays.o: print_arrays.c print_arrays.h
	gcc -g --std=gnu89 -c print_arrays.c

ArrayHelper.o: ArrayHelper.c ArrayHelper.h
	gcc -g -c ArrayHelper.c
docs: 
	doxygen
	chmod uo+r html/*
	cp -pr html/* ~/public_html/cs2303assig2
clean:
	rm -f *.o
	rm -f at at2 at3
