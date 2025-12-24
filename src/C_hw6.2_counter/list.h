#pragma once
#include <stdlib.h>

typedef struct ListNode {
    int value;
    struct ListNode* next;
} Node;

Node* createList(int n);

void deleteList(Node* top);