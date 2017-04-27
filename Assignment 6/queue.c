/** queue.c
 * @author Jack Palmstrom
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ---------------- Header Files --------------- //
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
// --------------------------------------------- //

/** Creates a queue with a circular buffer
 * @param max_cells The number of cells in queue
 * @return Pointer to the queue
 */
Queue *create_queue(int max_cells) {

  Queue* queue;                              // Initialize a queue
  queue = (Queue*) malloc(sizeof(Queue));    // Allocate memory for the queue

  // Checks if the queue is empty
  if (queue == NULL) {
    return NULL;        
  }

  // Allocating space for entries to queue
  queue->buffer = malloc(sizeof(void*)* max_cells);

  if (queue->buffer == NULL) {

    free(queue);
    return NULL;
  }

  // Filling in queue struct
  queue->max_cells = max_cells;
  queue->cells_used = 0;
  queue->head_ptr = 0;
  queue->tail_ptr = 0;

  return queue;
}

/** Adds an element to the queue
 * @param which_queue Pointer to target queue struct
 * @param ptr Pointer to be added to the queue
 * @return int -1 for queue underflow or 0 for success
 */
int enqueue(Queue *which_queue, void* ptr){

  if(which_queue->cells_used >= which_queue->max_cells){
    which_queue->cells_used = which_queue->max_cells;
    return -1;
  }
  
  else{
    if(which_queue->head_ptr >= which_queue->max_cells){
      which_queue->head_ptr = 0;
    }
    
    which_queue->buffer[which_queue->head_ptr] = ptr; // Store ptr
    which_queue->head_ptr++;                          // Increment to point to next free cell
    which_queue->cells_used++;                        // Increment number of used cells
    return 0;                                         // Success
  }
}

/** Remove an element from the queue
 * @param which_queue the target queue which we are taking an element from
 * @return pointer to the removed element
 */
void* dequeue(Queue *which_queue) {

  void * element;
  
  if (which_queue->cells_used <= 0) {
    which_queue->cells_used = 0;
    printf("OH NO, Encountered a: Queue Underflow\n");
    return NULL;
  } 
    
  element = which_queue->buffer[which_queue->tail_ptr];
  which_queue->tail_ptr++;
  which_queue->cells_used--;

  if (which_queue->tail_ptr == which_queue->max_cells) {
    which_queue->tail_ptr = 0;
  }
        
  return element;
}
