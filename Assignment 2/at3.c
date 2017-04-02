/** file at3.c
 * @author Mike Ciaraldi
 *
 * Program to demonstrate fixed-size arrays in C.
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

// --------------------- Header Files -------------------------------- //
                                                                       //
#include <stdio.h>                                                     //
#include <stdlib.h>                                                    //
#include <time.h>                                                      //
#include "print_arrays.h"                                              //
#include "sort.h"                                                      //
// ------------------------------------------------------------------- //

// --------------------- CONSTANTS ----------------------------------- //
//                                                                     //
#define SAMPLE_INT_ARRAY_SIZE (10)                                     //
// ------------------------------------------------------------------- //

/** Main program for demonstrating arrays. It fills them and prints them.
 * @return 0, Indicating success.
 */

int main() {

// -------------------- Variables -----------------------------------  //
                                                                       // 
  int i;                                                               // Loop Counter
  int a[SAMPLE_INT_ARRAY_SIZE];                                        // Sample array for demonstration
// ------------------------------------------------------------------- //
  
  srand(time(NULL));

  populate_random(a, SAMPLE_INT_ARRAY_SIZE);

  // Prints the array of unsorted random integers
  printf("Unsorted Random Integers: \n");
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);
  
  bubble_sort(a, SAMPLE_INT_ARRAY_SIZE);

  printf("\n");
  printf("Sorted Random Integers: \n");
  // Prints the array of sorted random integers
  print_int_array(a, SAMPLE_INT_ARRAY_SIZE);

  return 0;
}
