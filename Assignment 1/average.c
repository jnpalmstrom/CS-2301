// Name: Jack Palmstrom
// Username: jnpalmstrom

// -------------------------------------------------------------- Header Files --------------------------------------------------------------------------- //
#include <stdio.h>                                                                                        
#include "average.h"
// --------------------------------------------------------------------------- --------------------------------------------------------------------------- //


void average(int grd_array[], int num_elements) {

  int  min = grd_array[1];                           // Set the min grade to the first grade in the grd_array
  int  max = grd_array[1];                           // Set the max grade to the first grade in the grd_array
  int  num_grades = num_elements - 1;                // Creates a variable for the number of grades inputted

    for (j = 1; j < num_elements ; j++) {               // Run through each element in the array adding each element to the total sum of grades

      if (j > MAX_GRADES) {
	printf("The program can only handle %d grades. You provided %d grades.\n", MAX_GRADES, num_grades);
	break;
      }

      sum += grd_array[j];                          

      if (grd_array[j] < min) {                      // Finds if the current array element is less than the min
      min = grd_array[j];
      }
      if (grd_array[j] > max) {                      // Finds if the current array element is greater than the max
        max = grd_array[j];
      }


    }

    avg = sum / (num_elements - 1);                  // Calculates the average of the grades in the array
    printf("The average is %d.\n", avg);
    printf("The min is %d.\n", min);
    printf("The max is %d.\n", max);
  
   
}

