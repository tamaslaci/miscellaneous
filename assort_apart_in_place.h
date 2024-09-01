#ifndef assort_apart_in_place__h
#define assort_apart_in_place__h

#include <vector>
#include <iostream>

bool search_from_back(int& front, int& back, const std::vector<int>& numbers);
bool search_from_front(int& front, int& back, const std::vector<int>& numbers);
int assort_apart_in_place(std::vector<int>& numbers);

#endif
