/** Class to define a stack; each entry can hold a pointer to anything.
 */
class Stack {
 public:
  // Fields:
  void **stack_base; // Pointer to base of stack
  void **next;  // Pointer to next free cell;
  int max_cells; // Maximum number of entries in the stack
  int cells_used; // Currently used number of cells

  // Function prototypes
  Stack (int max_cells);
  ~Stack();
  int push(void *ptr);
  void* pop();
  void* peek();
};


