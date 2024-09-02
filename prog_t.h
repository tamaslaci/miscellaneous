#ifndef prog_t__h
#define prog_t__h

#include <iostream>
#include <vector>
#include <string>

//
// Basic Programming Theorems
//

// 1.
// SUMMATION
int summing_numbers(const std::vector<int>& numbers);

// 2.
// COUNTING
int counting_summer_months(const std::vector<int>& months);

// 3.
// MAXIMUM SELECTION
struct int_item {
    int value;
    int position;
};

int_item select_max_number(const std::vector<int>& numbers);

// 4.
// FINDING / DECIDING
bool find_greater_than_five(const std::vector<int>& numbers, int_item& first_greater_value);

bool every_number_positive(const std::vector<int>& numbers);

// 5.
// SELECTING
struct string_item {
    int index;
    std::string value;
};

string_item selecting_grapefruit(const std::vector<std::string>& fruits);

// 6.
// COPY ( TRANSFORM )
std::vector<int> square_numbers(const std::vector<int>& numbers);

std::vector<int> square_even_numbers(const std::vector<int>& numbers);

void print_vector(const std::vector<int>& vect);

// 7.
// ASSORT
struct assort_item{
    int count;
    std::vector<int> items;
};

assort_item assort_evens(const std::vector<int>& numbers);

std::vector<int> assort_evens_dynamic(const std::vector<int>& numbers);

// 8.
// ASSORT_APART / DISTRIBUTE
struct assort_apart_item{
    int count;
    std::vector<int> items_y;
    std::vector<int> items_z;
};

assort_apart_item assort_numbers(const std::vector<int>& numbers);

struct assort_apart_arrays{
    std::vector<int> items_y;
    std::vector<int> items_z;
};

assort_apart_arrays assort_numbers_dynamic(const std::vector<int>& numbers);

#endif