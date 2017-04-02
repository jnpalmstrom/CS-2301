/** file at.c
 * @author Mike Ciaraldi
 *
 * Program to demonstrate fixed-size arrays in C.
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

// --------------------- Header Files --------------------- //
//                                                          //
#include <stdio.h>                                          //
#include "print_arrays.h"                                   //
// -------------------------------------------------------- //

// --------------------- CONSTANTS ------------------------ //
//                                                          //
#define SAMPLE_INT_ARRAY_SIZE (10)                          //
#define SAMPLE_DOUBLE_ARRAY_SIZE (5)                        //
// ---------------------------------------------------------//

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {
// -------------------- Variables ------------------------- //
                                                            //
  int i = 0;                                                // Loop counter
  int j = 0;                                                // Loop counter for array of doubles
  double dub = 0.0;                                         // 
  int a[SAMPLE_INT_ARRAY_SIZE];                             // Sample array for int demonstration
  double b[SAMPLE_INT_ARRAY_SIZE];                          // Sample array for doubles
// -------------------------------------------------------- //
  
  // Fill the array with consecutive integers
  for (i; i < SAMPLE_INT_ARRAY_SIZE; i++) {
    a[i] = i;
  }
  
  // Fill the array with consecutive doubles
  for (j; j < SAMPLE_DOUBLE_ARRAY_SIZE; j++) {
    b[j] = dub;
    dub += 1.0;
  }
  printf("Consecutive Integers: \n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);
  printf("\n");
  printf("Consecutive Doubles: \n");
  print_double_array(b, SAMPLE_DOUBLE_ARRAY_SIZE);

  return 0; // Success!
}
