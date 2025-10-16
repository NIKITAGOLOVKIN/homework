#include <stdio.h>
#include <stdlib.h>
#include "stack.h"



Block* newStack(void)
{
    return NULL;
}


Block* push(Block *top, char value)
{
    Block *p = malloc(sizeof(Block));
    p->value = value;
    p->next = top;
    return p;
}


Block* pop(Block *top)
{
    if (top == NULL)
	return top;

    Block *p = top->next;
    free(top);
    return p;
}


char peek(Block *top)
{
    if (top == NULL) {
	return 0;
    }
    else
	return top->value;
}


void show(Block *top)
{
    printf("Стек: \n");
    Block *p = top;
    while (p != NULL) {
	printf("%c\n", p->value);
	p = p->next;
    }
    printf("\n");
}


void deleteStack(Block *top)
{
    while (top != NULL) {
	Block *p = top;
	top = top->next;
	free(p);
    }
    free(top);
    printf("Стек удален\n");
}