/**@file print_arrays.c
 * @author Mike Ciaraldi and Ben Hylak
 *
 * Functions for printing arrays.
 */

#include <stdio.h>
#include "print_arrays.h"

/** Print an array of ints, one per line.
    @param an Array to print
    @param num_entries Number of entries in the array
*/

void print_int_array(int a[], int num_entries) {
  int i; // Loop counter

  printf("\n");

  for (i = 0; i < num_entries; i++) {
    printf("%d\n", a[i]);
  }
}

/** Print an array of doubles, one per line.
    @param an Array to print
    @param num_entries Number of entries in the array
*/
void print_double_array(double a[], int num_entries) {
    int i; // Loop Counter

    printf("\n"); //new line 

    for(i=0; i< num_entries; i++) //for each entry
    {
        printf("%f\n", a[i]); //print double
    }
}

