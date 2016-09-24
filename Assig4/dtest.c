#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Totals all the integers from 0 to n.
 * @param n Value to total up to.
 * @return The total
 */

int sum(int n) {
    int i; // Loop counter
    int total; // Total accumulates here

    total = 0;

    for (i = 0; i <= n; i++) { // Loop for every i, 0 through n, inclusive.
        total += i; // Add the next integer
    }

    return total;  
}

/** Program to sum consecutive integers.
 * @param argc Number of words on the command line.
 * @param argv Array of pointers to these words, as character strings.
 *    The first word after the program name is the number to count up to.
 */

int main(int argc, char* argv[]) {
    int n;
    int tot;
    int b = 2;

    int c = 3;

    if(&b > &c) printf("WTF\n");

    printf("Starting program dtest.\n");
    if (argc < 2) {
        fprintf(stderr,"Must enter one nmber on the command line.\n");
        return 1;
    }

    n = atoi(argv[1]);
    tot = sum(n);

    printf("Sum of 0 through %d is %d\n", n, tot);

    printf("Ending program dtest.\n"); 
    return 0;
}

void func1(int *p) {
    int i;
    if (!p)
        func1(&i);
    else if (p < &i)
        printf("Stack grows upward\n");
    else
        printf("Stack grows downward\n");
}

