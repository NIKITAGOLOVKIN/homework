#pragma once
#include <stdlib.h>


typedef struct ListNode {
    int value;
    struct ListNode *next;
    struct ListNode *previous;
} Node;


Node* insertValue(Node *p, int value);

void symmetry(Node *top, Node *end);

void printList(Node *p);


void deleteList(Node *p);