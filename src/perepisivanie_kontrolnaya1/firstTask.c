#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int size = 10;
    int count = 0;
    int n;
    arr = (int *)malloc(size * sizeof(int));
    printf("Введите целые числа (0 для завершения):\n");
    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break;
        }

        if (count >= size) {
            size *= 2;
            arr = (int *)realloc(arr, size * sizeof(int));
        }

        arr[count] = n;
        count++;
    }

    printf("Числа без пары:\n");
    int numbersWithPair = 0;

    for (int i = 0; i < count; i++) {
        int havePair = 0;
        for (int j = 0; j < count; j++) {
            if (arr[j] == arr[i] + 1) {
                havePair = 1;
                break;
            }
        }
        if (!havePair) {
            printf("%d\n", arr[i]);
            numbersWithPair = 1;
        }
    }

    if (!numbersWithPair) {
        printf("Нет чисел без пары.\n");
    }

    free(arr);
    return 0;
}