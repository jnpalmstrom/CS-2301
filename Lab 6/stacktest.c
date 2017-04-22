/** File: stacktest.c 
 * author: Jack Palmstrom
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ------------------- Header File --------------- //
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "stack.h"
// ----------------------------------------------- //

typedef struct {
  int x;
  double y;
} Foo;                       // Just some arbitrary struct


int main() {

  const int max_entries = 5; // Size of stack
  
  Foo* new_fooA;
  Foo* new_fooB;
  Foo* new_fooC;
  Foo* new_fooD;
  Foo* new_fooE;
  Foo* new_fooF;
    
  Foo* returned_foo;
  int push_stat;             // Returned status from push

  printf("\n");
  printf("PART 1: \n");  
  printf("Test 1: push 3 elements onto the stack, pop 2 elements off, and push 1 more element onto the stack. \n");

  // First, create a stack
  Stack *new_stackA = create_stack(max_entries);
  if (!new_stackA) {
    fprintf(stderr, "Unable to create stack. Error = %d: %s\n",
            errno, strerror(errno));
    return 1;
  }
  // Allocate another 6 Foo(s) and push each of them onto the stack.
  // 1.
  new_fooA = (Foo *) malloc(sizeof(Foo));
  new_fooA->x = 65;
  new_fooA->y = 100;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooA->x, new_fooA->y);
  push_stat = push(new_stackA, (void *) new_fooA);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 2.
  new_fooB = (Foo *) malloc(sizeof(Foo));
  new_fooB->x = 66;
  new_fooB->y = 101;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooB->x, new_fooB->y);
  push_stat = push(new_stackA, (void *) new_fooB);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 3.
  new_fooC = (Foo *) malloc(sizeof(Foo));
  new_fooC->x = 67;
  new_fooC->y = 102;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooC->x, new_fooC->y);
  push_stat = push(new_stackA, (void *) new_fooC);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stackC);
  if (returned_foo) {
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  // Retrieve the 1 Foo struct and print it.
  returned_foo = (Foo *) pop(new_stackA);
  if (returned_foo) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  // Retrieve the Foos and print them.
  returned_foo = (Foo *) pop(new_stackA);
  if (returned_foo) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  // 4.
  new_fooD = (Foo *) malloc(sizeof(Foo));
  new_fooD->x = 68;
  new_fooD->y = 102;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooD->x, new_fooD->y);
  push_stat = push(new_stackA, (void *) new_fooD);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  returned_foo = (Foo *) pop(new_stackA);
  if (returned_foo) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stackC);
  if (returned_foo) {
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  // Retrieve the 1 Foo struct and print it.
  returned_foo = (Foo *) pop(new_stackA);
  if (returned_foo) {
    printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  delete_stack(new_stackA);
  free(new_fooA);
  free(new_fooB);
  free(new_fooC);
  free(new_fooD);
  ////////////////////////////////////////////////////////////////////////////

  printf("\n");
  printf("PART 2: \n");  
  printf("Test 2: Push over 5 elements onto the stack, check that it correctly handles this error. \n");

  Stack *new_stackB = create_stack(max_entries);
  if (!new_stackB) {
    fprintf(stderr, "Unable to create stack. Error = %d: %s\n",
            errno, strerror(errno));
    return 1;
  }

  // 1.
  new_fooA = (Foo *) malloc(sizeof(Foo));
  new_fooA->x = 65;
  new_fooA->y = 100;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooA->x, new_fooA->y);
  push_stat = push(new_stackB, (void *) new_fooA);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 2.
  new_fooB = (Foo *) malloc(sizeof(Foo));
  new_fooB->x = 66;
  new_fooB->y = 101;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooB->x, new_fooB->y);
  push_stat = push(new_stackB, (void *) new_fooB);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 3.
  new_fooC = (Foo *) malloc(sizeof(Foo));
  new_fooC->x = 67;
  new_fooC->y = 102;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooC->x, new_fooC->y);
  push_stat = push(new_stackB, (void *) new_fooC);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 4.
  new_fooD = (Foo *) malloc(sizeof(Foo));
  new_fooD->x = 68;
  new_fooD->y = 102;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooD->x, new_fooD->y);
  push_stat = push(new_stackB, (void *) new_fooD);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 5.
  new_fooE = (Foo *) malloc(sizeof(Foo));
  new_fooE->x = 69;
  new_fooE->y = 103;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooE->x, new_fooE->y);
  push_stat = push(new_stackB, (void *) new_fooE);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 6.
  new_fooF = (Foo *) malloc(sizeof(Foo));
  new_fooF->x = 70;
  new_fooF->y = 104;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooF->x, new_fooF->y);
  push_stat = push(new_stackB, (void *) new_fooF);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stackB);
  if (returned_foo) {
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  // Clean up
  delete_stack(new_stackB);
  free(new_fooA);
  free(new_fooB);
  free(new_fooC);
  free(new_fooD);
  free(new_fooE);
  free(new_fooF);
  
  /////////////////////////////////////////////////////////////////////  

  printf("\n");
  printf("PART 3: \n");  
  printf("Test 3: Pop more than 5 elements, confirm that function correctly handles. \n");

  // First, create a stack
  Stack *new_stackC = create_stack(max_entries);
  if (!new_stackC) {
    fprintf(stderr, "Unable to create stack. Error = %d: %s\n",
            errno, strerror(errno));
    return 1;
  }

  // 1.
  new_fooA = (Foo *) malloc(sizeof(Foo));
  new_fooA->x = 65;
  new_fooA->y = 100;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooA->x, new_fooA->y);
  push_stat = push(new_stackC, (void *) new_fooA);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 2.
  new_fooB = (Foo *) malloc(sizeof(Foo));
  new_fooB->x = 66;
  new_fooB->y = 101;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooB->x, new_fooB->y);
  push_stat = push(new_stackC, (void *) new_fooB);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 3.
  new_fooC = (Foo *) malloc(sizeof(Foo));
  new_fooC->x = 67;
  new_fooC->y = 102;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooC->x, new_fooC->y);
  push_stat = push(new_stackC, (void *) new_fooC);
  if (push_stat) {
    printf("Stack is full.\n");
  }
  // 4.
  new_fooD = (Foo *) malloc(sizeof(Foo));
  new_fooD->x = 68;
  new_fooD->y = 102;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooD->x, new_fooD->y);
  push_stat = push(new_stackC, (void *) new_fooD);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // 5.
  new_fooE = (Foo *) malloc(sizeof(Foo));
  new_fooE->x = 69;
  new_fooE->y = 103;
  printf("Pushing: x = %5d, y = %10.3f\n", new_fooE->x, new_fooE->y);
  push_stat = push(new_stackC, (void *) new_fooE);
  if (push_stat) {
    printf("Stack is full.\n");
  }

  // Peek at the top of the stack
  returned_foo = (Foo *) peek(new_stackC);
  if (returned_foo) {
    printf("Peeked:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  } else {
    printf("Stack is empty.\n");
  }

  // Try to pop more than five Foos off of the top of the stack
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  returned_foo = (Foo *) pop(new_stackC);
  printf("Popped:  x = %5d, y = %10.3f\n", returned_foo->x, returned_foo->y);
  printf("Size of stack after fifth pop= %d\n", new_stackC->cells_used);
  returned_foo = (Foo *) pop(new_stackC);

  // Clean up
  delete_stack(new_stackC);
  free(new_fooA);
  free(new_fooB);
  free(new_fooC);
  free(new_fooD);
  free(new_fooE);

  return 0;
}
