/* File: struct.c
 *
 */


// Name: Jack Palmstrom
// Username: jnpalmstrom

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "etest.h"

/** Outputs one Employee1 structure in verbose form, to an open file stream
 * @param stream The output stream to write to (must already be open).
 * @param employee Pointer to the structure to print
*/

void outputEmployee1Verbose(FILE *stream, Employee1 *emp) {
  fprintf(stream, "Employee1:. Name = %s, Salary = %d, Department = %s\n",
	  emp->name, emp->salary, emp->dept);
}

/** Prints one Employee1 structure in verbose form
 * @param employee Pointer to the structure to print
*/

void printEmployee1Verbose(Employee1 *emp) {
 // Save effort -- make use of other function already written!
  outputEmployee1Verbose(stdout, emp);
}

/** Fills in the fields of an Employee1 structure
 * @param emp Pointer to the struct. MUST ALREADY EXIST!
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @param dept Character string holding the department. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 */
void fillinEmployee1(Employee1* emp, int salary, char* name, char* dept) {
  emp->salary = salary;
  emp->name = strdup(name);
  emp->dept = strdup(dept);
}

/** Allocates an Employee1 struct and fills in its fields. 
 * @param salary Annual salary in dollars
 * @param name Character string holding the name. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @param department Character string holding the department. Gets duplicated,
 *    and the pointer to the duplicate is put into struct.
 * @return Pointer to the newly-allocated struct.
 */
Employee1* createEmployee1(int salary, char* name, char* dept) {

  Employee1* e1;
  e1 = (Employee1*)malloc(sizeof(Employee1));

  fillinEmployee1(e1, salary, name, dept);

  return e1;
}


/** Prompts the user to enter fields to complete a new employee struct. Then it allocates the new Employee1 struct
 *  and creates the employee. It returns a pointer to the location of this new employee struct.
 *
 * @return Pointer to a new Employee1 struct
 */
Employee1* inputEmp1() {

  char* name;
  char* dept;
  char* sSalary;
  int salary;

  printf("Enter the info of the new employee: ");

  name = readline("Name of employee: ");

  do {
    sSalary = readline("Salary of employee: ");

  }
  while (salary < 0 || !sscanf(sSalary, "%d", &salary));
  
  
  dept = readline("Department of employee: ");

  Employee1* e;
  e = createEmployee1(salary, name, dept);

  free(name);
  free(sSalary);
  free(dept);
    
  return e;
  
}

/** Promts the user for the number of Employees they would like to create. Then prompts the users 
 *  for that many employees, creates the employees,  and fills an array with pointers to these structures. 
 * @param numEmp Number of Employees to ask for
 * @return A pointer to the array of pointers to Employees
 * 
 */
Employee1** inputEmp1Array(int numEmp) {

  int index; 

  Employee1** arrOfEmp = (Employee1**) malloc(sizeof(Employee1*) *numEmp);  
  
  for(index = 0; index < numEmp; index++) {
    
    arrOfEmp[index] = inputEmp1();
    printf("\n");
  }
  
  return arrOfEmp;
}

/** Prints all the Employee structures defined in an array of pointers to structures
 * @param arrofEmp Array of pointers to structs to dereference and print
 * @param numEmp Number of elements in the array
 *
 */
void printEmp1Array(Employee1** arrOfEmp, int numEmp) {

  int index;
  
  for(index = 0; index < numEmp; index++) {          

    printEmployee1Verbose(arrOfEmp[index]); 
  }
}

/** Outputs all the Employee structures defined in an array of pointers of structures to the specified file stream
 * @param stream The open file stream to output to
 * @param arrOfEmp Array of pointers to structs to dereference and print
 * @param numEmp Number of elements in the array
 *
 */
void outputEmp1Array(FILE* stream, Employee1** arrOfEmp, int numEmp) {

  int index; 

  for(index = 0; index < numEmp; index++) {
    
    outputEmployee1Verbose(stream, arrOfEmp[index]); 
  }
}

/** Frees memory allocated by the structures referenced in the provided array. Also frees memory allocated by the structure fields and by the array of pointers.
 * @param arrOfEmp Array of pointers to Employee Structs to 'deep' free
 * @param numEmp Number of elements in the array
 * 
 */
void freeEmp1Array(Employee1** arrOfEmp, int numEmp) {

  int index;
  
  for(index = 0; index < numEmp; index++) {            

    free(arrOfEmp[index]->name);
    free(arrOfEmp[index]->dept);
    free(arrOfEmp[index]);          
  }
  
  free(arrOfEmp);                
  
}

