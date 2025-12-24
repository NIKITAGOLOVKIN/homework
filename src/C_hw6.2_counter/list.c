#include "list.h"
#include <stdio.h>

Node* createList(int n)
{
    Node* top = malloc(sizeof(Node));
    top->value = 1;
    Node* current = top;

    for (int i = 2; i <= n; i++) {
        current->next = malloc(sizeof(Node));
        current = current->next;
        current->value = i;
    }

    current->next = top;
    return top;
}

void deleteList(Node* top)
{
    Node* current = top;
    while (current->next != top) {
        current = current->next;
    }
    current->next = NULL;
    current = top;
    while (current != NULL) {
        top = top->next;
        free(current);
        current = top;
    }
}