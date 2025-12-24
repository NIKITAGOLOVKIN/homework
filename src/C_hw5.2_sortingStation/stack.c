#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Node* newStack(void)
{
    return NULL;
}

Node* push(Node* top, char value)
{
    Node* p = malloc(sizeof(Node));
    p->value = value;
    p->next = top;
    return p;
}

Node* pop(Node* top)
{
    if (top == NULL)
        return top;

    Node* p = top->next;
    free(top);
    return p;
}

char peek(Node* top)
{
    if (top == NULL) {
        return 0;
    } else
        return top->value;
}

void show(Node* top)
{
    printf("Стек: \n");
    Node* p = top;
    while (p != NULL) {
        printf("%c\n", p->value);
        p = p->next;
    }
    printf("\n");
}

void deleteStack(Node* top)
{
    while (top != NULL) {
        Node* p = top;
        top = top->next;
        free(p);
    }
    free(top);
}