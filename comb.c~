#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Functions List:
/ - buildTree()
/ - buildAND()
/ - buildOR()
/ - buildNOT()
/ - buildDECODER()
/ - buildMUX()
/ - main()
*/

/* Make sure this shit works !
/ Need a method for interpreting circuit lines
/ Needs to run a loop analyzing circuit line by line
/ Recursive might be a good idea?
/ Recursion require Circuits to be in order. 
*/

// buildTree takes in a FILE input stream and translates it into a tree
/*struct tree * buildTree(FILE * circuit)
{
  struct tree* circuitTree = malloc(sizeof(struct tree));
  circuitTree->root = NULL;
  circuitTree->count = 0;
  return circuitTree;
  }*/

/struct tree * buildTree(FILE* circuit)
{
  struct tree * theTree= malloc(sizeOf(struct tree));
  char line[100];
  if(fgets(line, sizeOf line, circuit)!=NULL)
    {
      tree = buildTree(circuit);
    }
  else
    {
      return tree;
    }
  if(tree->root == NULL)
    {
      struct node * root = buildGATE(circuit);
      tree->root = root;
      return tree;
    }
  tree = insert(tree, circuit);
}

struct tree * insert(tree * tree, FILE * circuit)
{
  struct node * addNode = buildGATE(
}

struct node * buildGATE(char *line[])
{
   switch(line[0])
    {
    case 'A':
      struct node * gate = malloc(sizeOf(struct node));
      struct node * gateL = malloc(sizeOf(struct node));
      struct node * gateR = malloc(sizeOf(struct node));
      gate->name = line[8];
      printf("%c", line[8]);
      gate->type = "AND";
      gateL->name = line[4];
      gateR->name = line[6];
      gate->left = gateL;
      gate->right = gateR;
      break;
    case 'O':
      struct node * gate = malloc(sizeOf(struct node));
      struct node * gateL = malloc(sizeOf(struct node));
      struct node * gateR = malloc(sizeOf(struct node));
      gate->name = line[7];
      printf("%c", line[7]);
      gate->type = "OR";
      gateL->name = line[3];
      gateR->name = line[5];
      gate->left = gateL;
      gate->right = gateR;
      break;
    case 'N':
      struct node * gate = malloc(sizeOf(struct node));
      struct node * gateL = malloc(sizeOf(struct node));
      gate->name = line[8];
      printf("%c", line[8]);
      gate->type = "AND";
      gateL->name = line[4];
      gate->left = gateL;
      break;
    }
   return gate;
}
  /*
struct tree * buildTreeOLD(FILE * circuit, tree * theTree)
{
  char line[100];
  if(fgets(line, sizeOf line, circuit)!=NULL)
    {
      return 0;
    }
  buildTree(circuit, theTree);
  switch(line[0])
    {
    case 'A':
      struct node * gate = malloc(sizeOf(struct node));
      struct node * gateL = malloc(sizeOf(struct node));
      struct node * gateR = malloc(sizeOf(struct node));
      gate->name = line[8];
      printf("%c", line[8]);
      gate->type = "AND";
      gateL->name = line[4];
      gateR->name = line[6];
      gate->left = gateL;
      gate->right = gateR;
      break;
    case 'O':
      struct node * gate = malloc(sizeOf(struct node));
      struct node * gateL = malloc(sizeOf(struct node));
      struct node * gateR = malloc(sizeOf(struct node));
      gate->name = line[7];
      printf("%c", line[7]);
      gate->type = "OR";
      gateL->name = line[3];
      gateR->name = line[5];
      gate->left = gateL;
      gate->right = gateR;
      break;
    case 'N':
      struct node * gate = malloc(sizeOf(struct node));
      struct node * gateL = malloc(sizeOf(struct node));
      gate->name = line[8];
      printf("%c", line[8]);
      gate->type = "AND";
      gateL->name = line[4];
      gate->left = gateL;
      break;
    }

  if()
  
}
  */

/* Build Convention
/ C = A * B
/ Syntax: buildAND(A,B,C);
/      C
/    /   \
/   A     B
*/


/*struct node * buildAND(node * A, node * B, node * C)
{
  C->type = "AND";
  C->left = A;
  C->right = B;
  return C;
  }*/

/* Build Convention
/ C = A + B
/ Syntax: buildOR(A,B,C);
/      C
/    /   \
/   A     B
*/
/*struct node * buildOR(node * A, node * B, node * C)
{
  C->type = "OR";
  C->left = A;
  C->right = B;
  return C;
  }*/

/* Build Convention
/ B = A'
/ Syntax: buildNOT(A,B);
/     B
/    /   
/   A     
*/
/*struct node * buildNOT(node * A, node * B)
{
}*/

// Reminder: Redefine Inputs
/*struct node * buildDECODER(node * A, node * B, node *C)
{
}*/

// Reminder: Redefine Inputs
/*struct node * buildMUX(node * A, node * B, node *C)
{
}*/

int main(int argc, char *argv[])
{
  //To Do list:
  //Check for valid arg
  //Create File
  //Open Files
  //build a tree
  //plant trees
  //water trees
  //pull weeds
  //Have methods do all the work
  //sleep forever
  FILE * theCircuit;
  FILE * theInput;
  theCircuit = fopen(argv[1], "r");
  theInput = fopen(argv[2], "r");
  struct tree * theTree = malloc(sizeOf(struct tree));
  theTree = buildTree(theCircuit);
}
