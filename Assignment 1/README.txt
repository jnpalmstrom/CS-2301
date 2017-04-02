Name: Jack Palmstrom
Date: 3/17/2017
Class: CS2301
Section: D03

Brief Description of Each Program:

	lab1: This program prints an initial Hello World statement. Then, this program prints the numbers 1 to 15, each on a new line. It finally prints
    	      a Goodbye statement.   	

	num: This program takes in grades from the command shell. The program first checks whether any grades were inputted on the command line. 
	     Then, these grades are taken from the command line and converted into integers where they are stored into an array. The average function 
             is then called with the new array of grades and the number of grades in the array.

	leap: This program takes in a given year from the command shell. The program first checks that enough inputs were given to the command line 
	      and then converts the input into an int. The program cannot handle years before 1752, it will print an error
	      message. Through a series of if statements the inputted year is evaluated whether it is a leap year. It then prints the result.

Instructions on How to Compile and Link Programs:

	lab1: This program can be ran from the command shell with-
			./lab1

	num: This program can be ran from the command shell with-
			./num n1 n2 n3 ... n20
             ** MAX_GRADES is set to 20, no more than 20 grades can be inputted **
	
	leap: This program can be ran from the command shell with-
			./leap n1

Test Data:

	lab1: No test data

	num: 
		1. I tested 1, 2, 3, 4, 5, and it printed that the average is 3. Then printed the min is 1 and the max is 5.
		2. I tested 3, 7, 1, 4, 5, and it printed that the average is 4. Then printed the min is 1 and the max is 7.
		3. I tested 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 and it printed that the average is 10. Then printed the min is 1 and the max is 20.
		4. I tested 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21. Then it prints an error and it printed that the average is 10. 
		   Then printed the min is 1 and the max is 20.		

	leap: 
		1. I tested 1900, and it printed that it was not a leap year.
		2. I tested 2000, and it printed that it was a leap year.
		3. I tested 2020, and it printed that it was a leap year.
		4. I tested 2100, and it printed that it was not a leap year.
		5. I tested 100, and it printed an error message.



