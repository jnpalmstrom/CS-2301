/** File: tnodetest.c
 * File which tests adding strings to a binary tree, which sorts them into ascending order, then traverses the tree and prints the strings in-order 
 * @author Jack Palmstrom
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ---------------- Header Files --------------- //
#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"
// --------------------------------------------- //
/*
void print_dataset(char* dataset[]) {

  int index, count;

  index = 0;
  count = 1;

  printf("The following is the order the elements are added to the tree...\n");
  while (dataset[index] != NULL) {

    printf("Element %d: %s\n", count, dataset[index]);
    count++;
    index++;
  }
  
}
*/

int main() {
  
    Tnode* root_node;
    Tnode* tree;
    char *dataset1[] = {"A" , "B", "C", "D" , "E", "F"};
    char *dataset2[] = {"F" , "E", "D", "C" , "B", "A"};
    char *dataset3[] = {"B" , "A", "D", "C" , "F", "E"};

    printf("\n");
    printf("The following is the order the elements are added to the tree for dataset1...\n");
    printf("Element 1: %s\n", dataset1[0]);
    printf("Element 2: %s\n", dataset1[1]);
    printf("Element 3: %s\n", dataset1[2]);
    printf("Element 4: %s\n", dataset1[3]);
    printf("Element 5: %s\n", dataset1[4]);
    printf("Element 6: %s\n", dataset1[5]);
    
    root_node = NULL;
    tree = add_tnode(root_node, dataset1[0]);
    add_tnode(tree, dataset1[1]);
    add_tnode(tree, dataset1[2]);
    add_tnode(tree, dataset1[3]);
    add_tnode(tree, dataset1[4]);
    add_tnode(tree, dataset1[5]);

    printf("\n");
    printf("The tree nodes for dataset1 are printed in descending order:\n");
    traverse_tree(tree);
    printf("\n");
    free_tnodes(tree);
    // End of dataset1

    // Start of dataset2
    printf("The following is the order the elements are added to the tree for dataset2...\n");
    printf("Element 1: %s\n", dataset2[0]);
    printf("Element 2: %s\n", dataset2[1]);
    printf("Element 3: %s\n", dataset2[2]);
    printf("Element 4: %s\n", dataset2[3]);
    printf("Element 5: %s\n", dataset2[4]);
    printf("Element 6: %s\n", dataset2[5]);

    root_node = NULL;
    tree = add_tnode(root_node, dataset2[0]); 
    add_tnode(tree, dataset2[1]);
    add_tnode(tree, dataset2[2]);
    add_tnode(tree, dataset2[3]);
    add_tnode(tree, dataset2[4]);
    add_tnode(tree, dataset2[5]);

    printf("\n");
    printf("The tree nodes for dataset2 are printed in descending order:\n");
    traverse_tree(tree);
    printf("\n");
    free_tnodes(tree);
    // End of dataset2
    
    // Start of dataset3
    printf("The following is the order the elements are added to the tree for dataset3...\n");
    printf("Element 1: %s\n", dataset3[0]);
    printf("Element 2: %s\n", dataset3[1]);
    printf("Element 3: %s\n", dataset3[2]);
    printf("Element 4: %s\n", dataset3[3]);
    printf("Element 5: %s\n", dataset3[4]);
    printf("Element 6: %s\n", dataset3[5]);
    
    root_node = NULL;
    tree = add_tnode(root_node, dataset3[0]);
    add_tnode(tree, dataset3[1]);
    add_tnode(tree, dataset3[2]);
    add_tnode(tree, dataset3[3]);
    add_tnode(tree, dataset3[4]);
    add_tnode(tree, dataset3[5]);

    printf("\n");
    printf("The tree nodes for dataset3 are printed in descending order:\n");
    traverse_tree(tree);
    printf("\n");
    free_tnodes(tree);
    // End of dataset3
}
