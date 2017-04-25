/* File: etest.c 
 *
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "etest.h"


#define OUTFILENAME "etest.txt"

int main(int argc, char* argv[]) {
  printf("Starting program etest.\n"); 

  // Anybody recognize these names?
  Employee1 harry; // Declare a local variable (a struct).
  fillinEmployee1(&harry, 50000, "Harry Palmer", "Seafood"); // Fill in values

  Employee1 bluejay; // Declare a local variable (a struct).
  fillinEmployee1(&bluejay, 60000, "Erik Grantby", "Deli");

  Employee1* Jack;
  Jack = createEmployee1(45000, "Jack Palmstrom", "Bakery");
  Employee1* Daxter;
  Daxter = createEmployee1(30000, "Daxter Smith", "Produce");
  
  // Output the employees to a file.
  printf("About to write to file %s.\n", OUTFILENAME);
  FILE *outfile = fopen(OUTFILENAME, "w"); // Open or create file for writing

  if(outfile == NULL) {
    perror("Failed: ");
    fprintf(stderr, "Uh-oh!\n");
    fprintf(stderr, "Error with program %s\n", argv[0]);
    fprintf(stderr, "Error Number: %d %s\n",errno, strerror(errno));
    fprintf(stderr, "Error: Could not open file: %s\n", OUTFILENAME);
    return 1;
  }
  
  outputEmployee1Verbose(outfile, &harry);
  outputEmployee1Verbose(outfile, &bluejay);
  outputEmployee1Verbose(outfile, Jack);
  outputEmployee1Verbose(outfile, Daxter);
  fclose(outfile); // Close the file

  // Output the employees to stdout.
  printEmployee1Verbose(&harry);
  printEmployee1Verbose(&bluejay);
  printEmployee1Verbose(Jack);
  printEmployee1Verbose(Daxter);

#ifdef TESTMODE
  printf("You are seeing this message, because TESTMODE is defined.\n");
#endif
  
  printf("Ending program etest.\n"); 
  return 0;
}
