/**Tree Node Class
 *
 * Represents a node in a tree. Has left node, right node, and it's own data in the form of a string.
 *
 * @author Benjamin Hylak
 */

#include "Tnode.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

/** Default constructor
 *
 * Default Constructor: data, left and right nodes set to null;
 */
Tnode::Tnode()
{
    data = NULL; 
    left = NULL; 
    right = NULL;
}

/**Secondary constructor. Takes data on construction. 
 *
 * @param data Node's data.
 */

Tnode::Tnode(const char *data)
{
    this->data = data;
    left = NULL;
    right = NULL;
}

/**Returns a node's data
 *
 * @return Node's string
 */
const char * Tnode::getData()
{
    return data; 
}

/**Adds string somewhere in tree
 *
 * Adds string somewhere in ascending order within the tree. If the first non similar letter in the string comes before this node's, it goes to the left. Otherwise, it goes to the right. If the string is a duplicate of the string in this node, it is ignored.
 *
 * @param toAdd C-Style string to add
 */
void Tnode::add(const char* toAdd)
{
    int compareVal = strcasecmp(toAdd, data);

    if(compareVal < 0) //search left
    {
        if(left==NULL)
        {
            left = new Tnode(toAdd);
            printf("Added %s\n", toAdd);    
        }
        else left->add(toAdd);
    }
    else if(compareVal > 0 ) //search right
    {
        if(right==NULL)
        {
            right = new Tnode(toAdd);
            printf("Added %s\n", toAdd);  
        }
        else right->add(toAdd);
    }
    else return; //string is duplicate of current nod.

}

/** Print all nodes in alphabetically ascending order. (Using in order traversal)
 */

void Tnode::printAscending()
{
    if(left!=NULL) left->printAscending();

    cout << data << "\n"; //my data 

    if(right!=NULL) right->printAscending();
}

/**Frees all nodes in this node's hierarchy. Performs free postorder (No sawed off branches)
 */

void Tnode::FreeNode()
{
    if(left!=NULL) left->FreeNode();
    if(right!=NULL) right->FreeNode();
    
    free((void*)data);
    delete this;
}
    
