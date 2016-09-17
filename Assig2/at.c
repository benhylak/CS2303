/** @file at.c
 * @author Ben Hylak
 *
 * Program to demonstrate fixed-size arrays in C.
 */

#include "print_arrays.h"

#define SAMPLE_INT_ARRAY_SIZE (10)

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {
  int i; // Loop counter
  int a[SAMPLE_INT_ARRAY_SIZE]; // Sample array for demonstration

  // Fill the array with consecutive integers
  for (i = 0; i < SAMPLE_INT_ARRAY_SIZE; i++) a[i] = i;

  // Now print it out
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);
    
  double b[SAMPLE_INT_ARRAY_SIZE];

  // Fill the array with consecutive doubles
  for (i = 0; i < SAMPLE_INT_ARRAY_SIZE; i++) b[i] = (double)i;
 
  print_double_array(b, SAMPLE_INT_ARRAY_SIZE); //print array of doubles

  return 0; // Success!
}
