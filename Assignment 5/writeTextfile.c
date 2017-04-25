/* File: writeTextfile.c
 *
 */


// Name: Jack Palmstrom
// Username: jnpalmstrom

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "etest.h"

int main() {

  int numEmp;
  

  while (numEmp > 0 || !sscanf(readline("How many employees are there: "),
			       "%d", &numEmp)) {
    printf("Please input the number of employees.\n");
  }

  printf("Please input data to complete %d total employees\n", numEmp);

  Employee1** arrOfEmp = inputEmp1Array(numEmp);
  printEmp1Array(arrOfEmp, numEmp);

  printf("Writing to file etest2.txt.\n");

  FILE *outputFile = fopen("etest2.txt", "w");

  if (outputFile == NULL) {
    return 1;
  }

  outputEmp1Array(outputFile, arrOfEmp, numEmp);
  printf("Writing to file etest2.txt is complete.\n");
  fclose(outputFile);

  freeEmp1Array(arrOfEmp, numEmp);
  

  return 0;
}




