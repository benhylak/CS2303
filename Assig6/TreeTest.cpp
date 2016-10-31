#include "tree.h"
#include "Tnode.h"
#include <iostream>

const char * test1 = "aaaa";
const char * test2 = "bbbb";
const char * test3 = "cccc";
const char * test4 = "dddd";
const char * test5 = "eeee";
const char * test6 = "ffff";

int main()
{
    Tree* testTree = new Tree();

    testTree->add(test4);
    testTree->add(test3);
    testTree->add(test6);
    testTree->add(test1);
    testTree->add(test2);
    testTree->add(test5);

    cout << "Sort Results:\n\n";

    testTree->printAscending();   
}
