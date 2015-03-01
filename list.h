#include <stdio.h>
#include <stdlib.h>

#ifndef LIST_H
#define LIST_H

typedef struct node
{
  int val;
  struct node *next;
}node;

typedef struct list
{
  struct node *head;
  struct node *tail;
  int size;
}list;

void createList(struct list **resultList);
struct list spawnList();
void insert(int val, struct list *listm);
void delete(int val, struct list *listm);
void printList(struct list *listm);

#endif
