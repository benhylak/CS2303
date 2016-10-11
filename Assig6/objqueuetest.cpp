/* This program is a test of the Object Queue class.
 *
 * @author Benjamin Hylak
 */

#include "objqueue.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

ObjQueue *testQueue; //queue for testing

/**Prints out the result of an attempted queue
 *
 * @param numToQ pointer to integer to try queueing 
 * @return true if successful, false if failure
 */
bool printTryQueue(int* numToQ)
{
    cout << "Adding " << *numToQ << " to queue.\n";

    if(testQueue->enqueue(static_cast<void*>(numToQ)))
    {
        cout << "Success\n";
        return true;
    }
    else
    {
        cout << "ERROR: Stack full!\n";
        return false;
    }
}

/**Prints out the result of an attempted dequeue
 *
 * @return true if successful, false if failure.
 */
bool printTryDequeue()
{

    int* dqd;

    dqd = static_cast<int*>(testQueue->dequeue());

    cout << "Trying Dequeue..."; 
    
    if(dqd!=NULL)
    {
        cout << "Success! Dequeued " << *dqd << "\n";
        return true;
    }
    else
    {
        cout << "ERROR: Nothing left to dequeue!\n";
        return false;
    }
}

/**Main function*/

int main()
{
    testQueue = new ObjQueue();

    cout << "\nTest program for ObjectQueue. The Queue can hold 5 elements. This program will take the follwoing steps:\n 1. Enqueue 6 Elements (once of which should fail)\n2. Dequeue 1 element\n3. Enqueue another element\n4. Finally, try dequeueing 6 elements (one of which should fail)\n";

    int* testVals = static_cast<int*>(calloc(sizeof(int), 6));

    for(int i=0; i<6; i++) //fill test vals with numbers 1 through 6 
    {
        testVals[i] = i+1;
    }

    for(int i=0; i<6; i++)
    {
        if(printTryQueue(testVals)) testVals++;
    }

    printTryDequeue();
    printTryQueue(testVals);

    if(testQueue->enqueue((void *) testVals))
    {
        cout << "Adding " << *testVals << "to queue"; 
    }

    for(int i=0; i<6; i++)
    {
        printTryDequeue();
    }
}
