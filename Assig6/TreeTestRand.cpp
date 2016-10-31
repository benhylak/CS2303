/** Program that tests putting random strings into a tree
 *
 * @author Benjamin Hylak
 *
 */

#include "tree.h"
#include "Tnode.h"
#include <iostream>
#include "mystring.h"
#include <time.h> 
#include <stdlib.h>

#define STR_LEN 4 

/**main function
 */

int main()
{
    Tree* testTree = new Tree();
    srand((int)time(NULL)); //seed random generator with time

    cout << "\nAdding 10 Random Strings 4 characters long to the tree:\n\n"; 

    for(int i=0; i<10; i++)
    {
        testTree->add(getRandomString(STR_LEN));
    }
 
    cout << "\nAscending Tree Sort Results:\n\n";

    testTree->printAscending();  

    testTree->FreeTree();

    delete testTree; 
}
