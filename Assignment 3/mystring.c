/** mystring.c
 * @author Mike Ciaraldi
 * My own versions of some of the C-style string functions
*/

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ----------------- Header Files --------------------------------- //
#include <string.h>
#include <stdlib.h>
// Have to #include stdlib.h because it is needed to use malloc()
#include "mystring.h"
// ---------------------------------------------------------------- //

// ----------------- CONSTANTS ------------------------------------ //
#define MAX_WORD (25)
// ---------------------------------------------------------------- //

/** Duplicates a C-style string.
 @param src Pointer to string to be copied
 @return Pointer to freshly-allocated string containing a duplicate of src
         or null if no memory is available
*/

char* mystrdup(const char* src) {

  int length;                                // Length of the source string
  char* newstr;                              // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;                // Leave space for the terminator
  newstr = (char*) malloc(length);           // Must cast!

  // If no memory was available, return null pointer immediately
  if (newstr == 0) return (char *) 0;

  // Otherwise, copy the string and return pointer to new string
  mystrcpy(newstr, src);
  return newstr;
}

/** Duplicates a C-style string up to n characters. If s is longer than n, only n characters are copied, and a '/0' is added. malloc() and free() are used to obtain memory for the new string.
 * @param s Pointer to the string to be duplicated
 * @param n the number of characters to be duplicated from s
 * @return Pointer to the string duplicate
 */
char *mystrndup(const char *src, size_t n) {

  int length;                                // Length of the source string
  char* newstr;                              // Pointer to memory which will hold new string

  length = mystrlen(src) + 1;                  // Leave space for terminator
  newstr = (char*) malloc(length);           // Allocate memory for newstr

  // If no memory available, return null pointer
  if (newstr == 0) {
    return (char *) 0;
  }
  
  // Otherwise, copy string up through n chars and return pointer to new string
  else {
    mystrncpy(newstr, src, n);
    *(newstr + length) = '\0';
    return newstr;
  }
}


/** Calculates the length of a string.
    @param s Pointer to string to find length of 
    @return Int to represent number of bytes in string s,
            excluding NULL character
*/

int mystrlen(const char *s) {

  int length;                         // Length of the source string
  char temp;                          // Current char in the array of characters

  length = 0; 
  temp = *s;

  while(temp != '\0'){
    length++;                         // Increment length
    temp = *(++s);                    // Move to next character in array
  }
  return length;  
}


/** Copy a string
    @param dest Pointer to destination string  
    @param src Pointer to string to be copied
    @return Pointer to freshly-allocated string containing a duplicate of src
            or NULL if no memory is available 
*/

char* mystrcpy(char *dest, const char *src) {

  char* first; 
  first = dest;                        // Stores the first place in memory

  while(*src != '\0'){
    *dest = *src;                      // Copy chars from src to dest
    src++;
    dest++;
  }
  
  *dest = *src;                        // Run one more time to include the null character
  return first;                        // Return pointer to first char of dest
}

/** Copy a string
    @param dest Pointer to destination string  
    @param src Pointer to string to be copied
    @param n The number of characters to be copied
    @return Pointer to freshly-allocated string containing a duplicate of src
            or NULL if no memory is available 
*/

char* mystrncpy (char *dest, const char *src, size_t n) {

  char* first;
  int i, length;
  
  first = dest;                        // Stores first memory location of dest
  length = mystrlen(src);              // Length of src string

  for(i = 0; i < n; i++){

    if(i > length) {                   // NULL pad
      *dest = '\0';
      dest++;
    }
    
    else {
      *dest = *src;                    // Copy chars from src to dest
      dest++;
      src++;
    }
  }
  return first;                        // Return pointer to first char of dest
}

/** Appends the src string to the dest string over-writing the '/0' character at the end of dest, 
    then adds a '/0' back on to the end of the resulting string. dest string must have ebough space for result.
* @param dest Pointer to the first string of the concatenation, which becomes the result afterwards
* @param src Pointer to the string to be added onto the end of dest
* @return dest Pointer to the concatenated string
*/
char* mystrcat(char *dest, const char *src) {

  int length; 
  char* first;
  char* insert;                        // Pointer to position of string we're inserting at
  
  first = dest;                        // Store memory location of first position of the first string
  length = mystrlen(dest);             // Length of the destination string
  insert = dest + length;              // Set insert position to end of first string

  while(*src != '\0'){
    *insert = *src;                    // Copy chars from src onto end of dest string
    insert++; 
    src++;
  }
  
  *insert = *src;                      // Run one more time to tack on the null-terminating character
  return first;                        // Return pointer to the start of the resulting string
}






/** Appends the first n characters, plus a '/0' character from src onto the end of dest, overwriting the '/0' of dest.
 * @param dest Pointer to the first string of concatenation, which becomes the result afterwards
 * @param src Pointer to the string to be added onto the end of dest
 * @param n the amount of characters from src to concatenate onto dest
 * @return dest Pointer to the concatenated string
 */
char* mystrncat(char *dest, const char *src, size_t n) { 

  int j, length;
  char* first;
  char* insert;                       // Pointer to position of string we're inserting at
  
  first = dest;                       // Store memory location of first position  of the first string
  length = mystrlen(dest);            // Length of the destination string
  insert = dest + length;             // Set insert position to end of first string

  for(j = 0; j < n; j++){

    if(j > length){                   // Stop adding on if we reach end of string
      break;
    }
    
    *insert = *src;                   // Copy chars from src onto back of destination string
    insert++; 
    src++;
  }
  return first;                       // Return pointer to first position of resulting string 
}
