/** file employee.h with functions on account structs
 * @author Jack Palmstrom
 */


#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#define NAME_LENGTH (10)    // The length of the random strings to be generated

//Employee structure with string name, int birth_year and int start_year
struct _Employee
{
  char* name;               // Name of employee
  int birth_year;           // Birth year of employee
  int start_year;           // Start year of employee
};

typedef struct _Employee Employee; //readability

// Function Prototypes
Employee* make_employee(char* name, int birth_year, int start_year);
void print_employee(Employee* e);

Employee* random_employee();
char* rand_str_generator(int length);

Employee** make_employees(int count);
void print_employees(Employee **employees, int count);

Employee** shallow_copy(Employee **employees, int size);
Employee** deep_copy(Employee **employees, int size);
void deallocate(Employee **employees, int size);
char rand_char();

#endif
