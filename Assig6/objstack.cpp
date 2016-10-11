#include <stdlib.h>
#include "objstack.h"

using namespace std;

/** Create a stack by initializing the fields of the object,
 *  including allocating memory to hold the stack entries.
 * @param max_cells Maximum entries in the stack
 */
Stack::Stack(int max_cells) {
  // Fill in the struct
  this->max_cells = max_cells; // "this->" needed to speciify field, not param.
  cells_used = 0; // Empty to start

  // Now allocate space for the stack entries.
  this->stack_base = (void **) calloc(sizeof(void *), max_cells);
  if (this->stack_base == NULL) {
    // Should signal an exception
  }

  next = stack_base; // Start at base
}

/** Destructor: cleans up a Stack object by deleting the memory
 * for holding the stack entries, but not the entries themselves.
 */
Stack::~Stack() {
  free(stack_base); // Free memory block with stack entries.
}

/** Pushes a pointer onto a Stack.
 * @param ptr Pointer to be pushed.
 * @return 0 if successful, -1 if not.
 */
int Stack::push(void *ptr) {
  // Check if stack is already full 
  if (cells_used >= max_cells) { //less than or equal to
    cells_used = max_cells; // Fix the field.
    return -1;  // Stack overflow.
  }

  // Push onto stack.
  *next = ptr;  // Store the pointer on the stack
  next++;       // Point to next free cell 
  cells_used++; 
  return 0;  // Success
}

/** Pops top of stack, and returns it.
 * @return Top entry of the stack, NULL if stack is empty.
 */
void* Stack::pop() {
  // Check if stack is empty
  if (cells_used <= 0) { //less than or equal to
    cells_used = 0; // Fix the field.
    return NULL;  // Stack empty
  }

  // Pop from stack.
  next--;         // Remember, this points to next free cell
  cells_used--;
  return *next;
}

/** Peek at top of stack, without popping
 * @return Top entry of the stack, NULL if stack is empty.
 */
void* Stack::peek() {
  // Check if stack is empty
  if (cells_used <= 0) {
    cells_used = 0; // Fix the field
    return NULL;  // Stack empty
  }

  //Return top of stack, without popping.
  //Remember, 'next' points to next free cell

  void** top = next - 1; // Point to real top of stack

  return (*top); // Get the entry
}
