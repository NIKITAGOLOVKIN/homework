#include <stdio.h>
#include "list.h"


int main(void)
{
    int command = 1;
    ListBlock *p = newList();
    int value;
    while (command != 0) {
	printf("Команды:\n");
	printf("0 - выйти\n");
	printf("1 - добавить значение в сортированный список\n");
	printf("2 - удалить значение из списка\n");
	printf("3 - распечатать список\n\n");
	printf("Введите команду: ");
	scanf("%d", &command);
	printf("-------------------\n");

	switch (command) {
	    case 0:
		break;
	    case 1:
		printf("Введите значение ");
		scanf("%d", &value);
		p = insertValue(p, value);
		printf("Значение %d добавлено в список\n", value);
		printf("-------------------\n");
		break;
	    case 2:
		printf("Введите значение ");
		scanf("%d", &value);
		p = removeValue(p, value);
		printf("Значение %d удалено из списка\n", value);
		printf("-------------------\n");
		break;
	    case 3:
		printList(p);
		break;
	    default:
		command = 1;
		printf("Неверная команда!!!\n");
		printf("-------------------\n");
		break;
	}
    }

    printf("Программа завершила свою работу\n");
    deleteList(p);
    return 0;
}