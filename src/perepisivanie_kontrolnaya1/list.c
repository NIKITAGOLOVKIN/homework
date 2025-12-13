#include <stdio.h>
#include "list.h"


ListNode* insertValue(ListNode *p, int value)
{
    ListNode *t = malloc(sizeof(ListNode));
    t->value = value;
    t->next = p;
    p = t;
    return p;
}


void printList(ListNode *p)
{
    ListNode *t = p;
    printf("Текущий список: \n");
    while (t != NULL) {
	printf("%d\n", t->value);
	t = t->next;
    }
    printf("-------------------\n");
}


void deleteList(ListNode *p)
{
    ListNode *t;
    while (p != NULL) {
	t = p->next;
	free(p);
	p = t;
    }
    free(t);
}