#include "quickSort.h"


void quickSort(int result[], int start, int end)
{
    if (start < end) {
	int p = permutation(result, start, end);
	quickSort(result, start, p - 1);
	quickSort(result, p + 1, end);
    }
}



int permutation(int result[], int start, int end)
{
    int pivot = result[end];
    int i = start - 1;
    int n;
    for (int j = start; j < end; ++j) {
	if (result[j] < pivot) {
	    ++i;
	    n = result[j];
	    result[j] = result[i];
	    result[i] = n;
	}
    }

    n = result[i + 1];
    result[i + 1] = result[end];
    result[end] = n;

    return i + 1;
}