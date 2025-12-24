#pragma once
#include <stdlib.h>


typedef struct ListNode {
    int value;
    struct ListNode *next;
} Node;


Node* newList(void);

Node* insertValue(Node *p, int value);


Node* removeValue(Node *p, int value);


void printList(Node *p);


void deleteList(Node *p);