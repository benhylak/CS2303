/** mystring.c
 * @author Ben Hylak
 * Useful functions for strings/chars
*/
#include <string.h>
#include <stdlib.h>
// stdlib.h is needed to use malloc()
#include "mystring.h"
#include <stdio.h>

#define MIN_ASCII_PRINTABLE 33
#define MAX_ASCII_PRINTABLE 126

/**Gets random integer between min and max
 *
 * @param min Minimum random integer (floor)
 * @param max Maximum random integer (ceiling)
 */
int getRandomInt(int min, int max)
{
    return (rand() % (max+1-min)) + min; //remainder can never be > max-min, and max-min + min is max
}

/**Return single random character ascii 41-176
 *
 * @return random ascii character between dec 41-176 (printable chars)
 * @warning random generator must be seeded before use using srand or similar 
 */

char getRandomChar()
{
    return (char) getRandomInt(MIN_ASCII_PRINTABLE, MAX_ASCII_PRINTABLE);
}

/*! Create random string of specified length
 *
 * Creates random string with 'length' characters. This function uses the getRandomChar()
 * function also in this file. 
 *
 * @param length Length of random string
 * @return Pointer to random string.
 * @warning Random generator must be seeded before use with srand or similar. See man rand
 */

char* getRandomString(int length)
{
    char* newStr = (char*)malloc(length*sizeof(char) +1); //size of string +1 for terminator

    for(int i=0; i<length-1; i++)
    {
        newStr[i] = getRandomChar();
    }

    newStr[length] = '\0'; //null terminate string. Size of Array is length+1, so length is last element

    return newStr;
}

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/

char* mystrdup(const char* src) {
  int length; // Length of the source string
  char* newstr; // Pointer to memory which will hold new string

  length = strlen(src) + 1;  // Leave space for the terminator
  newstr = (char*) malloc(length); // Must cast!

  // If no memory was available, return immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  // Note: strcpy() always puts the null terminator at the tend of the string.
  myStrCpy(newstr, src);
  return newstr;
}

/** Counts the length of a string
 * @param dest String to count
 * @return Length of String
 * @warning string must be null terminated
 */
int myStrLen(const char* dest)
{
    int len = 0;

    while(*(dest++)) len++;

    return len;
}

/** Copies string starting at address of dest, including null terminator
 * @param dest Address string is copied into
 * @param src String to copy
 * @return address of copied string
 * @warning src must be null terminated
 */
char* myStrCpy(char* dest, const char* src)
{
    char* destPreserved = dest;

    while(*src) //while null terminator hasn't been reached
    {
        *dest = *src; //copy over character
        src++; //next element of source
        dest++; //next element of destination
    }

    *dest = '\0'; //null terminate string

    return dest;
}

/**! Appends the src string to the dest string
 *
 * Appends the src string to the dest string, overwriting the terminating
 * null byte ('\0') at the end of dest, and  then  adds  a  terminating  null  byte.
 *
 * @param dest String that will have src appended to the end
 * @param src String that will be appended to the end of dest
 * @return Pointer to result string
 * @warning If dest is not large enough, program behavior is unpredictable; buffer
 * overruns are a favorite avenue for attacking secure programs
 *
 */
char* myStrCat(char *dest, const char* src)
{
    char* destPreserved = dest;
    
    int startIndex = myStrLen(dest); //although the index is len-1, the -1 is cancelled
                                    //because myStrLen doesn't include null terminator.

    for(dest = dest + (startIndex*sizeof(char)); *src; ++dest)
    {                       //dest pointer = to null terminator, if src isn't null terminator, increment dest pointer to next pos;
        *dest = *src; //copy
        src++;
    }

    *(++dest) = '\0'; //because for loop is eval'd before incrementing, increment dest to reach
                        //spot for terminator

    return destPreserved;
}



/**! Appends the src string to the dest string 
 *
 * Appends the src string to the dest string, overwriting the terminating
 * null byte ('\0') at the end of dest, and  then  adds  a  terminating  null  byte.
 * This function will use at most n bytes from src and src does not have to be null terminated
 * if it contains n or more bytes. The resulting string is always null terminated.
 *
 * @param dest String that will have src appended to the end
 * @param src String that will be appended to the end of dest
 * @return Pointer to result string
 * @warning because the result is always null terminated, dest must be at least strlen(dest)
 * + n + 1
 *
 */
char* myStrnCat(char *dest, const char* src, size_t n)
{
    char* destPreserved = dest;
    int added = 0; 

    dest = dest + (myStrLen(dest) * sizeof(char)); //set dest pointer equal to null terminator

    while(added<n && *src) //loop through until we've added n letters or hit a null terminator in src
    {
        *dest = *src; //copy value of src to dest
        
        ++src; //next letter in src
        ++dest; //next space for a letter in dest
        ++added; //increment number of letters added
    }

    *dest = '\0'; //null terminate end of string

    return destPreserved;
}

/**inserts numOfZeros null terminators starting at dest
 * 
 * @param dest Address to start inserting 0s at
 * @param numOfZeros how many zeroes to add
 * @returns false if error, true if success
 */

int insertZeros(char* dest, int numOfZeros)
{
   for(int i=0; i< numOfZeros; ++i)
   {
       (*dest++) = '\0';
   } 

   return 1; //success
}

/** Copies the stirng pointer to src to the buffer pointed to by dest
 *
 * Copies the string pointed to by src, including the null terminator byte, to the buffer
 * pointed to by dest. The strings may not overlap. At most n bytes of src are copied. If 
 * the length of src is less than n, myStrnCpy() writes additional null bytes to dest to ensure
 * that a total of n bytes are written
 *
 * @param dest Destination buffer
 * @param src String to copy
 * @returns pointer to buffer with src
 * @warning If there is no null byte among the first n bytes of src, the string places in dest
 * will not be null terminated.
 */
 char * myStrnCpy(char* dest, const char* src, size_t n)
{
    char* destPreserved = dest; //save original destination (head of array)
    size_t copied = 0; //number of chars copied

    while(copied<n && *src) //until we've copied n characters or hit the null terminator of src
    {
        *dest = *src; //copy value 

        copied++;
        src++;
        dest++;
    }

    insertZeros(dest, n-copied); //pad end of string with 0s if strlen(src) < n

    return destPreserved;
}

/** Returns a pointer to a new string which is a duplicate of the  string. A maximum of n
 * bytes are copied. If s is longer than n, only n bytes are copied and a terminating null byte
 * is added. 
 *
 *  @param src string to duplicate
 *  @param n max elements to copy
 *  @returns pointer to new string in memory
 */
char* myStrnDup(const char* src, size_t n)
{
    int srcLen = strnlen(src, n); //returns the smaller value, either src or n
    char* newStr;

    newStr = (char*) malloc(srcLen+1); //allocated array with space for null terminator
    if(!newStr) return (char*) 0; //no memory was available
    
    myStrnCpy(newStr, src, n); //copy into new memory location

    return newStr;
}





 







