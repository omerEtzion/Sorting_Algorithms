#include "Sort.h"
#include <iostream>

void Merge_Sort::sort()
{
	if ((*arr).size() > 0) {
		recursive_sort(*arr);
	}
	create_output("merge_sort");
}

void Merge_Sort::recursive_sort(vector<int>& array)
{
	if (array.size() > 1) {
		int mid = array.size() / 2;

		vector<int>* subarray1 = new vector<int>(array.begin(), array.begin() + mid);
		vector<int>* subarray2 = new vector<int>(array.begin() + mid, array.end());

		if ((*subarray1).size() > 1) {
			recursive_sort(*subarray1);
		}
		if ((*subarray2).size() > 1) {
			recursive_sort(*subarray2);
		}

		int i1 = 0;
		int i2 = 0;
		int i3 = 0;

		if ((*subarray1).size() == 0) {
			array[0] = (*subarray2)[0];
		}
		else {
			while (i3 < array.size()) {
				if (i1 == (*subarray1).size() || i2 == (*subarray2).size()) {
					if (i1 == (*subarray1).size() && i2 < (*subarray2).size()) {
						array[i3] = (*subarray2)[i2];
						i2++;
					}
					else {
						array[i3] = (*subarray1)[i1];
						i1++;
					}
				}
				else {
					if ((*subarray1)[i1] < (*subarray2)[i2]) {
						array[i3] = (*subarray1)[i1];
						i1++;
					}
					else {
						array[i3] = (*subarray2)[i2];
						i2++;
					}
				}
				i3++;
			}
		}

		delete(subarray1);
		delete(subarray2);
	}
}