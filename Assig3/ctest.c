#include <stdio.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"

/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 */

const int MAX_CHARS = 20; // Maximum number of characters in array

int main()
{
  char a1[MAX_CHARS + 1]; // Character array--initially empty
  char a2[] = "Hello"; // Character array--unsized but initialized
  char a3[MAX_CHARS + 1]; // Character array--we will underfill it
  char* p1 = "Hello"; // Pointer to constant string
  char* p2;           // Will be a pointer to dynamically-allocated string
  int copy_limit;     // Maximum characters to copy.

  myStrCpy(a3, "Hello, also"); // Initialize underfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);

  strcpy(a1, "Hi"); // Initialize character array

  printf("Contents of a1 = %s\n", a1);
  printf("Contents of a2 = %s\n", a2);
  printf("Contents of a3 = %s\n", a3);

  printf("Length of a1 = %d\n", myStrLen(a1));

  // Concatenate two character arrays, then print.
  myStrCat(a1, a2);
  printf("After concatenating a2 to a1, contents of a1 = %s\n", a1);

  // Concatenate two character arrays with limit, then print.
  strncat(a1, a2, 8);
  printf("After concatenating a2 to a1, max length 8, contents of a1 = %s\n",
         a1);

  // Copy with limit.
  strncpy(a1, a2, 3);
  printf("After copying a2 to a1, max length 3, contents of a1 = %s\n", a1);
  printf("Note that copied string was not terminated.\n");

  // Reset a1
  strcpy(a1, "Hi"); // Initialize character array
  printf("Resetting. a1 = %s\n", a1);

  // Concatenate two character arrays with limit, then print.
  strncat(a1, a2, 2);
  printf("After concatenating a2 to a1, max length 2, contents of a1 = %s\n",
         a1);
  printf("Note that copied string was terminated.\n");


  // Duplicate a string, using my function, then print
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("After dup, pointer p2 = %p, contents = %s\n", p2, p2);

  return 0;
}
