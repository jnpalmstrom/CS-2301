Name: Jack Palmstrom
Date: 4/03/2017
Class: CS2301
Section: D03

Brief Description of Each Program:

	ctest:

	There were two main parts of assigment 3: making our own C library string functions, and working with structs. The file mystring.c holds all the source code
	for my own versions of C library string functions such as strdup(), strndup(), strlen(), strcpy(), strncpy(), strcat(), and strncat().  It will output two big chunks
	of data with string manipulations explained. The first chunk uses the standard library functions and the second chunk uses my functions. The two outputs are intended
	to be basically equal to demonstrate expected function behavior. 

	The second part of the assignment can be found in the account.h, and account.c files. These functions revolve around the struct of a bank account with name,
	account_number, and dollars as it's attributes. There are functions for creating an account from data, creating an account with randomly generated data, populating
	an array of pointers that all point to account structs, and printing both accounts and arrays of pointers to accounts. There are also two functions: shallow_copy()
	and deep_copy() for copying arrays of account struct data. . The latter half of the output is for this section of the assignment. The last function that happens,
	but may be difficult to see is the deallocate() function which frees the pointers of their struct values. 


Instructions on How to Compile and Link Programs:

	ctest: Use make to compile the program and create the executable ctest.
	       Use ./ctest from the command line to run the executable.

Test Data:

	ctest: N/A (Doesn't rely on input from the command line.)

