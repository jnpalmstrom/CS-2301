// Name: Jack Palmstrom
// Username: jnpalmstrom

// --------------------- Header File --------------------- //
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sort.h"
// ------------------------------------------------------- //

/** Program which takes an array of integers, prints it,
 * sorts it, prints it again, and reports how long the sorting took.
 * @param a Array of integers.
 * @param count Number of integers in the array.
 * @return 0 if success, 1 if error (wrong number of arguments)
 */

void timesort (int a[], int count) {

  struct timeval start_time;        // Time stamps for start and end of sorting
  struct timeval end_time;
  struct timeval sort_time;         // Elapsed time while sorting

  printf("Unsorted array:\n");
  print_int_array(a, count);

  gettimeofday(&start_time, NULL);  // Get timestamp
  sort_descending(a, count);        // Sort array
  gettimeofday(&end_time, NULL);    // Get timestamp

  printf("Sorted array (descending order):\n");
  print_int_array(a, count);

  printf("Timestamp before sorting: ");
  print_timeval(start_time); 
  printf("Timestamp after sorting: ");
  print_timeval(end_time);
  sort_time = timediff(start_time, end_time);
  printf("Time spent sorting: ");
  print_timeval(sort_time); 

  return; // Nothing to return
}
