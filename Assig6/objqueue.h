/* Queue object class
 *
 * @author Benjamin Hylak
 * @warning Max queue size of 5
 */

#ifndef OBJ_QUEUE_H
#define OBJ_QUEUE_H

#define MAX_QUEUE_SIZE 5 

class ObjQueue 
{
    public:
        ObjQueue();
        void* dequeue();
        bool enqueue(void * toQueue);

    private:
        void **queue;
       
        int elements;
        int tailIndex; 
        int headIndex;

};

#endif
