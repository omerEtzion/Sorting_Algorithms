#include "Sort.h"
#include <chrono>
#include <random>
#include <iostream>

using namespace std;

void Quick_Sort::sort()
{
	if ((*arr).size() > 0) {
		recursive_sort(0, (*arr).size() - 1);
	}
	create_output("quick_sort");
}

void Quick_Sort::recursive_sort(int low, int high)
{
	if (low < high) {
		int pivot_index = partition(low, high);
		recursive_sort(low, pivot_index - 1);
		recursive_sort(pivot_index + 1, high);
	}
}

int Quick_Sort::partition(int low, int high)
{
	int pivot = (*arr)[high];
	int output = low;
	for (int j = low; j < high; j++) {
		if ((*arr)[j] < pivot) {
			swap(&(*arr)[j], &(*arr)[output]);
			output++;
		}
	}
	swap(&(*arr)[output], &(*arr)[high]);
	return output;
}

void Quick_Sort::swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}


