/* File: readEmployees.c
 *
 */


// Name: Jack Palmstrom
// Username: jnpalmstrom

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <readline/readline.h>
#include "etest.h"

int main() {

  int numEmp;
  

  FILE *inputFile = fopen("etest2.txt", "r");
  if (inputFile == NULL) {

    fprintf(stderr, "Can't read from file etest3.txt.\n");
    fprintf(stderr, "Encountered error %d, %s./n", errno, strerror(errno));
    return 1;
  }

  Employee1** arrOfEmp = readAllEmpsFile(inputFile, &numEmp);

  fclose(inputFile);
  printEmp1Array(arrOfEmp, numEmp);
  freeEmp1Array(arrOfEmp, numEmp);
 
  return 0;
}
