/** file print_arrays.c
 * @author Mike Ciaraldi
 *
 * Functions for printing arrays.
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

// --------------------- Header Files --------------------- //
//                                                          //
#include <stdio.h>                                          //
#include <stdlib.h>                                         //
#include "print_arrays.h"                                   //
// -------------------------------------------------------- //

/** Print an array of ints, one per line.
 *  @param a Array to print
 *  @param num_entries Number of entries in the array
 */

void print_int_array(int a[], int num_entries) {

// -------------------- Variables ------------------------- //
  int i;                                                    // Loop counter
// -------------------------------------------------------- //

  for (i = 0; i < num_entries; i++) {
    printf("%d\n", a[i]);
  }
}


/** Print an array of doubles, one per line.
 *  @param d Array to print
 *  @param num_entries Number of entries in the array
*/

void print_double_array(double d[], int num_entries) {

// -------------------- Variables ------------------------- //       
  int i;                                                    // Loop Counter
// -------------------------------------------------------- //

  for (i = 0; i < num_entries; i++){
    printf("%f\n", d[i]);
  }
}

/** Seperate function for getting integer data from the command line
 *  and storing it into an array
 * @param argc Number of elements in the array 
 * @param argv Array of characters from command line input
 * @param storage_array Array to fill with integers
 * @param size_of_array Size of the array being filled with ints
 */
  
int fillArray(int argc, const char* argv[], int storage_array[], int size_of_array) {

// -------------------- Variables ------------------------- // 
  int i;                                                    // Loop Counter
  int index = 0;                                            // Index counter
// -------------------------------------------------------- //
  
  // Fill the array with ints from the command line
  for (i = 0; i < size_of_array; i++) {

    
    if ((i + 1) > (argc - 1)) {
      index = argc - 1;
      break;
    }
    
        
    storage_array[index] = atoi(argv[i + 1]);
    index += 1;
  } 
  return index; 
}
