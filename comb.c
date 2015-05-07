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
struct tree * buildTree(FILE* circuit)
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

int main(int argc, char *argv[])
{
  FILE * theCircuit;
  FILE * theInput;
  theCircuit = fopen(argv[1], "r");
  theInput = fopen(argv[2], "r");
  struct tree * theTree = malloc(sizeOf(struct tree));
  theTree = buildTree(theCircuit);
}
