#include "Sort.h"
#include<iostream>

void Bubble_Sort::sort()
{
	if ((*arr).size() > 0) {
		bool swapped = true;
		while (swapped) {
			swapped = false;
			for (int i = 0; i < (*arr).size() - 1; i++) {
				if ((*arr)[i] > (*arr)[i + 1]) {
					swap(&(*arr)[i], &(*arr)[i + 1]);

					swapped = true;
				}
			}
		}
	}
	create_output("bubble_sort");
}

void Bubble_Sort::swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
