#include <stdio.h>
#include "list.h"


int main(void)
{
    int warriors;
    int n;
    int k;
    printf("Введите количество воинов: ");
    scanf("%d", &warriors);
    printf("Убиваем каждого n-ого, где n = ");
    scanf("%d", &n);

    ListBlock *p = newList();
    ListBlock *last = NULL;
    for (int i = warriors; i >= 1; --i) {
	p = insertValue(p, i);
	if (i == warriors)
	    last = p;
	if (i == 1)
	    last->next = p;
    }

    int i = 1;
    while (p != NULL) {
	p = p->next;
	i++;
	last = last->next;
	if (i == n) {
	    p = removeValue(p, last);
	    i = 1;
	}
    }
    k = last->value;
    printf("Чтобы выжить, нужно стоять на %d месте\n", k);
    return 0;
}