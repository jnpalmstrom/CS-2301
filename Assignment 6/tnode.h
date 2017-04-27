/** File: tnode.h
 * Struct to define a Tnode, each holds a c-style string, and pointers to left and right child Tnodes
 * @author Jack Palmstrom
 */

struct tnode{
  char* data;
  struct tnode* left_ptr;
  struct tnode* right_ptr;
};

typedef struct tnode Tnode;



// Function Prototypes
Tnode* new_tnode(Tnode* node, char* value);
Tnode* add_tnode(Tnode* current_tnode, char* value);
void traverse_tree(Tnode* root_node);
void free_tnodes(Tnode* root_node);
