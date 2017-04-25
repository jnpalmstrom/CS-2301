/* File: binaryReadEmployees.c
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

  int inputFile = open("etest2.bin", O_RDONLY);
  if (inputFile == -1) {

    fprintf(stderr, "Can't read from file etest3.bin.\n");
    fprintf(stderr, "Encountered error %d, %s./n", errno, strerror(errno));
    return 1;
  }

  Employee1** arrOfEmp = readAllEmpsBinFile(inputFile, &numEmp);

  close(inputFile);
  printEmp1Array(arrOfEmp, numEmp);
  freeEmp1Array(arrOfEmp, numEmp);

  return 0;
}
