/**Custom Queue implementation 
 *
 * @author Ben Hylak
 */

#include "objqueue.h"
#include <stdlib.h>

//head points at object in queue (next to dequeue)
//tail points at available memory space in queue, null if full 

/**ObjQueue Constructor. 
 */

ObjQueue::ObjQueue()
{
    queue = static_cast<void**>(calloc(sizeof(void*), MAX_QUEUE_SIZE));

    elements = 0; 
    tailIndex = 0; 
    headIndex = 0;
}

/**Adds a pointer to the queue
 *
 * @param toQueue Pointer to enqueue
 * @return true on successful insertion, false if failure
 */
bool ObjQueue::enqueue(void *toQueue)
{
    if(elements >= MAX_QUEUE_SIZE)
    {
        return false;
    }
    else if(tailIndex > MAX_QUEUE_SIZE - 1) //if we are at the end, but still have more space
    {
        tailIndex = 0;
    }
        
    queue[tailIndex] = toQueue;

    ++elements;
    ++tailIndex; 

    return true;
}

/** Dequeues pointer from queue
 *
 * @return dequeued pointer, NULL if queue is empty
 */
void* ObjQueue::dequeue()
{
    if(elements>0)
    {
        if(headIndex > MAX_QUEUE_SIZE-1)
        {
            headIndex = 0;
        }

        --elements; //reduce num of elements in queue

        void* next = queue[headIndex];

        ++headIndex;

        return next; //return the head and then increment it
    }
    else return NULL;
}


