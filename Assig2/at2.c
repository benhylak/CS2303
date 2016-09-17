/*! Part 2+3 of Assignment 2 for CS2303.
 * @file
 * @author Ben Hylak
 *
 * Takes a list of integers from the command line, prints the inputted numbers, sorts the numbers (quicksort) and then prints again.
 *
 */

#include "ArrayHelper.h"
#include "print_arrays.h"
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE (10)

/** Function to fill array with integer data from command line data
 *  @param argc Argument count from command line
 *  @param argv Arguments from command line
 *  @param arr Array to fill
 *  @param maxSize Max size of the array, so the function knows when to stop filling
 *  @return Number elements were inserted into the array
 */
int fillArray(int argc, const char* argv[], int arr[], int maxSize)
{
    int arrSize = 0;

    if(argc-1 > maxSize)
    {
        printf("This program supports a maximum of %d grades. Because you have entered %d grades, the last %d grades will not be processed.\n", maxSize, argc-1,
                argc-1-maxSize);
    }

    for(int i=0; (i < argc-1 && i < maxSize); i++) //argc-1 because arg count includes program name e.g. ./num
    {
        arr[i] = atoi(argv[i+1]); //first argument is program name, not a grade, so skip it
        arrSize++; //track increased size of array
    }

    return arrSize;
}

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */
int main(int argc, const char* argv[]) {
    int gradesSize=0; //track size of array
    int grades[ARRAY_SIZE]; // Define and allocate the array 

    if(argc < 2) //Check that there was an entry
    {
        printf("Must enter a number on the command line!\n");
        return 1; //Indicate failure;
    }

    gradesSize = fillArray(argc, argv, grades, ARRAY_SIZE); //fill array with data inputted on command line
    
    printf("\nInputted Array:\n");

    print_int_array(grades, gradesSize); //prints array

    quickSort(grades, gradesSize); //sorts the array of inputted numbers

    printf("\nSorted Input:\n");

    print_int_array(grades, gradesSize); //prints again, sorted
}
