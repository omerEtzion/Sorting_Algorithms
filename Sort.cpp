#include "Sort.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Sort::Sort(string path)
{
	fstream input("C:\\Users\\etzio\\Desktop\\cs\\Sorting_Algorithms\\Sorting_Algorithms\\input.txt", std::ios_base::in);
	arr = new vector<int>();
	if (input.is_open()) {
		int i;
		while (input >> i) {
			(*arr).push_back(i);
		}
		input.close();
	}
}

Sort::Sort(const Sort& other)
{
	arr = new vector<int>((*other.arr));
}

Sort::Sort(Sort&& other) : arr(other.arr) {}

const Sort& Sort::operator=(const Sort& other)
{
	if (this != &other) {
		delete(arr);
		arr = new vector<int>(*(other.arr));
	}
	return *this;
}

const Sort& Sort:: operator=(Sort&& other)
{
	if (this != &other) {
		delete(arr);
		arr = other.arr;
	}
	return *this;
}

void Sort::create_output(string method_name)
{
	ofstream output("C:\\Users\\etzio\\Desktop\\cs\\Sorting_Algorithms\\Sorting_Algorithms\\input.txt");
	if (output.is_open()) {
		for (int i = 0; i < (*arr).size(); i++) {
			output << to_string((*arr)[i]) + "\n";
		}
		output.close();
	}
}

Sort::~Sort()
{
	delete(arr);
}
