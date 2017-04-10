/* Program which reads 1 number from the command line,
 * this number represents a count, it outputs random numbers equivalent to the count,
 * sorts them in descending order, and outputs the sorted list.
 *
 * Usage:
 *         ./sorttest2 count
 * Example:
 *         ./sorttest2 110
 *
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ----------------- Header Files ----------------- //
                                                    //
#include <stdio.h>                                  //
#include <stdlib.h>                                 //
#include <time.h>                                   //
#include "sort2.h"                                  //
// ------------------------------------------------ //


/** Main program
 * @param argc Number of words on the command line
 * @param argv 
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

int main (int argc, char* argv[]) {

  int *nums;                                            // Space to store randomly generated numbers.
  int i;                                                // Array index 
  int num_nums;                                         // How many numbers actually entered on the command line.
  int count;                                            // Integer entered on the command line.
  int which_sort;                                       // Specifies which sort function to use.
  
  count = atoi(argv[1]);
  which_sort = atoi(argv[2]);
  
  // Check that there are at least two numbers
  num_nums = argc - 1;
  if (num_nums != 2) { 
    printf("Must enter only 2 number on the command line! Exiting.\n");
    return 1; // Indicate failure
  }

  // Allocate an array big enough to hold the numbers
  nums = (int*) calloc(count, sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Unable to allocate enougn memory to hold the numbers.\n");
  }
  
  /* Generate Random Numbers until equivalent to count entered on command line. */
  for (i = 0; i < count; i++) {
    
    nums[i] = rand() % 101;
  }

  // Now print, sort, and print the array, and time how long the sorting took.
  timesort(nums, count, which_sort);

  return 0; // Indicate success!
}
