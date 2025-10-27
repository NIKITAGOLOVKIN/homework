#include <stdlib.h>


typedef struct ListBlock {
    int value;
    struct ListBlock *next;
} ListBlock;


ListBlock* newList(void);


ListBlock* insertValue(ListBlock *p, int value);


ListBlock* removeValue(ListBlock *p, ListBlock *t);


void printList(ListBlock *p);


void deleteList(ListBlock *p);