/** Reads an Employee from an open file and returns a pointer to that employee structure
 * @param stream The open file to read from
 * @return A pointer to the new Employee stuct
 * 
 */
Employee1* readEmpsFile(FILE *stream) {

  char read[50];
  char name[10];
  char sSalary[10] = "";
  char dept[10] = "";

  if(fscanf(stream, "%s", read) == EOF) {
    return NULL;
  }

 
  while (fscanf(stream, "%s", read) == 1 && strcmp(read, "=")) {

  }
 
  while (fscanf(stream, "%s", read) == 1 && strcmp(read, "Salary")) {

    strcat(name, read);
    strcat(name, " ");
  }
 
  while (fscanf(stream, "%s", read) == 1 && strcmp(read, "=")) {

  }
  
  fscanf(stream, "%s", sSalary);
  while (fscanf(stream, "%s", read) == 1 && strcmp(read, "=")) {

  }
  
  while (fscanf(stream, "%s", read) == 1 && strcmp(read, "Employee1")) {

    strcat(dept, read);
    strcat(dept, " ");
  }
  
  return createEmployee1(atoi(sSalary), name, dept);
}


/** Reads all the Employees from an open File and builds an array pointing to them
 * @param stream An open FILE Stream
 * @param numEmp Filled with the total number of employees read from the file
 * @return A pointer to the array of pointers to Employees
 * 
 * 
 */
Employee1** readAllEmpsFile(FILE *stream, int* numEmp) {

  Employee1* tempEmps;            
  Employee1** arrOfEmp = NULL;
  *numEmp = 1;
  

  while ((tempEmps = readEmpsFile(stream)) != NULL) {

    arrOfEmp = (Employee1**) realloc(arrOfEmp, sizeof(Employee1*) * (*numEmp));
    arrOfEmp[((*numEmp)++)-1] = tempEmps;
  }
  
  (*numEmp)--;
  return arrOfEmp; 
}


/** Write an employee struct to an already open binary file
 * @param fileDescript The file descriptor of the open file to write to
 * @param emp Pointer to the Employee struct to print
 */
void outBinEmp(int fileDescript, Employee1 *emp) {

  char Buf[100];
  
  if (strlen(emp->name) > 40 || strlen(emp->dept) > 40) {
    
    fprintf(stderr,"Fields exceed 40 characters. Canceling write.\n");
    return;
  }
  
  sprintf(Buf, "%-40s%-12d%-40s", emp->name, emp->salary, emp->dept); 
  write(fileDescript, Buf, strlen(Buf)); 
}

/** Outputs all the Employee structures defined in an array of pointers of structures to the specified binary file
 * @param fileDescript The open file descriptor to write to
 * @param arrOfEmp Array of pointers to structs to dereference and print
 * @param numEmp Number of elements in the array
 *
 */
void outBinEmpsArray(int fileDescript, Employee1** arrOfEmp, int numEmp) {

  int index;
  
  for(index = 0; index < numEmp; index++) {
    
    outBinEmp(fileDescript, arrOfEmp[index]); 
  }
}


/** Reads an Employee from an open binary file and returns a pointer to that employee structure
 * @param fileDescript The open file descriptor to read from
 * @return A pointer to the new Employee stuct
 * 
 */
Employee1* readEmpBinFile(int fileDescript) {

  char name[40] = "";
  char sSalary[12] = "";
  char dept[40] = "";
  
 
  if(read(fileDescript, name, 40) + read(fileDescript, sSalary, 12) + read(fileDescript, dept, 40) < 92) {
    return NULL;
  }
  
  return createEmployee1(atoi(sSalary), name, dept);
}


/* Reads all the employees from the specified binary file, allocates them, and returns a pointer to its locations in memory
 * @param fileDescript An open file descriptor
 * @param numEmp Will be filled with the number of employees read
 * @return A pointer to the array of pointers to Employees
 * 
 */
Employee1** readAllEmpsBinFile(int fileDescript, int* numEmp) {
  
  Employee1* tempEmps;            
  Employee1** arrOfEmp;

  arrOfEmp = NULL;
  *numEmp = 1;
  
 
  while ((tempEmps = readEmpBinFile(fileDescript)) != NULL) {
   
    arrOfEmp = (Employee1**) realloc(arrOfEmp, sizeof(Employee1*) * (*numEmp));
    arrOfEmp[((*numEmp) ++) -1] = tempEmps;
  }
  
  (*numEmp)--; 
  return arrOfEmp;
}



