#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "etest.h"

#define OUTFILENAME "etest.txt"

int main(int argc, char* argv[]) {
  printf("Starting program etest.\n"); 

  // Anybody recognize these names?
  Employee1 harry; // Declare a local variable (a struct).
  fillinEmployee1(&harry, 50000, "Harry Palmer"); // Fill in values

  Employee1 bluejay; // Declare a local variable (a struct).
  fillinEmployee1(&bluejay, 60000, "Erik Grantby");

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
  fclose(outfile); // Close the file

  // Output the employees to stdout.
  printEmployee1Verbose(&harry);
  printEmployee1Verbose(&bluejay);

#ifdef TESTMODE
  printf("You are seeing this message, because TESTMODE is defined.\n");
#endif
  
  printf("Ending program etest.\n"); 
  return 0;
}

/** Outputs one Employee1 structure in verbose form, to an open file stream
 * @param stream The output stream to write to (must already be open).
 * @param employee Pointer to the structure to print
*/

void outputEmployee1Verbose(FILE *stream, Employee1 *employee) {
  fprintf(stream, "Employee1:. Name = %s, Salary = %d\n",
	  employee->name, employee->salary);
}

/** Prints one Employee1 structure in verbose form
 * @param employee Pointer to the structure to print
*/

void printEmployee1Verbose(Employee1 *employee) {
 // Save effort -- make use of other function already written!
  outputEmployee1Verbose(stdout, employee);
}

/** Fills in the fields of an Employee1 structure
 * @param emp Pointer to the struct. MUST ALREADY EXIST!
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 */
void fillinEmployee1(Employee1* emp, int salary, char* name) {
  emp->salary = salary;
  emp->name = strdup(name);
}

/** Allocates an Employee1 struct and fills in its fields. 
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @param department Character string holding the department. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @return Pointer to the newly-allocated struct.
 */
Employee1* createEmployee1(int salary, char* name, char* department) {

}

