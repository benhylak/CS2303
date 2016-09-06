/**

@mainpage Assignment1

@author Benjamin Hylak 

This project has two programs, leap and num.

Leap:
    Desription:
         Leap determines whether or not a given year is a leap year. It only supports years after 1752. 

    Usage: 
        ./leap year
    
    Example:
        ./leap 2000 -> "2000 is a leap year"
        ./leap 2003 -> "2003 is not a leap year"
        ./leap 1680 -> "Years before 1752 are not supported"

    Required Files:
        leap.c

Num:
    Description:
        Num takes multiple inputs and prints the min, max and average. If more than MAX_GRADES (20) inputs are supplied
        those inputs will be ignored. 
    
    Usage:
        ./num number1 number2 number3 number 4
    
    Example:
        ./num 0 100 50 -> "Min:0 Max:0 Avg: 50"

    Required Files:
        num num.c ArrayHelper.c ArrayHelper.h

ArrayHelper (for Num program):
    Contains function that takes an array and size of the array and prints out min/max/avg of array

Compiling:
    To compile, simply run "make" in this directory. Please note that in addition to the above required files, the makefile requires lab1.c
*/
