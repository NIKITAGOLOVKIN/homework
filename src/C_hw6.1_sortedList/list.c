#include "list.h"
#include <stdio.h>

Node* newList(void)
{
    return NULL;
}

Node* insertValue(Node* top, int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->value = value;

    if (top == NULL || value < top->value) {
        newNode->next = top;
        return newNode;
    }

    Node* current = p;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    return top;
}

Node* removeValue(Node* top, int value)
{
    if (top != NULL && top->value == value) {
        Node* newTop = top->next;
        free(head);
        return newTop;
    }

    Node* t = top;
    while (t != NULL && t->next != NULL && t->next->value != value) {
        t = t->next;
    }

    if (t == NULL || t->next == NULL)
        return head;

    Node* toRemove = t->next;
    t->next = toRemove->next;
    free(toRemove);
    return head;
}

void printList(Node* top)
{
    Node* t = top;
    printf("Текущий список: \n");
    while (t != NULL) {
        printf("%d\n", t->value);
        t = t->next;
    }
    printf("-------------------\n");
}

void deleteList(Node* top)
{
    while (top != NULL) {
        Node* t = top;
        top = top->next;
        free(t);
    }
}