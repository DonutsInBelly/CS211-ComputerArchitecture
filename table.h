#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#ifndef TABLE_H
#define TABLE_H

typedef struct node
{
  intmax_t val;
  struct node *next;
}node;

typedef struct list
{
  struct node *head;
  struct node *tail;
  int size;
}list;

typedef struct table
{
  struct list* hTable;
  int unique;
  int tableSize;
}table;

//void createList(struct list **resultList);
struct list * spawnList();
struct table * spawnTable(int tableSize);
//void insert(int val, struct list *listm);
//void insertEnd(int val, struct list *listm);
//void delete(int val, struct list *listm);
void printList(struct list *listm);
void hash(intmax_t val, struct table *theTable);

#endif
