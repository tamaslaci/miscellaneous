#ifndef merge_sort__h
#define merge_sort__h

#include <iostream>
#include <vector>
#include <cmath>

void merge_sort(std::vector<int>& numbers);
void ms(std::vector<int>& numbers_b, std::vector<int>& numbers_a, int start, int end);
void merge(std::vector<int>& numbers_b, std::vector<int>& numbers_a, int start, int middle, int end);

#endif