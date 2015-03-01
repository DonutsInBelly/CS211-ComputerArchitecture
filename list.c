#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void createList(struct list **resultList)
{
  // Creates an empty list for the argument to point to
  struct list* listm = malloc(sizeof(struct list));
  // initializes the head, tail, and size of list
  listm->size = 0;
  listm->head = NULL;
  listm->tail = NULL;
  // Argument points to empty list here
  *resultList=listm;
}

struct list * spawnList()
{
  struct list* listm = malloc(sizeof(struct list));
  listm->size = 0;
  listm->head = NULL;
  listm->tail = NULL;
  return listm;
}

void insert(int val, struct list *listm)
{
  struct node *nodeAdd = malloc(sizeof(struct node));
  nodeAdd->val = val;
  nodeAdd->next = NULL;
  listm->size++;

  if(listm->head == NULL)
    {
      nodeAdd->next = NULL;
      listm->head= nodeAdd;
      listm->tail= nodeAdd;
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
	      return;
	    }
	  else
	    {
	      prev->next = nodeAdd;
	      nodeAdd->next=cur;
	      return;
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
	      return;
	    }
	  else
	    {
	      prev=cur;
	      cur=cur->next;
	    }
	}
    }
}

void delete(int val, struct list *listm)
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
}

void printList(struct list *listm)
{
  struct node *cur = listm->head;

  do{
      printf("%d\n", cur->val);
      cur=cur->next;
  }while(cur!=listm->tail);
}

int main(int argc, char *argv[])
{
 
  /* struct list theList;
     createList(theList);*/

  struct list * myList = spawnList();
  insert(10, myList);
  insert(14, myList);
  insert(9, myList);
  insert(20, myList);
  insert(50, myList);
  printList(myList);
}
