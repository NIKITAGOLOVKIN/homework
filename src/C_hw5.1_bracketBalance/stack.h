#pragma once
#include <stdlib.h>


typedef struct StackNode {
    char value;
    struct StackNode *next;
} Node;




Node* newStack(void);

Node* push(Node *top, char value);


Node* pop(Node *top);


char peek(Node *top);


void show(Node *top);


void deleteStack(Node *top);