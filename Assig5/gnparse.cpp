#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GeneralNumber.h"

// Static methods:

/** Parses a string representing a GeneralNumber
 * @param s The string to parse
 * @return Pointer to a newly-allocated object of the correct subclass,
 *         or null pointer if unable to parse.
 */
GeneralNumber* GeneralNumber::parse(const char* s) {

  GeneralNumber* newobj = NULL;
  long n1, n2; // Numbers parsed from the command line
  int nconv; // Number of successful conversions
  
  // Try to match the input format, then create the right type object.

  // First look for GeneralRational format
  nconv = sscanf(s, " [ %ld / %ld ]", &n1, &n2); 
  if (nconv == 2) { // Recognized!
    newobj = new GeneralRational(n1, n2);
    return newobj;
  }

  // Next look for GeneralLong format
  nconv = sscanf(s, "%ld", &n1); 
  if (nconv == 1) { // Recognized!
    newobj = new GeneralLong(n1);
    return newobj;
  }
  
  return NULL; // Nothing recognized
}
