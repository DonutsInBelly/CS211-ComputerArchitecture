#include <stdio.h>
#include <stdlib.h>

#ifndef TREEIMP_H
#define TREEIMP_H

struct tree {
int data;
struct tree * right, * left;
};
typedef struct tree node;

#endif
