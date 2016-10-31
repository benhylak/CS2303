#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GeneralNumber.h"
#include <stdio.h>
#include <math.h>
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

GeneralDouble* GeneralLong::toGeneralDouble() const {
    GeneralDouble* g = new GeneralDouble(static_cast<double>(value)); //convert long to double

    return g; //return result;
}


/** Sums two numbers of type GeneralNumber together  
 *
 * @param num pointer to GeneralLong
 * @return GeneralNumber holding resutls of summation
 */
GeneralNumber* GeneralLong::sumWith(GeneralNumber* num)
{
    long sum = value + num->toGeneralLong()->getValue();
    return new GeneralLong(sum);
}

/** Subtracts the inputted GeneralNumber from this GeneralNumber
 *
 * @param Input that will be subtracted
 * @return GeneralLong with result
 */
GeneralNumber* GeneralLong::minus(GeneralNumber* num)
{
    GeneralLong* convInput= num->toGeneralLong(); //convert input to GeneralLong

    return new GeneralLong(value-(convInput->getValue())); //subtract and return
}
/** Divides this GeneralLong by any GeneralNumber
 *
 * @param numInput the GeneralNumber to divde by
 * @return A GeneralRational with the result of this value divided by the input
 */
GeneralNumber* GeneralLong::divideBy(GeneralNumber* numInput)
{
    GeneralRational* convInput = numInput->toGeneralRational(); //convert input to general rational

    long newTop = value * convInput->getBottom();
    long newBottom = 1 * convInput->getTop();

    GeneralRational* calcResult = new GeneralRational(newTop, newBottom); 
    calcResult->canonicalize();

    return calcResult;
}

/** Multiplies this GeneralLong with any GeneralNumber
 *
 * @param numInput the number to multiply by
 * @return GeneralLong with result of multiplication
 */
GeneralNumber* GeneralLong::multiplyBy(GeneralNumber* numInput)
{
    GeneralLong* convInput = numInput->toGeneralLong();

    GeneralLong* calcResult = new GeneralLong(value * convInput->getValue());

    return calcResult;
}

/** Default constructor for GeneralDouble 
*/
GeneralDouble::GeneralDouble() {
    value = 0L; // Default value is a long zero
}

/** Constructor for GeneralDouble
 * @param value Number to store in the object
 */
GeneralDouble::GeneralDouble(double value) {
    this->value = value;
    // "this->value" means the field inside the object.
    // Just "value" means the parameter.
}

/**Gets the value of this general long
 *
 * @return value of general long
 */
double GeneralDouble::getValue()
{
    return value;
}

// See header comment in GeneralNumber 
char* GeneralDouble::toString() const {
    // Allocate enough space for largest possible number.
    char* rep = (char*) malloc(MAX_DIGITS_IN_LONG + 1);

    sprintf(rep, "%f", value); // convert to printable form.
    return rep;
}


GeneralLong* GeneralDouble::toGeneralLong() const{
    GeneralLong* g = new GeneralLong(static_cast<long>(value));

    return g; //return the value of the new general long
}
/** Generates an equivalent GeneralDouble
 * @return Pointer to a freshly-allocated GeneralDouble object
 */
GeneralDouble* GeneralDouble::toGeneralDouble() const {
    GeneralDouble* g = new GeneralDouble(value); // Very simple!
    return g;
}

/** Generates an equivalent GeneralRational (Implementation inspired by StackOverflow)
 * @return Pointer to a freshly-allocated GeneralRational object
 */
GeneralRational* GeneralDouble::toGeneralRational() const {
    double intPart = floor(value);
    double fracPart = value - intPart;

    long precision = 1000000000; // accuracy.
    
    long thisGCD = GCD(static_cast<long>(round(fracPart * precision)), precision);

    long denominator = precision / thisGCD; 
    long numerator = round(fracPart * precision) / thisGCD;

    GeneralRational* g = new GeneralRational(numerator, denominator);

    return g;
    return new GeneralRational(0L, 0L);
}


