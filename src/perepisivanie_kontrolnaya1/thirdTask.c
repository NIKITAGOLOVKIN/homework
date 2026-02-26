#include <stdio.h>
#include "list.h"


int main(void)
{
    ListNode *firstList = NULL;
    ListNode *secondList = NULL;
    ListNode *resultList = NULL;
    firstList = insertValue(firstList, 5);
    firstList = insertValue(firstList, 3);
    firstList = insertValue(firstList, 1);
    secondList = insertValue(secondList, 6);
    secondList = insertValue(secondList, 4);
    secondList = insertValue(secondList, 2);

    resultList = mergeList(firstList, secondList);
    printList(resultList);



    deleteList(resultList);
    return 0;
}


ListNode* mergeList(ListNode *first, ListNode *second)
{
    ListNode *start = NULL;
    ListNode *t;
    start = first;
    while ((first != NULL) && (second != NULL)) {
        t = first->next;
        first->next = second;
        first = t;
        t = second->next;
        second->next = first;
        second = t;
    }
    return start;
}