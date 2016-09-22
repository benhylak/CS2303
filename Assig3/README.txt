Benjamin Hylak 

secondMain
    -Program tests functions on "Car" structs. 
    -Creates arrays, tests copying functions. 
        -shallow copy
            -just copies pointers from one array to the other
        -deep copy
            -copies VALUES of pointers into new memory, makes array of pointers
                to their respective spots in memory
    -prints results

mystring.c/.h/.o
    -Contains functions for manipulating string
    -reimplimented std string function
        -strcat(), strncat(), strncpy(), strndup()
    -generates random characters and strings (random generator must be seeded)

ctest
    -Tests mystring functions on actual data and prints results
