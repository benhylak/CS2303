#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "GeneralNumber.h"
#include <iostream>
#include <string>

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
    nconv = sscanf(s, "[ %ld / %ld ]", &n1, &n2); 
    if (nconv == 2) { // Recognized!
        newobj = new GeneralRational(n1, n2);
        return newobj;
    }


    bool isDouble = false;

    for(size_t i=0; i<strlen(s); i++)
    {
        if(s[i] == '.') isDouble = true;
    }

    if(isDouble)
    {
        std::string strRes = s; 
        double res = stod(strRes);

        newobj = new GeneralDouble(res);
    }
    else
    {
        long res; 

        nconv = sscanf(s, "%ld", &res);

        if(nconv==1)
        {
            newobj = new GeneralLong(res);
        }
    }

    return newobj;

}
