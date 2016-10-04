#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GeneralNumber.h"

/**Function recursively finds GCD
 *
 * @param A first long to find GCD of
 * @param B second long to find GCD of
 *
 * @return greatest common divisor
 */

long gcd_Helper(long A, long B)
{
    return (B==0) ? A : gcd_Helper(B, A % B); //euclids algorithm
}

/** Function that finds GCD and keeps sign intact
 *
 * @param A first long to find GCD of
 * @param B second long to find GCD of
 *
 * @return greatest common divisor
 */
long GCD(long A, long B)
{
    int commonSign = 1; 

    if( (A<0) && (B<0) ) //Common factor of -1
    {
        commonSign = -1;     
    }

    return commonSign*gcd_Helper(labs(A),labs(B));
}
/** Demonstrates a non-virtual function.
 * @return Freshly-allocated C-stype string
 */
char* GeneralNumber::foo() const {
  char* rep = strdup("This is the output of foo() for GeneralNumber!");
  return rep;
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

/**Gets the value of this general long
 *
 * @return value of general long
 */
long GeneralLong::getValue()
{
    return value;
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


/** Sums two numbers of type GeneralNumber together  
 *
 * @param num pointer to GeneralNumber
 * @return GeneralLong holding resutls of summation
 */
GeneralNumber* GeneralLong::sumWith(GeneralNumber* num)
{
    long sum = value + num->toGeneralLong()->getValue();
    return new GeneralLong(sum);
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

/** Sums this GeneralRational with any GeneralNumber
 *
 * @param numInput The General Number to sum with
 * @return A GeneralRational summed with this and the input
 */
GeneralNumber* GeneralRational::sumWith(GeneralNumber* numInput)
{
    GeneralRational * convInput = numInput->toGeneralRational();
    convInput->canonicalize();

    long inputDenom = convInput->getBottom(); //denominator from input

    long gc_denom = GCD(inputDenom, bottom); //greatest common denominator

    long final_denom = (inputDenom * bottom)/gc_denom; //Find LCM 

    //changing fractions to have the same denom
    long final_num = top*(final_denom/bottom) + (convInput->getTop() * (final_denom/inputDenom));
    
    GeneralRational* result = new GeneralRational(final_num, final_denom);

    result->canonicalize(); //put in simplest form

    delete(convInput);

    return result;
}


/** Returns numerator of rational
 *
 * @return Numerator of this general rational
 */

long GeneralRational::getTop()
{
    return top;
}

/** Returns denominator of rational
 *
 * @return Denominator of this general rational
 */

long GeneralRational::getBottom()
{
    return bottom;
}

/*! Canonicalizes a GeneralRational
 * Converts the GeneralRational to its canonical form. That is, the rational
 * number is written in its simplest form. If the ratio is negative, the sign is 
 * on the numerator, and the denominator is positive.
 *
 */
void GeneralRational::canonicalize()
{
    long gcd = GCD(top, bottom);

    int signMultiplier;

    if( top < 0 != bottom < 0) //if one of, but not both of, the parts of the function are negative
    {
        signMultiplier=-1; //remember sign for later
    }
    else signMultiplier=1;

    top = labs(top/gcd) * signMultiplier; //make the numerator negative;

    bottom = labs(bottom/gcd);
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

