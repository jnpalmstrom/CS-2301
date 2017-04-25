// Name: Jack Palmstrom
// Username: jnpalmstrom

#ifndef ETEST_H
#define ETEST_H

#include <stdio.h>
#define MAX_NAME (40)

// Define some structures
struct _employee1 {
  int salary; // Monthly salary in US dollars
  char *name; // Pointer to character string holding name of employee.
  char *dept; // MUST be dynamically allocated from the heap.
};

struct _employee2 {
  int salary; // Monthly salary in US dollars
  char name[MAX_NAME + 1]; // Character string holding name of employee.
  char *dept; // MUST be dynamically allocated from the heap.
};

typedef struct _employee1 Employee1; // For convenience
typedef struct _employee2 Employee2; // For convenience

// Function Prototypes
void printEmployee1Verbose(Employee1 *emp);
void outputEmployee1Verbose(FILE *stream, Employee1 *emp);
void fillinEmployee1(Employee1* emp, int salary, char* name, char* dept);
Employee1* createEmployee1(int salary, char* name, char* dept);
Employee1* inputEmp1();
Employee1** inputEmp1Array(int numEmp);
void printEmp1Array(Employee1** arrOfEmp, int numEmp);
void outputEmp1Array(FILE* stream, Employee1** arrOfEmp, int numEmp);
void freeEmp1Array(Employee1** arrOfEmp, int numEmp);
Employee1* readEmpsFile(FILE *stream);
Employee1** readAllEmpsFile(FILE *stream, int* numEmp);
void outBinEmp(int fileDescript, Employee1 *emp);
void outBinEmpsArray(int fileDescript, Employee1** arrOfEmp, int numEmp);
Employee1* readEmpBinaryFile(int fileDescript);
Employee1** readAllEmpsBinFile(int fileDescript, int* numEmp);

#endif
