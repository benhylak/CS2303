#include <stdlib.h>
#include <stdio.h>
#include "objstack.h"
#include "foo.h"

using namespace std;

int main() {
    const int max_entries = 5; // size of stack
    Foo* new_foo1;
    Foo* new_foo2; 
    Foo* returned_foo;
    char *ts; // Points to string returned by toString();

    // First, create a stack
    Stack *new_stack = new Stack(max_entries);

    // Allocate a Foo and push it onto the stack.
    new_foo1 = new Foo(6, 14.79);
    ts = new_foo1->toString();
    printf("Pushing: %s\n", ts);
    free(ts);
    new_stack->push((void *) new_foo1);

    // Allocate another Foo and push it onto the stack.
    new_foo2 = new Foo(217, 3.14159);
    ts = new_foo2->toString();
    printf("Pushing: %s\n", ts);
    free(ts);
    new_stack->push((void *) new_foo2);

    // Peek at the top of the stack
    returned_foo = (Foo *) new_stack->peek();
    ts = returned_foo->toString();
    printf("Peeked: %s\n", ts);
    free(ts); // Do not free returned_foo, since we are still using it!

    // Retrieve the Foos and print them.
    returned_foo = (Foo *) new_stack->pop();
    if (!returned_foo) {
        printf("Stack is empty!\n");
    } else {
        ts = returned_foo->toString();
        printf("Popped: %s\n", ts);
        free(ts);
        delete(returned_foo);
    }

    returned_foo = (Foo *) new_stack->pop();
    if (!returned_foo) {
        printf("Stack is empty!\n");
    } else {
        ts = returned_foo->toString();
        printf("Popped: %s\n", ts);
        free(ts);
        delete(returned_foo);
    }

    //Stack should now be empty
    //

    returned_foo = (Foo *) new_stack->pop();
    if (!returned_foo) {
        printf("Stack is empty!\n");
    } else {
        ts = returned_foo->toString();
        printf("Popped: %s\n", ts);
        free(ts);
        delete(returned_foo);
    }


    new_foo1 = new Foo(1, 1);
    ts = new_foo1->toString();
    printf("Pushing: %s\n", ts);
    new_stack->push((void *) new_foo1);

    new_foo2 = new Foo(2, 1);
    ts = new_foo2->toString();
    printf("Pushing: %s\n", ts);
    new_stack->push((void *) new_foo2);

    Foo* new_foo3 = new Foo(3, 1);
    ts = new_foo3->toString();
    printf("Pushing: %s\n", ts);
    new_stack->push((void *) new_foo3);

    Foo* new_foo4 = new Foo(4, 1);
    ts = new_foo4->toString();
    printf("Pushing: %s\n", ts);
    new_stack->push((void *) new_foo4);

    Foo* new_foo5 = new Foo(5, 1);
    ts = new_foo5->toString();
    printf("Pushing: %s\n", ts);
    new_stack->push((void *) new_foo5);

    Foo* new_foo6 = new Foo(6,1);
    ts = new_foo6->toString();
    printf("Pushing: %s\n", ts);
    if(new_stack->push((void *) new_foo6) < 0) //should return error
    {
        printf("Could not push: %s\n", ts);
    }
    free(ts);

    for(int i=0; i<5; i++)
    {
        returned_foo = (Foo *) new_stack->pop();
        if (!returned_foo) {
            printf("Stack is empty!\n");
        } else {
            ts = returned_foo->toString();
            printf("Popped: %s\n", ts);
            free(ts);
            delete(returned_foo);
        }
    }
    

    // Clean up
    delete(new_stack);

    return 0;
}
