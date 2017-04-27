/** Struct to define a queue; each entry can hold a pointer to anything
 * @author Jack Palmstrom
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

struct queue{
  
  void **buffer;     // Array of void pointers in memory
  int tail_ptr;      // Index number of tail of queue
  int head_ptr;      // Index number of next available cell in queue
  int max_cells;     // Max number of entries in the queue
  int cells_used;    // Currently used number of cells
  
};

typedef struct queue Queue; 

// Function Prototypes
Queue *create_queue(int max_cells);
int enqueue(Queue *which_queue, void* ptr);
void *dequeue(Queue *which_queue);
