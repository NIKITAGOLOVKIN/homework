#include <stdio.h>
#include "list.h"


Node* insertValue(Node *p, int value)
{
    Node *t = malloc(sizeof(Node));
    t->value = value;
    t->next = p;
    t->previous = NULL;
    p = t;
    if (t->next != NULL) {
        t->next->previous = t;
    }
    return p;
}

void symmetry(Node *top, Node *end)
{
    Node *counter = top;
    Node *topTemporary = top;
    Node *endTemporary = end;
    int count = 0;
    while (counter->next != NULL) {
        count++;
        counter = counter->next;
    }
    count++;

    int flag = 1;
    for (int i = 0; (count+1) / 2 >= i; i++) {
	if (topTemporary->value == endTemporary->value) {
	    topTemporary = topTemporary->next;            //тут чтото ломается, или не тут ¯\_(ツ)_/¯
	    endTemporary = endTemporary->previous;
	}
	else {
	    flag = 0;
	    break;
	}
    }

    if (flag) {
	printf("Симметрия выполняется\n");
    }
    else {
	printf("Симметрия не выполняется\n");
    }
}

void printList(Node *p)
{
    Node *t = p;
    printf("Текущий список: \n");
    while (t != NULL) {
	printf("%d\n", t->value);
	t = t->next;
    }
    printf("-------------------\n");
}


void deleteList(Node *p)
{
    Node *t = p;
    while (p != NULL) {
	t = p->next;
	free(p);
	p = t;
    }
    free(t);
}