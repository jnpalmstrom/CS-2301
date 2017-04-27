/**File to demonstrate queue implementation functionality: 
 * does things such as trying to dequeue off of an empty queue and add more items to a queue than it is allowed to accept. 
 * @author Jack Palmstrom
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// --------------- Header Files -------------- //
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
// ------------------------------------------- //

int main() {

  Queue* queue;                                     // Initial Queue struct
  int index;                                      // Index to move through for loop
  int count1, count2;
  char *data[] = {"A", "B", "C", "D", "E", "F"};  // Data to be inserted into the queue

  queue = create_queue(5);   // Initialize the queue with 5 elements
    
  printf("\n");
    
  for (index = 0; index < 6; index++) {  // Try to add on 6 items to a queue with max_cells 5

    count1 = index + 1;
      
    printf("Enqueue %d: %s\n", count1, data[index]);
    enqueue(queue, data[index]);
  }
    
  printf("\n");
  printf("Attempting to dequeue more than 5 elements...\n");
  printf("\n");
    
  for (index = 0; index < 6; index++) {
    count2 = index + 1; 
    printf("Dequeue %d: %s\n", count2, (char *)dequeue(queue)); // Shows the 6th char* didn't make it on, 
    // Shows can't dequeue off an empty queue
  }
  printf("\n");
}
