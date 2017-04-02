// Name: Jack Palmstrom
// Username: jnpalmstrom

// -------------------------------------------------------------- Header Files --------------------------------------------------------------------------- //
#include <stdio.h>
#include <stdlib.h>
// ------------------------------------------------------------------------------------------------------------------------------------------------------- //

int main(int argc, const char* argv[]) {
	int n;                                                                  // Integer read from the command line goes here.
	
	if (argc < 2) {                                                         // Check that there was an entry
		printf("Must enter a number on the command line!\n");
		return 1;                                                       // Indicate failure
	}

	n = atoi(argv[1]);                                                      // Get string from the command line; convert to int


        // Check if this year is within the range which this program is designed to handle.
	if (n < 1752) {
	  printf("This program cannot test the year %d. It only handles the year 1752 and after.\n", n); // Error message
	}
        
        if ((n % 400) == 0) {                                                   // Checks that the year meets the initial requirement for being a leap year.
	  printf("The year %d you entered is a leap year.\n", n);
	}
	else if((n % 100) == 0) {                                               // Checks that the year is not divisible by both 400 and 100
	  printf("The year %d you entered is not a leap year.\n", n);
	}
	else if ((n % 4) == 0) {                                                // If the program passes the last comparison it is a leap year.
	  printf("The year %d you entered is a leap year.\n", n);
	}
	return 0;                                                               // Success
}
