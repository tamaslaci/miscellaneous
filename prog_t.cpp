//
// Basic Programming Theorems
//

#include "prog_t.h"

// 1.
// SUMMATION
int summing_numbers(const std::vector<int>& numbers){        // input: N, X[1..N]
    int sum = 0;                                             // SUM := 0 (SUM := F0)
    for(int i = 0; i < numbers.size(); ++i){                 // i = 1 .. N
        sum += numbers.at(i);                                // SUM := SUM + X[i] (SUM := f(SUM,X[i]))
    }
    return sum;                                              // output: SUM
}

// 2.
// COUNTING
int counting_summer_months(const std::vector<int>& months){  // input: N, X[1..N], T:H -> L
    int count = 0;                                           // COUNT := 0
    for(int i = 0; i < months.size(); ++i){                  // i = 1 .. N
        if(i >= 6 && i <= 8){                                // T(X[i]) -> L
            ++count;                                         // COUNT := COUNT + 1
        }
    }
    return count;                                            // output: COUNT
}

// 3.
// MAXIMUM SELECTION
int_item select_max_number(const std::vector<int>& numbers){ // input: N, X[1..N]
    int_item result{};
    result.value = numbers.at(0);                            // MaxValue := X[1]
    result.position = 0;                                     // MaxPosition := 1
    for(int i = 1; i < numbers.size(); ++i){                 // i = 2 .. N
        if(numbers.at(i) > result.value){                    // X[i] > MaxValue -> L
            result.value = numbers.at(i);                    // MaxValue := X[i]
            result.position = i;                             // MaxPosition := i
        }
    }
    return result;                                           // output: (MaxValue, MaxPosition)
}

// 4.
// FINDING / DECIDING
bool find_greater_than_five(const std::vector<int>& numbers, int_item& first_greater_value){ // input: N, X[1..N], T:H -> L
    int i = 0;                                                                               // i := 1
    while(i < numbers.size() && numbers.at(i) <= 5){                                         // i < N and not T(X[i])
        ++i;                                                                                 // i := i + 1
    }
    if(i < numbers.size()){                                                                  // FOUND := i < N ( -> DECIDING )
        first_greater_value.value = numbers.at(i);                                           // VALUE := X[i]
        first_greater_value.position = i;                                                    // POSITION := i
        return true;                                                                         // output: (FOUND, POSITION, VALUE)
    }
    return false;
}

bool every_number_positive(const std::vector<int>& numbers){ // input: N, X[1..N], T:H -> L 
    int i = 0;                                               // i := 1
    while(i < numbers.size() && numbers.at(i) > 0){          // i < N and not T(X[i])
        ++i;                                                 // i := i + 1
    }
    if(i < numbers.size()){                                  // FOUND := i < N ( -> DECIDING )
        return false;                                        // output: FOUND (not every)
    }
    return true;                                             // output: FOUND (every)
}

// 5.
// SELECTING
string_item selecting_grapefruit(const std::vector<std::string>& fruits){ // input: N, X[1..N], T:H -> L
    string_item result{};
    int i = 0;                                                            // i := 1
    while(fruits.at(i).compare("grapefruit") != 0){                       // not T(X[i])
        ++i;                                                              // i := i + 1
    }
    result.index = i;                                                     // INDEX := i
    result.value = fruits.at(i);                                          // VALUE := X[i]
    return result;                                                        // output: (INDEX, VALUE)
}

// 6.
// COPY ( TRANSFORM )
std::vector<int> square_numbers(const std::vector<int>& numbers){         // input: N, X[1..N], f:H -> H
    std::vector<int> result(numbers.size());
    for(int i = 0; i < numbers.size(); ++i){                              // i = 1 .. N
        result.at(i) = numbers.at(i) * numbers.at(i);                     // Y[i] := f(X[i])
    }
    return result;                                                        // output: Y[1..N]
}

std::vector<int> square_even_numbers(const std::vector<int>& numbers){    // input: N, X[1..N], g:H -> H, T:H -> L
    std::vector<int> result(numbers.size());
    for(int i = 0; i < numbers.size(); ++i){                              // i = 1 .. N
        if(numbers.at(i) % 2 == 0){                                       // T(X[i])
            result.at(i) = numbers.at(i) * numbers.at(i);                 // Y[i] := g(X[i])
        }else{                                                            // not T(X[i])
            result.at(i) = numbers.at(i);                                 // Y[i] := X[i]
        }
    }
    return result;                                                        // output: Y[1..N]
}

