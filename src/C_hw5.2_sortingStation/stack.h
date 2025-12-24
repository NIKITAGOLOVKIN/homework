#pragma once
#include <stdlib.h>

typedef struct StackNode {
    char value;
    struct StackNode* next;
} Node;

Node* newStack(void); // создать стек

Node* push(Node* top, char value); // отправить значение в стек

Node* pop(Node* top); // удалить элемент стека

char peek(Node* top); // вернуть значение из стека

void show(Node* top); // вывести весь стек

void deleteStack(Node* top); // удалить стек