/** File: tnode.c
 * File which holds implementation of tnode functions for a binary tree data structure implementation
 * @author Jack Palmstrom
 */

// Name: Jack Palmstrom
// Username: jnpalmstrom

// ------------------- Header File --------------- //
#include <stdio.h>                                 
#include <stdlib.h>                               
#include <string.h>
#include "tnode.h"
// ----------------------------------------------- //



/** Creates a new node for the tree 
 * @param value The string value of the node to be created
 * @return Pointer to the added Tnode
 */
Tnode* new_tnode(Tnode* node, char* value){

  node = (Tnode*) malloc(sizeof(Tnode));
  
  node->data = value;
  node->left_ptr = NULL;
  node->right_ptr = NULL;
  
  return node;
}

/** Adds a tnode to the tree
 * @param current_tnode Pointer to the Tnode to be added to the tree
 * @param value The string value of the node to be added
 */
Tnode* add_tnode(Tnode* current_tnode, char* value){

  if(current_tnode == NULL){                                                  // Allocate a new node if nothing is in pointer
    new_tnode(current_tnode, value); 
  }
  else if(strcmp(current_tnode->data, value) < 0) {                      
    current_tnode->right_ptr = add_tnode(current_tnode->right_ptr, value);    // Add node to right subtree
  }
  else {                                                              
    current_tnode->left_ptr = add_tnode(current_tnode->left_ptr, value);      // Add node to left subtree
  }
}

/** Print values of the tree in descending order
 *  using in-order tree traversal but going to the right 
 *  subnode first then going to the left subnode
 * @param root_node the root node of the tree to be printed
 */
void traverse_tree(Tnode* root_node){

  if(root_node != NULL){
    
    traverse_tree(root_node->right_ptr);
    printf("Node: %s\n", root_node->data);
    traverse_tree(root_node->left_ptr);
  }
  
}

/** Free all nodes from a tree
 * @param root_node Pointer to the root node of the tree
 */
void free_tnodes(Tnode* root_node) {

  if(root_node != NULL){

    // Free left sub node before the right 
    if(root_node->left_ptr != NULL){     
      free_tnodes(root_node->left_ptr);
    }
    
    if(root_node->right_ptr != NULL){    
      free_tnodes(root_node->right_ptr);
    }
    
    free(root_node);                    
  }
}
