/*Class for Tree Node. 
 *
 * Represents a node in a tree. Has left and right and its own data
 *
 * @author Benjamin Hylak
 */ 

#ifndef TNODE_H
#define TNODE_H

#include <strings.h>
#include <string>

using namespace std;

class Tnode
{
    public:
        Tnode();
        Tnode(const char *data);

       // Tnode(Tnode* left, Tnode* right);
       // Tnode(string data, Tnode* left, Tnode* right);

        const char * getData();
        
        void add(const char* toAdd);
        void printAscending();
        Tnode* left;
        Tnode* right;
        void FreeNode();
    private:
        const char *data;
};

#endif
