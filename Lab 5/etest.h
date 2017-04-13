#ifndef ETEST_H
#define ETEST_H

#include <stdio.h>
#define MAX_NAME (40)

// Define some structures
struct _employee1 {
  int salary; // Monthly salary in US dollars
  char *name; // Pointer to character string holding name of employee.
              // MUST be dynamically allocated from the heap.
};

struct _employee2 {
  int salary; // Monthly salary in US dollars
  char name[MAX_NAME + 1]; // Character string holding name of employee.
              // MUST be dynamically allocated from the heap.
};

typedef struct _employee1 Employee1; // For convenience
typedef struct _employee2 Employee2; // For convenience

// function prototypes
void printEmployee1Verbose(Employee1 *employee);
void outputEmployee1Verbose(FILE *stream, Employee1 *employee);
void fillinEmployee1(Employee1* emp, int salary, char* name);
Employee1* createEmployee1(int salary, char* name, char* department);

#endif
