#pragma once
#include <vector>
#include <string>

using namespace std;

class Sort {
public:
	vector<int>* arr;

	Sort(string path);
	Sort(const Sort& other);
	Sort(Sort&& other);

	const Sort& operator=(const Sort& other);
	const Sort& operator=(Sort&& other);

	virtual void sort() = 0;
	void create_output(string method_name);

	virtual ~Sort();
};

class Quick_Sort : public Sort {
	using Sort::Sort;

public:
	virtual void sort();
	void recursive_sort(int low, int high);
	int partition(int low, int high);
	void swap(int* x, int* y);
};

class Merge_Sort : public Sort {
	using Sort::Sort;

public:
	virtual void sort();
	void recursive_sort(vector<int>& array);
};

class Bubble_Sort : public Sort {
	using Sort::Sort;

public:
	virtual void sort();
	void swap(int* x, int* y);
};

