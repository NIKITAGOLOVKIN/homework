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
    if (p == NULL || t->value <= p->value) {
	t->next = p;
	p = t;
	return p;
    }

/*    ListBlock *current = p->next;
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

    t->next = current;
    prev->next = t;
    return p;*/
}


ListBlock* removeValue(ListBlock *p, ListBlock *t)
{
    if (t->next == p && p->next == t) {
	t->next = NULL;
	free(p);
	return NULL;
    }
    t->next = p->next;
    free(p);
    return t->next;
    
    /*ListBlock *next = NULL;
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
    }*/
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