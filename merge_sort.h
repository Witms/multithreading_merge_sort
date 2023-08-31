#pragma once
#include <future>
#include <vector>
#include <iostream>


void merge(int* arr, int l, int m, int r);

void split(int* arr, int l, int r);

void mergeSort(int* arr, int l, int r);

bool operator==(const std::vector<int>& my, const std::vector<int> other);

std::ostream& operator<<(std::ostream&, const std::vector<int>&);