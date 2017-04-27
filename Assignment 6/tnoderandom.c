/** File: tnoderandom.c
 * File that creates a binary tree of randomly generated strings,
 * then prints out the strings sorted in descending order
 * @author Jack Palmstrom
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ------------------- Header File --------------- //
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tnode.h"
// ----------------------------------------------- //

/** Generates a random string of inputted size
 * @param size The total size of the generated random string
 * @return Pointer to the character array for the string
 */
char* rand_str_gen(int size) {

  int index, count;
  const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *string = NULL;
 
  if (size) {
    
    string = malloc(sizeof(char) * (size + 1));
    
    for(count = 0; count < size; count++) {

      index = rand() % (int)(sizeof alphabet);
      string[count] = alphabet[index];
    }
    string[size] = '\0';
  }
  return string;
}
 
int main() {

  // Reset random number seed @ start of program
    srand(time(NULL)); 

    Tnode* root_node;
    root_node = NULL;

    printf("\n");
    printf("Randomly generated strings:\n");

    // Create 6 randomly generated strings
    char* str1 = rand_str_gen(6); // Random string #1
    char* str2 = rand_str_gen(6); // Random string #2 
    char* str3 = rand_str_gen(6); // Random string #3
    char* str4 = rand_str_gen(6); // Random string #4
    char* str5 = rand_str_gen(6); // Random string #5
    char* str6 = rand_str_gen(6); // Random string #6

    // Print the randomly generated strings
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("String 3: %s\n", str3);
    printf("String 4: %s\n", str4);
    printf("String 5: %s\n", str5);
    printf("String 6: %s\n", str6);

    // Add the strings to the tree
    Tnode* tree; 
    tree = add_tnode(root_node, str1);
    add_tnode(tree, str2);
    add_tnode(tree, str3);
    add_tnode(tree, str4);
    add_tnode(tree, str5);
    add_tnode(tree, str6);

    // Traverse and print the tree in descending order
    printf("\n");
    printf("Printing descending order traversal of tree...\n");
    traverse_tree(tree);
    printf("\n");

    //Free nodes from tree
    free_tnodes(tree);                        
}
