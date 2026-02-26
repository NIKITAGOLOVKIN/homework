#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

#define MAXSIZE 100


int main()
{
    int input[MAXSIZE] = {0};    //инициализируем массив нулями
    int countOfDigit = 0;
    char c;
    int count = 0;
    printf("Введите до %d чисел через пробел ", MAXSIZE);
    for (int i = 0; i < MAXSIZE; ++i) {              //в цикле заполняем массив
        ++countOfDigit;        //считаем сколько чисел ввел пользователь
        scanf("%d", &input[i]);
        if ((c = getchar()) == '\n') {              //если встретили enter прерываем цикл
            break;
        }
    }

    int *result = (int*)malloc(countOfDigit * sizeof(int));  //создаем новый массив только с введеными числами
    for (int i = 0; i < countOfDigit; ++i) {
        result[i] = input[i];
    }


    quickSort(result, 0, countOfDigit - 1);   //вызываем сортировку

    printf("Массив после сортировки ");
    for (int i = 0; i < countOfDigit; ++i) {   //печать массива
        printf("%d ", result[i]);
    }
    printf("\n");


    for (int i = 0; i < countOfDigit; ++i) {   //подсчет элементов изменивших свое место
        if (input[i] != result[i]) {
            ++count;
        }
    }


    printf("Свою позицию изменили %d элементов\n", count);
    free(result);
    return count;
}