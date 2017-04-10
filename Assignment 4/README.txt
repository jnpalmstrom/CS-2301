Name: Jack Palmstrom
Date: 4/10/2017
Class: CS2301
Section: D03

Brief Description of Each Program:

	sorttest: Takes numbers inputted on the command line and stores them into an array. It then prints the unsorted array.
		  The program sorts the array and prints the newly sorted array. An initial timestamp is taken right before the
		  array is sorted and another one is taken directly after the sorting. Both these timestamps are printed. The
		  difference between the two timestamps is found and then printed to show the elapsed time for the sorting of
		  the array.

	sorttest2: This program takes an initial count inputted on the command line as well as a logic 0 or 1 identifying which
		   sort method to use. It then generates the amount of random numbers to store into an array based on the count.
		   It then prints the unsorted array. Based on which sorting method you choose to use, the array is then sorted
		   by either array indexing or pointer incrementing for loops. The program sorts the array and prints the newly
		   sorted array. An initial timestamp is taken right before the array is sorted and another one is taken directly
		   after the sorting. Both these timestamps are printed. The difference between the two timestamps is found and
		   then printed to show the elapsed time for the sorting of the array.

Instructions on How to Compile and Link Programs:

	sorttest: Use make to compile the program and create the executable ctest.
	       Use ./sorttest n1 n2 n3 ... 

	sorttest2: Use make to compile the program and create the executable ctest.
	       Use ./sorttest2 n1 n2
	       **n1 specifies the count
	       **n2 is 0 for pointer incrementation sort method
	       	       1 for array indexing sort method

Test Data:

	sorttest:
		Input: 1 2 3 4 5
		Output: 5 4 3 2 1
		Elasped Time: 0 seconds 0 milliseconds

		Input: 8 9 1 3 2 4 5 7 6
		Output: 9 8 7 6 5 4 3 2 1
		Elapsed Time: 0 seconds 1 milliseconds
		
	
	sorttest2: Input: 250 0
		   Elapsed Time: 0 seconds 175 microseconds

		   Input: 250 1
		   Elapsed Time: 0 seconds 186 microseconds

		   Input: 1000 0
		   Elasped Time: 0 seconds 2682 microseconds

		   Input: 1000 1
		   Elapsed Time: 0 seconds 2539 microseconds

		   Input: 10000 0
		   Elasped Time: 0 seconds 273103 microseconds

		   Input: 10000 1
		   Elapsed Time: 0 seconds 281304 microseconds
