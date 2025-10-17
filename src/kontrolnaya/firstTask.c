#include <stdio.h>
#include <stdlib.h>

int sum(int n)
{
    int sum = 0;
    while (n) {
	sum = sum + (n % 10);
	n = n / 10;
    }
    return sum;
}


int main()
{
    int arr1[] = {1, 12, 34, 147, 8, 99, 198, -387};
    int size = (sizeof(arr1) / sizeof(arr1[0]));
    int arr2[size];
    int max = 0;
    int buff = 0;


    for (int i = 0; i < size; ++i) {
	buff = sum(abs(arr1[i]));
	arr2[i] = buff;
	if (buff > max) {
	    max = buff;
	}
    }


    for (int i = 0; i < size; ++i) {
	if (arr2[i] == max)
	    printf("%d ", arr1[i]);
    }
    printf("\n");
    return 0;
}