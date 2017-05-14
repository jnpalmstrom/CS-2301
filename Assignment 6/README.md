Name: Jack Palmstrom
Date: 4/23/2017
Class: CS2301
Section: D03

Brief Description of Each Program:

      stacktest:
	This program implements a stack system which allows you all the same functionalities as a real stack. This program demonstrates functions
	such as push(), pop(), and peek(). This program checks what happens to the stack when pushing elements onto the stack, then popping off
	elements, and pushing more elements back on. Then it checks what occurs when presented with an overflow. The program also demonstates how
	it deals with being asked to pop off more elements than are in the stack.


      queuetest:
	This program implements a queue system which lets you create multiple queues that hold pointers. This program uses functions
	create_queue(), enqueue(), dequeue() along with the struct queue in order to simulate the work of the actual queue. The struct
	queue includes data regarding the size, head and tail pointers, as well as the location of the queue buffer in memory. This program
	thoroughly tests the queue in order to check for that pointers correctly wraps around when the end of the array that holds the pointers
	is met. Testing on the queue also extends to correctly handling cases of overflow or underflow. 


      tnodetest:
	This program implements the tree sort algorithm by defining a struct Tnode which holds a piece of data as well as pointers to the left and
	right children for the current node. This program tests the implementation of tree sort on the created tree. The program checks that as each
	element on the tree is added during the sort, it is put in the correct spot in the tree so that when traversing the tree, each node is visited
	in sorted order.

      tnoderandom:
	This program builds off of the program tnodetest listed above. However, this program generates random strings to be added to the tree. The program
	tests the sorting of the tree sort on the tree with the same scrutiny as the program tnodetest.


Instructions on How to Compile and Link Programs:

        **On a Linux OS, open up the terminal and navigate to correct directory. Run make in order to create the executable programs listed here.** 
				   
	stacktest: To run use ./stacktest on the command line after compiling.


        queuetest: To run use ./queuetest on the command line after compiling.


        tnodetest: To run use ./tnodetest on the command line after compiling.


        tnoderandom: To run use ./tnoderandom on the command line after compiling.
