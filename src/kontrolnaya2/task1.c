#include <stdio.h>
#include "list.h"

int main()
{
    int *top = NULL;
    Node *end = NULL;
    int command = 0;
    int value = 0;
    while (command != 3) {
        printf("Список команд:\n");
        printf("1 - добавить значение в список\n");
        printf("2 - проверка на симметричность\n");
        printf("3 - завершить программу\n\n");
        printf("Введите команду: ");
        scanf("%d", &command);
        printf("--------------------------------\n");
        switch (command) {
            case 1:
                printf("Введите значение: ");
		scanf("%d", &value);
                printf("--------------------------------\n");
		top = insertValue(top, value);
                end = top;
		printList(top);
		break;
	    case 2:
		symmetry(top, end);
		break;
	    default:
		break;
	}
    }
    deleteList(top);
    return 0;
}