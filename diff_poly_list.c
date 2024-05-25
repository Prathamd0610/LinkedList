#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
    int var;
    int coeff;
    struct linkedlist *next;
}node;