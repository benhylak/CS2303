#include "tree.h"

/** Tree constructor */

Tree::Tree()
{
    root = NULL;
}

/** Adds the given data (string) to the tree.
 *
 * Adds the given data to the tree. Strings with its first non similar letter below this node's are on the left. Otherwise, right. If the string toAdd is the same as this node's , it is ignored.
 *
 * @param data C-Style string to add
 */
void Tree::add(const char *data)
{
    if(root==NULL)
    {
        root = new Tnode(data);
    }
    else
    {
        root->add(data);
    }
}

/** Prints the array in ascending order (lowest to highest) 
 */

void Tree::printAscending()
{
    root->printAscending();
}

/** Frees all nodes in this tree (post order)
 */
void Tree::FreeTree()
{
    root->FreeNode();
}

