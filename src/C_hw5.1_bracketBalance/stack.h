#include <stdlib.h>



typedef struct StackBlock {
    char value;
    struct StackBlock *next;
} Block;




Block* newStack(void);

Block* push(Block *top, char value);


Block* pop(Block *top);


char peek(Block *top);


void show(Block *top);


void deleteStack(Block *top);