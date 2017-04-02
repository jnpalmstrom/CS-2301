// Name: Jack Palmstrom
// Username: jnpalmstrom

// -------------------------------------------------------------- Header Files --------------------------------------------------------------------------- //
#include <stdio.h>
#include <stdlib.h>
#include "average.h"
// ------------------------------------------------------------------------------------------------------------------------------------------------------- //



int main(int argc, const char* argv[]) {

  int n;                                                              // Integer read from the command line goes here.
  int c;                                                              // Integer used for counting
  int total = argc;
  int grades[MAX_GRADES];                                             // Define and allocate the array
	
  if (argc < 2) {                                                     // Check that there was an entry
    printf("Must enter a number on the command line!\n");
    return 1;                                                         // Indicate failure
  }

  for (c = 1; c < argc; c++) {                                        // Runs through all given command line arguments
    n = atoi(argv[c]);                                                // Get string from the command line; convert to int
    grades[c] = n;                                                    // Store the value into array after being converted into an integer
  }
        
  average(grades, total);                                             // Call average function 
	
  return 0;                                                           // Indicate success!
}

