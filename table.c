#include <stdio.h>
#include <stdlib.h>
#include "table.h"

/*void createList(struct list **resultList)
{
  // Creates an empty list for the argument to point to
  struct list* listm = malloc(sizeof(struct list));
  // initializes the head, tail, and size of list
  listm->size = 0;
  listm->head = NULL;
  listm->tail = NULL;
  // Argument points to empty list here
  *resultList=listm;
  }*/

struct list * spawnList()
{
  struct list* listm = malloc(sizeof(struct list));
  listm->size = 0;
  listm->head = NULL;
  listm->tail = NULL;
  return listm;
}

struct table * spawnTable(int tableSize)
{
  struct table* theTable = malloc(sizeof(struct table));
  theTable->hTable = malloc(sizeof(struct list)*tableSize);
  for(int iter = tableSize-1; iter>=0; iter--)
    {
      theTable->hTable[iter].head = NULL;
    }
  theTable->unique = 0;
  theTable->tableSize = tableSize;
  return theTable;
}

/*
void insert(int val, struct list *listm)
{
  struct node *nodeAdd = malloc(sizeof(struct node));
  nodeAdd->val = val;
  nodeAdd->next = NULL;
  listm->size++;

  // If the list is empty
  if(listm->head == NULL)
    {
      nodeAdd->next = NULL;
      listm->head= nodeAdd;
      listm->tail= nodeAdd;
      return;
    }
  struct node *cur = listm->head;
  struct node *prev = NULL;
  while(cur!=NULL)
    {
      // if the new value is lower or equal
      // Insert before
      if(cur->val >= nodeAdd->val)
	{
	  if(prev==NULL)
	    {
	      nodeAdd->next = cur;
	      listm->head=nodeAdd;
	      break;
	    }
	  else
	    {
	      prev->next = nodeAdd;
	      nodeAdd->next=cur;
	      break;
	    }
	}
      // if the new value is higher
      // Insert after if the pointer hits the Tail
      // Otherwise, Insert before should take care of most cases
      // Most of the time, the cur will increment here
      else if(cur->val < nodeAdd->val)
	{
	  if(cur->next==NULL)
	    {
	      cur->next=nodeAdd;
	      listm->tail=nodeAdd;
	      listm->size++;
	      break;
	    }
	}
      prev=cur;
      cur=cur->next;
    }
  return;
  }*/
/*
void insertEnd(int val, struct list *listm)
{
  struct node *nodeAdd = malloc(sizeof(struct node));
  nodeAdd->val=val;
  nodeAdd->next=NULL;
  if(listm->head==NULL)
    {
      listm->head=nodeAdd;
      listm->tail=nodeAdd;
      listm->size++;
      return;
    }
  else
    {
      listm->tail->next=nodeAdd;
      listm->tail=nodeAdd;
      listm->size++;
      return;
    }
    }*/

/*void delete(int val, struct list *listm)
{
  if(listm->head == NULL)
    {
      return;
    }
  struct node *cur = listm->head;
  struct node *prev = NULL;
  if(listm->head->val = val)
    {
      if(listm->head==listm->tail)
	{
	  free(listm->head);
	  listm->head=NULL;
	  listm->tail=NULL;
	  listm->size--;
	  return;
	}
      free(listm->head);
      listm->head=listm->head->next;
      listm->size--;
      return;
    }
  while(cur!= NULL)
    {
      // For any node with the target value
      if(cur->val==val)
	{
	  // If Statement to catch if tail node is target node
	  if(cur==listm->tail)
	    {
	      free(listm->tail);
	      prev->next=NULL;
	      listm->tail=prev;
	      listm->size--;
	      return;
	    }
	  // General Node deletion		 
	  prev->next = cur->next;
	  free(cur);
	  listm->size--;
	  return;
	}
      // Moves cur and prev up the linked list
      prev=cur;
      cur=cur->next;
    }
  return;
  }*/

void printList(struct list *listm)
{
  struct node *cur = listm->head;

  do{
      printf("%lx\n", cur->val);
      cur=cur->next;
  }while(cur!=NULL);
  return;
}


void hash(intmax_t val, struct table *theTable)
{
  struct node *nodeAdd = malloc(sizeof(struct node));
  nodeAdd->next = NULL;
  int key = val%theTable->tableSize;
  //if list is empty at key index
  if(theTable->hTable[key].head==NULL)
    {
      theTable->hTable[key].head = nodeAdd;
      theTable->hTable[key].tail = nodeAdd;
      theTable->hTable[key].size++;
      theTable->unique++;
      return;
    }
  else
    {
      //if the val is in the head of the list
      if(theTable->hTable[key].head->val==nodeAdd->val)
	{
	  free(nodeAdd);
	  return;
	}
      //if list exists and chaining must occur
      //First case: if the only node in the list is the head
      if(theTable->hTable[key].head==theTable->hTable[key].tail)
	{
	  theTable->hTable[key].head->next = nodeAdd;
	  theTable->hTable[key].tail = nodeAdd;
	  theTable->hTable[key].size++;
	  theTable->unique++;
	}
      //Second case: for all general nodes
      struct node *cur = theTable->hTable[key].head;
      struct node *prev = NULL;
      do{
	  //Checks if the val exists later in the list
	  if(cur->val==nodeAdd->val)
	    {
	      free(nodeAdd);
	      return;
	    }
	  //adds val to end of list
	  if(cur->next==NULL)
	    {
	      cur->next = nodeAdd;
	      theTable->hTable[key].tail = nodeAdd;
	      theTable->hTable[key].size++;
	      theTable->unique++;
	      return;
	    }
	  //iterates through list
	  prev=cur;
	  cur=cur->next;
      }while(cur!=NULL);
    }
}


int main(int argc, char *argv[])
{
  FILE * theText;
  if(argv[1] == NULL)
    {
      printf("%s\n", "error");
      return 0;
    }
  theText = fopen(argv[1], "rt");
  struct table * myTable = spawnTable(1000);
  char line[100];
  while(fgets(line, sizeof line, theText)!=NULL)
    {
      //printf("%s\n", line);
      intmax_t * hex;
      //printf("%ld\n", strtoimax(line, &hex, 0));
      hash(strtoimax(line, &hex, 0), myTable);
      //sscanf(line, "0x%"SCNx64, &hex);
      //printf("%"PRIx64"\n", *hex);
      //printf("%"PRId64"\n", *hex);
    }


  /* For testing how many are in each linked list of the Hash Table*/
  /*for(int iter = 0; iter <1000; iter++)
    {
      printf("%d\n", myTable->hTable[iter].size);
    }
  */

  /* For testing whats in the linked lists within the Hash Table */
  for(int iter = 0; iter <1000; iter++)
    {
      printList(myTable->hTable[iter]);
    }
  printf("%d\n", myTable->unique);
  return 0;
}