/** Sums two numbers of type GeneralNumber together  
 *
 * @param num pointer to GeneralDouble
 * @return GeneralNumber holding resutls of summation
 */
GeneralNumber* GeneralDouble::sumWith(GeneralNumber* num)
{
    double sum = value + num->toGeneralDouble()->getValue();
    return new GeneralDouble(sum);
}

/** Subtracts the inputted GeneralNumber from this GeneralNumber
 *
 * @param Input that will be subtracted
 * @return GeneralDouble with result
 */
GeneralNumber* GeneralDouble::minus(GeneralNumber* num)
{
    GeneralDouble* convInput= num->toGeneralDouble(); //convert input to GeneralDouble

    return new GeneralDouble(value-(convInput->getValue())); //subtract and return
}
/** Divides this GeneralDouble by any GeneralNumber
 *
 * @param numInput the GeneralNumber to divde by
 * @return A GeneralRational with the result of this value divided by the input
 */
GeneralNumber* GeneralDouble::divideBy(GeneralNumber* numInput)
{
    GeneralDouble* convInput = numInput->toGeneralDouble();
    GeneralDouble* calcResult = new GeneralDouble(value / convInput->getValue());

    return calcResult;
}

/** Multiplies this GeneralDouble with any GeneralNumber
 *
 * @param numInput the number to multiply by
 * @return GeneralDouble with result of multiplication
 */
GeneralNumber* GeneralDouble::multiplyBy(GeneralNumber* numInput)
{
    GeneralDouble* convInput = numInput->toGeneralDouble();

    GeneralDouble* calcResult = new GeneralDouble(value * convInput->getValue());

    return calcResult;
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

/** Subtracts the inputted value from this value
 *
 * @param GeneralNumber representing inputted value
 * @return GeneralNumber with calculated result
 */
GeneralNumber* GeneralRational::minus(GeneralNumber* numInput)
{
    GeneralRational * convInput = numInput->toGeneralRational();
    convInput->canonicalize();

    long inputDenom = convInput->getBottom(); //denominator from input

    long gc_denom = GCD(inputDenom, bottom); //greatest common denominator

    long final_denom = (inputDenom * bottom)/gc_denom; //Find LCM 
    //changing fractions to have the same denom
    //
    long final_num = top*(final_denom/bottom) - (convInput->getTop() * (final_denom/inputDenom));

    GeneralRational* result = new GeneralRational(final_num, final_denom);

    result->canonicalize(); //put in simplest form

    delete(convInput);

    return result;
}

/** Divides this GeneralRational by any GeneralNumber
 *
 * @param numInput the GeneralNumber to divde by
 * @return A GeneralRational with the result of this value divided by the input
 */
GeneralNumber* GeneralRational::divideBy(GeneralNumber* numInput)
{
    GeneralRational* convInput = numInput->toGeneralRational(); //convert input to general rational

    long newTop = top * convInput->getBottom();
    long newBottom = bottom * convInput->getTop();

    GeneralRational* calcResult = new GeneralRational(newTop, newBottom); 
    calcResult->canonicalize();

    return calcResult;
}

/** Multiplies this GeneralRational by any GeneralNumber
 *
 * @param numInput the GeneralNumber to divide by
 * @return a GeneralRational with the result of the calculation
 */
GeneralNumber* GeneralRational::multiplyBy(GeneralNumber* numInput)
{
    GeneralRational* convInput = numInput->toGeneralRational();

    long newTop = top * convInput->getTop();
    long newBottom = bottom * convInput->getBottom();

    GeneralRational* calcResult = new GeneralRational(newTop, newBottom); 
    calcResult->canonicalize();

    return calcResult;
}

/** General Rational to GeneralDouble 
 *
 * @returns GeneralDouble with value from GeneralRational
 */
GeneralDouble* GeneralRational::toGeneralDouble() const
{
    GeneralDouble* g = new GeneralDouble(static_cast<double>(top) / static_cast<double>(bottom));
    return g;
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

