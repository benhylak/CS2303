/**Header file for Tree class
 */

#ifndef TREE_H
#define TREE_H

#include "Tnode.h"
#include <string>

class Tree
{
    public:
        Tree();
        void add(const char* data);
       //void setRoot(Tnode* rootToBe);

        void printAscending();
        void FreeTree();
    private:
        Tnode* root; 
};

#endif
