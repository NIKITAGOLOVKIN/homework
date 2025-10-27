#include <stdio.h>
#include "list.h"


ListBlock* newList(void)
{
    return NULL;
}


ListBlock* insertValue(ListBlock *p, int value)
{
    ListBlock *t = malloc(sizeof(ListBlock));
    t->value = value;
    if (p == NULL || t->value >= p->value) {
	t->next = p;
	p = t;
	return p;
    }

    ListBlock *current = p->next;       //если мы дошли до этой строчки, значит мы не вернули ничего в прошлом if
    ListBlock *prev = p;
    while (current != NULL) {
	if (t->value >= current->value) {
	    prev->next = t;
	    t->next = current;
	    return p;
	}
	else {
	    prev = current;
	    current = current->next;
	}
    }

    t->next = current;          //если мы дошли до этой строчки, значит current == NULL и мы не вернули ничего в прошлом while
    prev->next = t;
    return p;
}


ListBlock* removeValue(ListBlock *p, int value)
{
    ListBlock *next = NULL;
    ListBlock *prev = NULL;
    ListBlock *t = p;
    while (t != NULL && t->value != value) {
	prev = t;
	t = t->next;
    }

    if (t == NULL) 
	return p;

    if (prev == NULL) {
	next = t->next;
	free(t);
	return next;
    }
    else {
	prev->next = t->next;
	free(t);
	return p;
    }
}


void printList(ListBlock *p)
{
    ListBlock *t = p;
    printf("Текущий список: \n");
    while (t != NULL) {
	printf("%d\n", t->value);
	t = t->next;
    }
    printf("-------------------\n");
}


void deleteList(ListBlock *p)
{
    ListBlock *t;
    while (p != NULL) {
	t = p->next;
	free(p);
	p = t;
    }
    printf("Список удален\n");
}