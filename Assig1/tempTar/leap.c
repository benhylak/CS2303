#include <stdio.h>
#include <stdlib.h>

/* Very simple program to demonstrate reading a number from the command line.
 * Usage
 *	./num some_number
 * Example:
 *	./num 2014
 *
 */

int main(int argc, const char* argv[])
{
	int n; //Integer read from the command line goes here
	
	if(argc < 2) //Check that there was an entry
	{
		printf("Must enter a number on the command line!\n");
		return 1; //Indicate failure;
	}

	n=atoi(argv[1]);
    
    if(n<1752) //Modern rule came into effect with Gregorian Calendar, function only handles this rule
    {
        printf("An input of %d is invalid because this program can only test years after 1752\n", n);
    }
    else if( (n%4==0 && n%100) || ( !(n%100) && !(n%400)) ) //if year is divisible by 4 and not 100 or year is divisible by 100 and 400
    {
        printf("%d is a leap year!\n", n);
    }
    else
    {
        printf("%d is not a leap year :(\n", n);
    }

	return 0;
}

