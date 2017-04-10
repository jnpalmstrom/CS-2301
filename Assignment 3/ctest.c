/** ctest.c
 * Program to demonstrate character arrays and
 * dynamically-allocated memory.
 * @author Mike Ciaraldi
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ----------------- Header Files -------------------------------------- //
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// string.h covers the C-style string functions.
#include "mystring.h"
#include "employee.h"
#include <time.h>
// --------------------------------------------------------------------- //

// ----------------- CONSTANTS ----------------------------------------- //
const int MAX_CHARS = 20;                                                // Maximum number of characters in array
// --------------------------------------------------------------------- //

int main()
{
  // ----------------- Variables ----------------------------------------- //  
  char a1[MAX_CHARS + 1];                                                  // Character array--initially empty
  char a2[] = "Hello";                                                     // Character array--unsized but initialized
  char a3[MAX_CHARS + 1];                                                  // Character array--we will underfill it
  char* p1 = "Hello";                                                      // Pointer to constant string
  char* p2;                                                                // Will be a pointer to dynamically-allocated string
  int copy_limit;                                                          // Maximum characters to copy.
  // --------------------------------------------------------------------- //
  // ------------------ MY VERSION --------------------------------------- //  
  char b1[MAX_CHARS + 1];                                                  // Character array--initially empty
  char b2[] = "Hello";                                                     // Character array--unsized but initialized
  char b3[MAX_CHARS + 1];                                                  // Character array--we will underfill it
  char* ptr1 = "Hello";                                                      // Pointer to constant string
  char* ptr2;                                                                // Will be a pointer to dynamically-allocated string
  int copy_limit_b;                                                        // Maximum characters to copy.
  char test_copy_b[MAX_CHARS + 1];                                         // Character array initially empty
  char* ptr3;                                                                // Pointer to dynamically-allocated string
  // --------------------------------------------------------------------- //

  mystrcpy(a3, "Hello, also");                                             // Initialize uinderfilled character array

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: a1 = %p, a2 = %p, a3 = %p\n", a1, a2, a3);
  printf("          p1 = %p p2 = %p\n", p1, p2);

  mystrcpy(a1, "Hi");                                                    // Initialize character array

  printf("a1 = %s\n", a1);
  printf("a2 = %s\n", a2);
  printf("a3 = %s\n", a3);

  // Be sure there is a terminator character in the last element of the array
  a1[MAX_CHARS] = '\0';

  // Concatenate two character arrays, then print.
  mystrcat(a1, a2);
  printf("Concatenating a2 to the end of a1\n");
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1);                                 // How much space is left?
  printf("Concatenating a2 to the end of a1, with copy_limit = %d\n",
	 copy_limit);
  
  if (copy_limit > 0) mystrncat(a1, a2, copy_limit);
  printf("a1 = %s\n", a1);

  // Concatenate two character arrays safely, then print.
  copy_limit = MAX_CHARS - mystrlen(a1);                                 // How much space is left?
  printf("Concatenating a3 to the end of a1, with copy_limit = %d\n",
	 copy_limit);
  
  if (copy_limit > 0) mystrncat(a1, a3, copy_limit);
  printf("a1 = %s\n", a1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer a2 = %p, contents = %s\n", a2, a2);
  p2 = mystrdup(a2);
  printf("Duplicated string: \n");
  printf("Pointer p2 = %p, contents = %s\n", p2, p2);

  // ------------------ MY VERSION --------------------------------------- //  

  printf("\n\n");
  printf("Jack's Versions of the C library functions\n\n");

  /* Print the pointers.
     Note: this example prints
     the values of the pointers themselves, not the targets.
  */
  printf("Pointers: b1 = %p, b2 = %p, b3 = %p\n", b1, b2, b3);
  printf("          ptr1 = %p ptr2 = %p\n", b1, b2);

  mystrcpy(b1, "Hi");                                                    // Initialize character array

  printf("b1 = %s\n", b1);
  printf("b2 = %s\n", b2);
  printf("b3 = %s\n", b3);

  // Be sure there is a terminator character in the last element of the array
  b1[MAX_CHARS] = '\0';

  // Concatenate two character arrays, then print.
  mystrcat(b1, b2);
  printf("Concatenating b2 to the end of b1\n");
  printf("b1 = %s\n", b1);

  // Concatenate two character arrays safely, then print.
  copy_limit_b = MAX_CHARS - mystrlen(b1); 
  printf("Concatenating b2 to the end of b1, with copy_limit_b = %d\n",
	 copy_limit_b);
  if (copy_limit_b > 0)
    mystrncat(b1, b2, copy_limit_b);
  printf("b1 = %s\n", b1);

  // Concatenate two character arrays safely, then print.
  copy_limit_b = MAX_CHARS - mystrlen(b1); 
  printf("Concatenating b3 to the end of b1, with copy_limit_b = %d\n",
	 copy_limit_b);
  if (copy_limit_b > 0)
    mystrncat(b1, b3, copy_limit_b);
  printf("b1 = %s\n", b1);

  // Duplicate a string, using my function, then print
  printf("Before dup, pointer b2 = %p, contents = %s\n", b2, b2);
  ptr2 = mystrdup(b2);
  printf("Duplicated string: \n");
  printf("Pointer ptr2 = %p, contents = %s\n", ptr2, ptr2);
 
  // Duplicate string when length is greater than limit, using my function, then print
  printf("Before dup, pointer b2 = %p, contents = %s\n", b2,b2);
  ptr2 = mystrndup(b2, 3);
  printf("duplicated string up to 3 chars: \n");
  printf("Pointer ptr2 = %p, contexts = %s\n", ptr2, ptr2);
 
  // Duplicate string when length is equal to limit, using my function, then print
  printf("Before dup, pointer b2 = %p, contents = %s\n", b2,b2);
  ptr2 = mystrndup(b2, 5);
  printf("duplicated string up to 5 chars: \n");
  printf("Pointer ptr2 = %p, contexts = %s\n", ptr2, ptr2);
 
  // Duplicate string when length is greater than limit, using my function, then print
  printf("Before dup, pointer b2 = %p, contents = %s\n", b2,b2);
  ptr2 = mystrndup(b2, 7);
  printf("duplicated string up to 7 chars: \n");
  printf("Pointer ptr2 = %p, contexts = %s\n", ptr2, ptr2);
 
  ptr3 = mystrcpy(test_copy_b, ptr1);
  printf("length of str 'hello' is: %i\n", mystrlen(ptr1));
  printf("copy of str 'Hello' is: %s\n", ptr3);
  char* c1 = "bye";
  
  //testing when string length is greater than limit
  ptr3 = mystrncpy(test_copy_b, c1, 2);
  printf("2 char copy of str 'bye' onto string 'Hello' is: %s\n", ptr3);
  
  //testing when string length is less than limit
  ptr3 = mystrncpy(test_copy_b, c1, 5);
  printf("5 char copy of str 'bye' onto string 'byllo' is: %s\n", ptr3);
  
  //testing when string length is equal to limit
  ptr3 = mystrncpy(test_copy_b, ptr1, 5);
  printf("5 char copy of str 'Hello' is: %s\n", ptr3);


