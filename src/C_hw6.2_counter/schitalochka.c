#include <stdio.h>
//#include <stdlib.h>
#include "list.h"


int schitalochka(Node *top, int n)
{
    Node *current = top;
    Node *prev = NULL;

    while (current->next != current) {
        for (int count = 1; count < n; count++) {
            prev = current;
            current = current->next;
        }

        prev->next = current->next;
        free(current);
        current = prev->next;
    }

    int survivor = current->value;
    free(current);
    top = NULL;
    return survivor;
}


int main(void)
{
    int warriors;
    int n;
    printf("Введите количество воинов: ");
    scanf("%d", &warriors);
    printf("Убиваем каждого n-ого, где n = ");
    scanf("%d", &n);
    Node *top = createList(warriors);
    int survivor = schitalochka(top, n);
    printf("Чтобы выжить, нужно стоять на %d месте\n", survivor);

    return 0;
}