void print_vector(const std::vector<int>& vect){
    std::cout << "< ";
    for(int i : vect){
        std::cout << i << " ";
    }
    std::cout << ">";
}

// 7.
// ASSORT

assort_item assort_evens(const std::vector<int>& numbers){              // input: N, X[1..N], T:H -> L
    std::vector<int> result;
    int count = 0;                                                      // COUNT := 0
    for(int i = 0; i < numbers.size(); ++i){                            // i = 1 .. N
        if(numbers.at(i) % 2 == 0){                                     // T(X[i]) -> L
            ++count;                                                    // COUNT := COUNT + 1
            result.resize(count);
            result.at(count - 1) = numbers.at(i);                       // Y[COUNT] := X[i]
        }
    }
    return {count, result};                                             // output: (COUNT, Y[1..COUNT])
}

std::vector<int> assort_evens_dynamic(const std::vector<int>& numbers){ // input: N, X[1..N], T:H -> L
    std::vector<int> result;                                            // Y()
    for(int i = 0; i < numbers.size(); ++i){                            // i = 1 .. N
        if(numbers.at(i) % 2 == 0){                                     // T(X[i]) -> L
            result.push_back(numbers.at(i));                            // push_back(Y, X[i])
        }
    }
    return result;                                                      // output: Y
}

// 8.
// ASSORT_APART / DISTRIBUTE

assort_apart_item assort_numbers(const std::vector<int>& numbers){      // input: N, X[1..N], T:H -> L
    std::vector<int> items_y;                                           // Y()
    std::vector<int> items_z;                                           // Z()
    int count = 0;                                                      // COUNT := 0
    for(int i = 0; i < numbers.size(); ++i){                            // i = 1 .. N
        if(numbers.at(i) % 2 == 0){                                     // T(X[i])
            ++count;                                                    // COUNT := COUNT + 1
            items_y.resize(count);
            items_y.at(count - 1) = numbers.at(i);                      // Y[COUNT] := X[i]
        }else{                                                          // not T(X[i])
            items_z.resize(i - count + 1);
            items_z.at(i - count) = numbers.at(i);                      // Z[i-COUNT] := X[i]
        }
    }
    return {count, items_y, items_z};                                   // output: (COUNT, Y[1..COUNT], Z[1..N-COUNT])
}

assort_apart_arrays assort_numbers_dynamic(const std::vector<int>& numbers){ // input: N, X[1..N], T:H -> L
    std::vector<int> items_y;                                                // Y()
    std::vector<int> items_z;                                                // Z()
    for(int i = 0; i < numbers.size(); ++i){                                 // i = 1 .. N
        if(numbers.at(i) % 2 == 0){                                          // T(X[i])
            items_y.push_back(numbers.at(i));                                // push_back(Y, X[i])
        }else{                                                               // not T(X[i])
            items_z.push_back(numbers.at(i));                                // push_back(Z, X[i])
        }
    }
    return {items_y, items_z};                                               // output: (Y, Z)
}

