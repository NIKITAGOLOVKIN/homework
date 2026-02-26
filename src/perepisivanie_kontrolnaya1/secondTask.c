#include <stdio.h>

int countOfDigits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int main() {
    printf("Введите два числа через пробел\n");
    int a, b;
    scanf("%d %d", &a, &b);

    int sumA = countOfDigits(a);
    int sumB = countOfDigits(b);

    if (sumA >= sumB) {
        printf("%d\n", a);
    }
    else {
        printf("%d\n", b);
    }

    return 0;
}