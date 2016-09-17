README:

Assignment 2 for CS2303 
Author: Benjamin Hylak
License: N/A

Compiling:
    Run "make clean" and then "make"

Executable Programs Included:
    at
        Description
            -Prints two arrays: The first with consecutive integers and the other with consecutive doubles.
        
        Dependencies:
            -print_arrays

        Example:
            ./at

    at2
        Takes numbers from command line, loads into array, prints array, sorts array and then prints again. Number of inputs
        must be less than ARRAY_SIZE (10). Extraneous arguments are truncated
        
        Dependencies:
            -print_arrays
            -ArrayHelper

        Example:
            ./at2 1 4 2 4 6 4 9 1 6 
    at3 
        Loads an array with MAX_ARRAY_SIZE (20) random integers between 0 and MAX_RANDOM_INT (200). Uses rand() function. After printing 
        the random array, it calls a quick sort function from ArrayHelper.c and prints the result.
        
        Dependencies:
            -print_arrays
            -ArrayHelper

        Example:
            ./at3

Libraries:
    ArrayHelper
        Files
            -ArrayHelper.c
            -ArrayHelper.h
        Description
            Contains functions for quicksorting an array of ints in place

    print_arrays
        Files
            -print_arrays.c
            -print_arrays.h
        Description
            Contains functions for printing
                1. Array of Ints
                2. Array of doubles 

