#include "Sort.h"
#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int min_element_index(vector<int> v)
{
	int min_index = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] < v[min_index]) {
			min_index = i;
		}
	}
	return min_index;
}

int main(int argc, char** argv) {

	Quick_Sort* qs = new Quick_Sort("input.txt");
	Merge_Sort* ms = new Merge_Sort("input.txt");
	Bubble_Sort* bs = new Bubble_Sort("input.txt");

	int qs_time = chrono::duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
	(*qs).sort();
	qs_time = chrono::duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count() - qs_time;
	cout << "quick sort running time: " << qs_time << " ms\n";

	int ms_time = chrono::duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
	(*ms).sort();
	ms_time = chrono::duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count() - ms_time;
	cout << "merge sort running time: " << ms_time << " ms\n";

	int bs_time = chrono::duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count();
	(*bs).sort();
	bs_time = chrono::duration_cast<milliseconds>(high_resolution_clock::now().time_since_epoch()).count() - bs_time;
	cout << "Bubble sort running time: " << bs_time << " ms";

	vector<int> times = { qs_time, ms_time, bs_time };
	vector<string> methods = { "Quick Sort", "Merge Sort", "Bubble Sort" };

	string winner = methods[min_element_index(times)];
	cout << "\n\nThe quickest method is " << winner << "\n\n";

	delete(qs);
	delete(ms);
	delete(bs);

	return 0;
}

