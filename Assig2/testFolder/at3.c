/*! Part 4 Assignment 2 for CS2303.
 * @author Ben Hylak
 *
 * Generates an array of random integers, prints them, sorts them, and then prints again.
 */

#include "ArrayHelper.h"
#include "print_arrays.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE (20)
#define MAX_RANDOM_INT 200

/*! Gets random integer
 * Function gets a pseudo random integer from 0 to specific maximum, inclusive. 
 * @param max Maximum random integer can be
 * @returns Psuedo random int
 */
int getRandomInt(int max)
{
   return rand() % (max+1); 
}

/*! Fills arrays with random ints
 *
 *  @param arr Array to fill
 *  @param maxSize Max size of the array, so the function knows when to stop filling
 */
void fillArrayRandom(int arr[], int maxSize)
{
    for(int i=0; i < maxSize; i++) //argc-1 because arg count includes program name e.g. ./num
    {
        arr[i] = getRandomInt(MAX_RANDOM_INT); //gets random int less than MAX_RANDOM_INT 
    }
}

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */
int main()
{
    srand((int)time(NULL)); //seeds array from time

    int arrSize = MAX_ARRAY_SIZE; //track size of array
    int arr[MAX_ARRAY_SIZE]; // Define and allocate the array 

    fillArrayRandom(arr, arrSize); //fill array with random integers

    printf("\nRandom Array Before Sort: ");
    print_int_array(arr, arrSize); //print array (unsorted)

    quickSort(arr, arrSize); //sort array
    
    printf("\nRandom Array After Sort: ");
    print_int_array(arr, arrSize); //print array (now in ascending order)
}
