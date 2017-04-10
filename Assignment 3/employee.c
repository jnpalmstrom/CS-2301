/** employee.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Jack Palmstrom 
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ----------------- Header Files -------------------------------------- //
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include "employee.h"
// --------------------------------------------------------------------- //

/** creates an Employee struct from data passed in as parameters
 * @param name Pointer to character array expressing name of employee
 * @param birth_year Integer birth_year
 * @param start_year Integer start_year
 * @return Pointer to created Employee struct
 */

Employee* make_employee(char* name, int birth_year, int start_year) {

  Employee* e;
  e  = (Employee*)malloc(sizeof(Employee));

  e->name = name;
  e->birth_year = birth_year;
  e->start_year = start_year;
  return e;
}

/** prints an Employee struct
 * @param e Pointer to the Employee struct to be printed
 */
void print_employee(Employee* e) {

  printf("Pointer: %p\n", e);
  printf("Name: %s\n", (*e).name);
  printf("Birth year: %i\n", (*e).birth_year);
  printf("Start year: %i\n", (*e).start_year);
  printf("\n");
  
}


// --------------------------- PART 4 ------------------------------------ //
/**
 * @return char random ASCII character
 */
char rand_char() {

  char any_char;
  const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
  any_char = alphabet[rand() % (sizeof(alphabet) - 1)];
  return any_char;
}
// ----------------------------------------------------------------------- //


// --------------------------- PART 5 ------------------------------------ //
/**generates a random string of size length
 * @param length the size of the string to be generated
 * @return Pointer to the character array that holds the generated string
 */
char* rand_str_generator(int length){

  char *string = NULL;

  if (length) {

    int counter;
    string = malloc(sizeof(char) * (length + 1));  

    for(counter = 0; counter < length; counter++){
      
      string[counter] = rand_char();
    }
    string[length] = '\0';                                                 // Sets last element in array to NULL 
  }
  return string;
} 
// ----------------------------------------------------------------------- //


// --------------------------- PART 6 ------------------------------------ //
/** creates an Employee struct from random generated data fields
 * @return Pointer to created Employee struct
 */
Employee* random_employee() {

  char* rand_name;
  int birth_year, start_year, length;
  
  length = 10;
  rand_name = rand_str_generator(NAME_LENGTH);
  birth_year = 1000 + (rand() % 8999);
  start_year = 1000 + (rand() % 8999);
  
  return make_employee(rand_name, birth_year, start_year);
}
// ----------------------------------------------------------------------- //


// --------------------------- PART 7 ------------------------------------ //

/** allocates an array of size count pointers to Employee structs 
 * @param count Number of Employee structs that will be created
 * @return Pointer to array of Pointers all pointing to Employee structs
 */
Employee **make_employees(int count) {

  Employee **employees;                                                    // Pointer to array of pointers, each pointing to a random bank account struct
  Employee *pointer;
  int index;
  
  employees = malloc(sizeof(pointer) * (count + 1));                        // Allocate array to hold pointers
  
  for(index = 0; index < count; index++){
    
    pointer = random_employee();
    employees[index] = pointer;
  }
  
  return employees;
}

/** prints an array of pointers to Employee structs
 * @param employees Pointer to array of pointers to Employee structs
 * @param count Number of employees
 */
void print_employees(Employee **employees, int count) {

  int index;

  for(index = 0; index < count; index++){

    print_employee(employees[index]);
  }
}
// ----------------------------------------------------------------------- //


// --------------------------- PART 8 ------------------------------------ //
/**duplicates an array of pointers to Employee structs, but not what they point to
 * @param employees Pointer to array of pointers to Employee structs
 * @param size Size of the array of pointer employees
 * @return Pointer to the array of pointer copies
 */
Employee **shallow_copy(Employee **employees, int size) {

  Employee **shallow_copies;
  int index;
  
  shallow_copies = malloc(sizeof(**employees) * size);

  for(index = 0; index < size; index++){

    shallow_copies[index] = employees[index];
  }
  
  return shallow_copies;
}
// ----------------------------------------------------------------------- //


// --------------------------- PART 10 ----------------------------------- //
/** duplicates an array of pointers, including the structs that they point to
 * @param employees Pointer to the array of pointers to copy
 * @param size Size of the employees array
 * @return Pointer to the duplicate array 
 */
Employee **deep_copy(Employee **employees, int size){
  
  Employee **deep_copies;                                                  
  Employee *e; 
  int index;

  deep_copies = malloc(sizeof(**employees) * size);

  for(index = 0; index < size; index++){
    
    e = make_employee((*employees[index]).name, (*employees[index]).birth_year, (*employees[index]).start_year);
    deep_copies[index] = e;
  }
  
  return deep_copies;
}
// ----------------------------------------------------------------------- //


// --------------------------- PART 9 ------------------------------------ //
/** de-allocates all the structs pointed to by the employees array of pointers
 * @param employees Pointer to the array of pointers to be freed
 * @param size Number of employees
 */
void deallocate(Employee **employees, int size){

  int index;
  
  for(index = 0; index < size; index++) {
    
    free(employees[index]);                                                // Free each pointer in array of pointers
  }
  
  free(employees);                                                         // Free pointer to the array of pointers
}
// ----------------------------------------------------------------------- //
