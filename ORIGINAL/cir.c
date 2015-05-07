#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void buildTree(node **root, node *target)
{
  if(*root == NULL)
    {
      *root = target;
      return;
    }
  if((*root)->name==target->name)
    {
      printf("Node Replaced: %c\nBy Target: %c\n", (*root)->name,target->name);
      *root = target;
      return;
    }
  buildTree(&(*root)->left,target);
  printf("Current Node: %c\n", (*root)->name);
  buildTree(&(*root)->right,target);
}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%c\n",tree->name);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

struct node* createNode(char name)
{
  node *theNode;
  char nameC;
  theNode->name = &nameC;
  theNode->name = name;
  return theNode;
}

struct node* buildNode(char gateStr[])
{
  char gateT = gateStr[0];
  node *gate = malloc(sizeof(struct node));
  if(gateStr[0]=='A')
	{
	  node *gateL = malloc(sizeof(struct node));
	  node *gateR = malloc(sizeof(struct node));
	  gate->name = gateStr[8];
	  printf("%c\n", gateStr[8]);
	  gateL->name = gateStr[4];
	  gateR->name = gateStr[6];
	  gate->left = gateL;
	  gate->right = gateR;
	  printf("Gate Name: %c\nGateLeft: %c\nGateRight: %c\n", gate->name, gate->left->name, gate->right->name);
	}
      else if(gateStr[0]=='O')
	{
	  printf("OR STATEMENT\n");
	  node *gateL = malloc(sizeof(struct node));
	  node *gateR = malloc(sizeof(struct node));
	  char nameC;
	  gate->name = &nameC;
	  gate->name = gateStr[7];
	  printf("name: %c\n", gate->name);
	  //gateL = createNode('G');
	  printf("gateL: %c\n", gateL->name);
	  char typeC;
	  printf("Still OKAY!\n");
	  gate->type = &typeC;
	  printf("Still OKAY!\n");
	  gate->type = '+';
	  printf("type: %c\n", gate->type);
	  char nameL;
	  gateL->name = &nameL;
	  char nameR;
	  gateR->name = &nameR;
	  gateL->name = gateStr[3];
	  gateR->name = gateStr[5];
	  printf("%c\n", gateL->name);
	  printf("%c\n", gateR->name);
	  gate->left = gateL;
	  gate->right = gateR;
	  printf("Gate Name: %c\nGateLeft: %c\nGateRight: %c\n", gate->name, gate->left->name, gate->right->name);
	}
      else if(gateStr[0]=='N')
	{
	  node *gateL = malloc(sizeof(struct node));
	  gate->name = gateStr[8];
	  printf("%c\n", gateStr[8]);
	  gate->type = '_';
	  gateL->name = gateStr[4];
	  gate->left = gateL;
	  printf("Gate Name: %c\nGateLeft: %c\n", gate->name, gate->left->name);
	}
  return gate;
}


//struct node * buildTree(

int main(int argc, char * argv[])
{
  FILE *theCircuit;
  FILE *theInput;
  theCircuit = fopen(argv[1], "r");
  theInput = fopen(argv[2], "r");
  char circuit[100];
  char *allGates[100];
  int input[10];
  int gateCount=0;
  //Creates an Array of Strings for the circuit.txt file
  while(fgets(circuit, sizeof circuit, theCircuit)!=NULL)
    {
      allGates[gateCount] = malloc(sizeof circuit);
      strcpy(allGates[gateCount],circuit);
      printf("%d , %s", gateCount, allGates[gateCount]);
      gateCount++;
    }
  gateCount--;
  int i;
  for(i = 0; i < gateCount; i++) {
        printf("Gate %d: %s\n", i, allGates[i]);
    }
  node *root;
  root = NULL;
  //printf("%d\n",gateCount);
  i = gateCount;
  if(root==NULL)
    {
      printf("YES\n");
    }
  //Builds the tree by sending lines to buildTree()
  while(i!=1)
    {
      printf("Sending line: %d\n", i);
      node *temp = NULL;
      temp = buildNode(allGates[i]);
      buildTree(&root, temp);
      i--;
    }
  print_preorder(root);
}

/*
while(i!=1)
    {
      char *gateStr= allGates[i];
      printf("%s", gateStr);
      if(gateStr[0]=='A')
	{
	  struct node * gate;
	  struct node * gateL;
	  struct node * gateR;
	  gate->name = gateStr[8];
	  printf("%c", gateStr[8]);
	  gate->type ='*';
	  gateL->name = gateStr[4];
	  gateR->name = gateStr[6];
	  gate->left = gateL;
	  gate->right = gateR;
	}
      else if(gateStr[0]=='O')
	{
	  struct node * gate;
	  struct node * gateL;
	  struct node * gateR;
	  gate->name = gateStr[7];
	  printf("%c", gateStr[7]);
	  //gate->type = '+';
	  //gateL->name = gateStr[3];
	  //gateR->name = gateStr[5];
	  //gate->left = gateL;
	  //gate->right = gateR;
	}
      else if(gateStr[0]=='N')
	{
	  struct node * gate;
	  struct node * gateL;
	  gate->name = gateStr[8];
	  printf("%c", gateStr[8]);
	  gate->type = '_';
	  gateL->name = gateStr[4];
	  gate->left = gateL;
	}
      //buildTree(allGates[i]);
      i--;
      }
*/
