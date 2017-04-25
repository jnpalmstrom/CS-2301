/* File: binaryWriteTextfile.c
 *
 */


// Name: Jack Palmstrom
// Username: jnpalmstrom

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
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

  printf("Writing to file etest2.bin.\n");

  int outputFile = open("etest2.bin",O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);

  if (outputFile == -1) {
    return 1;
  }

  outBinEmpsArray(outputFile, arrOfEmp, numEmp);
  printf("Writing to file etest2.txt is complete.\n");
  close(outputFile);

  freeEmp1Array(arrOfEmp, numEmp);

  return 0;
}
