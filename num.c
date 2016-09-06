/** @file num.c
 *  @brief Program to calculate min, max, and avg of grades (int) inputted from command line.
 *
 * Program to calculate min, max and avg of grades (ints) inputted from command line. After MAX_GRADES (20) numbers, subsequent inputs  will be ignored
 *
 * Usage
 *	./num grade0 grade2 grade3 ... grade{MAX_GRADES} 
 * Example:
 *	./num 99 100 50 80 50 
 *
 *  @returns 0 if success, 1 if no numbers inputted
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayHelper.h"

#define MAX_GRADES (20)


int main(int argc, const char* argv[])
{
    int gradesSize=0; //track size of array

    int grades[MAX_GRADES]; // Define and allocate the array 

	if(argc < 2) //Check that there was an entry
	{
		printf("Must enter a number on the command line!\n");
		return 1; //Indicate failure;
	}

    for(int i=0; (i < argc-1 && i <= MAX_GRADES); i++) //argc-1 because arg count includes program name e.g. ./num
    {
        grades[i] = atoi(argv[i+1]); //first argument is program name, not a grade, so skip it
        gradesSize++; //track increased size of array
    }

    printAvgMaxMin(grades, gradesSize); //print avg, min, max of array

	return 0; //success
}
