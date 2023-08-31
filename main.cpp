#include <iostream>
#include "merge_sort.h"
#include <vector>


int main()
{
	std::vector<int> vec{ 6, 5, 4, 3, 2, 10, 15, 11, 12, 14, 20, 1, 2, 34, 40, 22, 5, 65, 12, 23, 78, 80, 26, 28, 89, 34, 35, 23, 31, 41, 44, 48, 52, 53, 58, 60, 72, 73, 71, 75, 78, 80, 82, 84, 87, 90 };

	mergeSort(&vec.at(0), 0, vec.size());

	std::cout << "Result: " << vec;

	return 0;
}