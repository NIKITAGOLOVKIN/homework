#pragma once
#include <stdlib.h>


typedef struct ListNode {
    int value;
    struct ListNode *next;
} Node;


Node* newList(void);

Node* insertValue(Node *top, int value);


Node* removeValue(Node *top, int value);


void printList(Node *top);


void deleteList(Node *top);