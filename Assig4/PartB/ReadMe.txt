Author:Benjamin Hylak

This project has a number of files for Assignment 4. (Both Lab and Homework)

In the homework, there is a gnum file that tests a number of different conversions and polymorphism concepts using the GeneralNumber class. 

gnum program is ran with: ./gnum 

The GeneralNumber class, defined in GeneralNumber.cpp, is accompanied by two other classes in the same file. (Which both extend GeneralNumber)

-GeneralRational
    -Used for representing a fraction with a top and bottom
    -Has canonicalize function for putting fraction in canoncial form

-GeneralLong
    -Stores the value of a long

Both functions have a "sumWith" function that takes in a GeneralNumber as a parameter and returns a GeneralNumber. In order to be useful, the returned result should be casted to the same type as the calling class. (If you call sumWith on a GeneralRational for example, you should cast the return result to a GeneralRational)

Also included are the dtest.c files and dtest program.