// ------------------ Employee STRUCT FUNCTIONS ------------------------------ //
  
  printf("\n\n");
  printf("Demo of Employee Struct Functions: \n\n");
  printf("Make_employee():\n\n");
  
  Employee* emp;
  char* name;
  int birth_year, start_year;
  
  name = "Jack";
  birth_year = 1996;
  start_year = 2005;
  emp = make_employee(name, birth_year, start_year);
  print_employee(emp);
  
  printf("Demo 2 random_employee()s:\n\n");
  Employee* emp1;
  Employee* emp2;
  emp1 = random_employee();
  emp2 = random_employee();

  print_employee(emp1);
  print_employee(emp2);  

  printf("Demo populating an array of 3 pointers to Employee structs: \n\n");
  
  Employee **employees;
  employees = make_employees(3);
  print_employees(employees, 3);
  
  printf("Demo employee shallow copies: \n\n");
  Employee **copies_of_emp;
  copies_of_emp = shallow_copy(employees, 3);
  print_employees(copies_of_emp, 3);
  
  printf("Demo employee deep copies: \n\n");
  Employee **deep_copies_emp;
  deep_copies_emp = deep_copy(employees, 3);
  print_employees(deep_copies_emp, 3);
  
  deallocate(employees, 3); // Free Pointerss

  return 0;
}
