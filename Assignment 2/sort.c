/** file sort.c
 * @author Jack Palmstrom
 *
 * Program to sort arrays and generate random integers .
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom
// Date: 3/27/2017

// --------------------- Header Files -------------------------------- //
                                                                       //
#include <stdlib.h>                                                    //
// ------------------------------------------------------------------- //

// --------------------- CONSTANTS ----------------------------------- //
//                                                                     //
#define MAX_RANDOM_INT (10)                                            //
// ------------------------------------------------------------------- //

/**
 * sorts the given array of integers into ascending order using bubble sort
 * @param array Array of integers to be sorted
 * @param num_elements total number of elements in the array
 */

void bubble_sort(int a[], int num_elements) {

  int i, j, temp;
  
  for(i = 0; i < num_elements; i++){
    
    for(j = 0; j < num_elements; j++){
      
      if(a[i] < a[j]){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
}

/**
 * generates a random integer from 0 to max inclusive
 * @param max the largest possible number returned 
 * @return the generated random integer
 */
int gen_random(int max){
  
  int rand_gen; //the random integer to be generated
  
  rand_gen = rand() % (max + 1); //generate random int between 0 and max inclusive
  return rand_gen;
}

/**
 * populates an array with random integers
 * @param a the Array to be filled
 * @param num_elements the length of the array
 */
void populate_random(int a[], int num_elements){

  int i = 0;

  for(i; i < num_elements; i++){
    
    a[i] = gen_random(MAX_RANDOM_INT);
    
  }
}
