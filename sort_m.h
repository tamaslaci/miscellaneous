#ifndef sort_m__h
#define sort_m__h

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

//
// Basic sorting algorithms
//

void simple_swap_sort(std::vector<int>& numbers);

void minimum_search_sort(std::vector<int>& numbers);

void bubble_sort(std::vector<int>& numbers);

void enhanced_bubble_sort(std::vector<int>& numbers);

void insertion_sort(std::vector<int>& numbers);

void enhanced_insertion_sort(std::vector<int>& numbers);

std::vector<int> division_sort(const std::vector<int> numbers);

std::vector<int> counting_division_sort(const std::vector<int> numbers, int max_value);

std::vector<int> counting_sort(std::vector<int>& numbers);

//
// Searching in sorted sequence
//

struct found_item{
    bool found;
    int index;
};

found_item logarithmic_search(const std::vector<int> numbers, const int value);

found_item binary_search(const std::vector<int> numbers, const int value);

// utility methods

void shuffle_numbers(std::vector<int>& numbers);

void print_vector(const std::vector<int>& vect);

#endif