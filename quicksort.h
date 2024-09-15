#ifndef quicksort__h
#define quicksort__h

#include <iostream>
#include <vector>

void quicksort(std::vector<int>& numbers);
void quicksort(std::vector<int>& numbers, int start, int end);
int partition(std::vector<int>& numbers, int start, int end);

#endif