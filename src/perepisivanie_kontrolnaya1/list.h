#pragma once
#include <stdlib.h>


typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;


ListNode* insertValue(ListNode *p, int value);


void printList(ListNode *p);


void deleteList(ListNode *p);


ListNode* mergeList(ListNode *first, ListNode* second);