int main(){
    std::vector<int> numbers_in_order = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::vector<int> numbers_unordered = {4, 6, 8, 9, 1, 2, 5, 3, 7};
    std::vector<int> months = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    std::vector<std::string> fruits = {"apple", "peach", "grapes", "strawberry", "raspberry", "grapefruit", "pineapple"};

    std::cout << std::endl;
    std::cout << "Basic programming theorems" << std::endl;
    
    // Summation
    std::cout << std::endl;
    std::cout << "SUM" << std::endl;
    std::cout << "Summing numbers from 1 to 9 = ";
    std::cout << summing_numbers(numbers_in_order) << std::endl;
    std::cout << std::endl;

    // Counting
    std::cout << "COUNT" << std::endl;
    std::cout << "Counting summer months = ";
    std::cout << counting_summer_months(months) << std::endl;
    std::cout << std::endl;

    // Selecting maximum
    std::cout << "MAXIMUM SELECT" << std::endl;
    int_item selected_max = select_max_number(numbers_unordered);
    std::cout << "Selecting maximum from an unordered sequence = " << selected_max.value
                << ", on position = " << selected_max.position + 1 << std::endl;
    std::cout << "The unordered sequence was: < 4 6 8 9 1 2 5 3 7 >" << std::endl;
    std::cout << std::endl;

    // Finding a value with a defined property, like: "greater than five"
    std::cout << "FIND / SEARCH" << std::endl;
    int_item first_greater_value{};
    if(find_greater_than_five(numbers_in_order, first_greater_value)){
        std::cout << "First greater value than five = " << first_greater_value.value
                    << ", on position = " << first_greater_value.position + 1 << std::endl;
        std::cout << "In the ordered number sequence of < 1 2 3 4 5 6 7 8 9 >" << std::endl;
    }else{
        std::cout << "There is no greater value than five in the given sequence!" << std::endl;
    }
    std::cout << std::endl;

    // Deciding if every value has a defined property, like: "greater than zero"
    std::cout << "DECIDE" << std::endl;
    std::cout << "Given number sequence: < 4 6 8 9 1 2 5 3 7 >" << std::endl;
    if(every_number_positive(numbers_unordered)){
        std::cout << "The number sequence has only positive numbers!" << std::endl;
    }else{
        std::cout << "The number sequence has zero or negative numbers too!" << std::endl;
    }
    std::cout << std::endl;

    // Selecting a given value first occurrence from a sequence
    string_item grapefruit = selecting_grapefruit(fruits);
    std::cout << "SELECT" << std::endl;
    std::cout << "Given string sequence: \n< apple peach grapes strawberry raspberry grapefruit pineapple >" << std::endl;
    std::cout << "The string sequence contains: " << grapefruit.value << " on position: " << grapefruit.index + 1 << std::endl;
    std::cout << std::endl;

    // Copy a sequence and alter it's members
    std::vector<int> squares = square_numbers(numbers_in_order);
    std::cout << "COPY" << std::endl;
    std::cout << "Square numbers from 1 to 9:" << std::endl;
    print_vector(squares);
    std::cout << std::endl;

    std::vector<int> square_evens = square_even_numbers(numbers_in_order);
    std::cout << "Square even numbers from 1 to 9 (odd numbers unchanged):" << std::endl;
    print_vector(square_evens);
    std::cout << std::endl;
    std::cout << std::endl;

    // Assort the even numbers from a sequence
    assort_item evens = assort_evens(numbers_unordered);
    std::cout << "ASSORT" << std::endl;
    std::cout << "Assort the even numbers from an undordered sequence (< 4 6 8 9 1 2 5 3 7 >):" << std::endl;
    std::cout << "Numbers: ";
    print_vector(evens.items);
    std::cout << " number of items: " << evens.count << std::endl;
    std::cout << "Assort the even numbers from an ordered sequence (< 1 2 3 4 5 6 7 8 9 >) to a dynamic array:" << std::endl;
    std::cout << "Numbers: ";
    print_vector(assort_evens_dynamic(numbers_in_order));
    std::cout << std::endl;
    std::cout << std::endl;

    // Assort apart numbers from a sequence as odd and even numbers
    assort_apart_item assorted_numbers = assort_numbers(numbers_unordered);
    std::cout << "ASSORT APART / DISTRIBUTE" << std::endl;
    std::cout << "Assort the numbers from an undordered sequence (< 4 6 8 9 1 2 5 3 7 >), as evens and odds:" << std::endl;
    std::cout << "Evens: ";
    print_vector(assorted_numbers.items_y);
    std::cout << std::endl;
    std::cout << "Odds: ";
    print_vector(assorted_numbers.items_z);
    std::cout << std::endl;
    std::cout << std::endl;
    assort_apart_arrays assorted_arrays = assort_numbers_dynamic(numbers_in_order);
    std::cout << "Assort the numbers from an ordered sequence (< 1 2 3 4 5 6 7 8 9 >), as evens and odds to dynamic arrays:" << std::endl;
    std::cout << "Evens: ";
    print_vector(assorted_arrays.items_y);
    std::cout << std::endl;
    std::cout << "Odds: ";
    print_vector(assorted_arrays.items_z);
    std::cout << std::endl;
    std::cout << std::endl;
    
    return 0;
}