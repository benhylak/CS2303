#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GeneralNumber.h"

/** Default constructor for GeneralNumber
 */
GeneralNumber::GeneralNumber() {
  // Just a placeholder for now -- nothing to do.
}

/** Generates a printable representation of the object.
 * @return Freshly-allocated C-stype string
 */
char* GeneralNumber::toString() const {
  char* rep; // String representation of the vlaue.
  rep = strdup("Never instantiate a plain GeneralNumber!");
  return rep;
}

/** Demonstrates a non-virtual function.
 * @return Freshly-allocated C-stype string
 */
char* GeneralNumber::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralNumber!");
  return rep;
}

/** Generates an equivalent GeneralLong
 * @return Pointer to a freshly-allocated GeneralLong object
 */
GeneralLong* GeneralNumber::toGeneralLong() const {
  GeneralLong* g = new GeneralLong();
  return g;
}

/** Generates an equivalent GeneralRational
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralNumber::toGeneralRational() const {
  GeneralRational* g = new GeneralRational();
  return g;
}






/** Default constructor for GeneralLong 
*/
GeneralLong::GeneralLong() {
  value = 0L; // Default value is a long zero
}

/** Constructor for GeneralLong
 * @param value Number to store in the object
 */
GeneralLong::GeneralLong(long value) {
  this->value = value;
  // "this->value" means the field inside the object.
  // Just "value" means the parameter.
}

// See header comment in GeneralNumber 
char* GeneralLong::toString() const {
  // Allocate enough space for largest possible number.
  char* rep = (char*) malloc(MAX_DIGITS_IN_LONG + 1);

  sprintf(rep, "%ld", value); // convert to printable form.
  return rep;
}

/** Demonstrates a non-virtual function.
 * @return Freshly-allocated C-stype string
 */
char* GeneralLong::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralLong!");
  return rep;
}

/** Generates an equivalent GeneralLong
 * @return Pointer to a freshly-allocated GeneralLong object
 */
GeneralLong* GeneralLong::toGeneralLong() const {
  GeneralLong* g = new GeneralLong(value); // Very simple!
  return g;
}

/** Generates an equivalent GeneralRational
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralLong::toGeneralRational() const {
  GeneralRational* g = new GeneralRational(value, 1L);
  // Slightly more complicated!
  return g;
}




/** Default constructor for GeneralRational 
*/
GeneralRational::GeneralRational() {
  top = 0L;
  bottom = 1L;// Default value is a long zero over a long one
}

/** Constructor for GeneralRational
 * @param top Numerator to store in the object
 * @param bottom Denominator to store in the object
 */
GeneralRational::GeneralRational(long top, long bottom) {
  this->top = top;
  this->bottom = bottom;
  // "this->something" means the field inside the object.
  // Just "something" means the parameter.
}

// See header comment in GeneralNumber 
char* GeneralRational::toString() const {
  // Allocate enough space for largest possible number.
  char* rep = (char*) malloc((2 * MAX_DIGITS_IN_LONG) + 6);

  sprintf(rep, "[%ld / %ld]", top, bottom); // convert to printable form.
  return rep;
}

/** Demonstrates a non-virtual function.
 * @return Freshly-allocated C-stype string
 */
char* GeneralRational::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralRational!");
  return rep;
}

/** Generates an equivalent GeneralLong
 * @return Pointer to a freshly-allocated GeneralLong object
 */
GeneralLong* GeneralRational::toGeneralLong() const {
  GeneralLong* g = new GeneralLong(top / bottom);
  return g;
}

/** Generates an equivalent GeneralRational
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralRational::toGeneralRational() const {
  GeneralRational* g = new GeneralRational(top, bottom);
  return g;
}

