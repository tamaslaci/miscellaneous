//
// Basic sorting algorithms
//

#include "sort_m.h"

void simple_swap_sort(std::vector<int>& numbers){           // input: N, X[1..N], [>] ExE -> L, output: X'[1..N]
    for(int i = 0; i < numbers.size() - 1; ++i){            // i = 1 .. N - 1
        for(int j = i + 1; j < numbers.size(); ++j){        // j = i + 1 .. N
            if(numbers.at(i) > numbers.at(j)){              // X[i] > X[j] -> L
                int temp = numbers.at(i);                   // s := X[i]
                numbers.at(i) = numbers.at(j);              // X[i] := X[j]
                numbers.at(j) = temp;                       // X[j] := s
            }
        }
    }
}

void minimum_search_sort(std::vector<int>& numbers){        // input: N, X[1..N], [>] ExE -> L, output: X'[1..N]
    for(int i = 0; i < numbers.size() - 1; ++i){            // i = 1 .. N - 1
        int min_i = i;                                      // MinI := i
        for(int j = i + 1; j < numbers.size(); ++j){        // j = i + 1 .. N
            if(numbers.at(min_i) > numbers.at(j)){          // X[MinI] > X[j] -> L
                min_i = j;                                  // MinI := j
            }
        }
        int temp = numbers.at(i);                           // s := X[i]
        numbers.at(i) = numbers.at(min_i);                  // X[i] := X[MinI]
        numbers.at(min_i) = temp;                           // X[MinI] := s
    }
}

void bubble_sort(std::vector<int>& numbers){                // input: N, X[1..N], [>] ExE -> L, output: X'[1..N]
    for(int i = numbers.size() - 1; i >= 1; --i){           // i = N .. 2
        for(int j = 0; j <= i - 1; ++j){                    // j = 1 .. i - 1
            if(numbers.at(j) > numbers.at(j + 1)){          // X[j] > X[j + 1] -> L
                int temp = numbers.at(j);                   // s := X[j]
                numbers.at(j) = numbers.at(j + 1);          // X[j] := X[j + 1]
                numbers.at(j + 1) = temp;                   // X[j + 1] := s
            }
        }
    }
}

void enhanced_bubble_sort(std::vector<int>& numbers){       // input: N, X[1..N], [>] ExE -> L, output: X'[1..N]
    int i = numbers.size() - 1;                             // i := N
    while(i >= 1){                                          // i >= 2
        int swap{};                                         // cs := 0
        for(int j = 0; j <= i - 1; ++j){                    // j = 1 .. i - 1
            if(numbers.at(j) > numbers.at(j + 1)){          // X[j] > X[j + 1] -> L
                int temp = numbers.at(j);                   // s := X[j]
                numbers.at(j) = numbers.at(j + 1);          // X[j] := X[j + 1]
                numbers.at(j + 1) = temp;                   // X[j + 1] := s
                swap = j;                                   // cs := j
            }
        }
        i = swap;                                           // i := cs
    }
}

void insertion_sort(std::vector<int>& numbers){             // input: N, X[1..N], [>] ExE -> L, output: X'[1..N]
    for(int i = 1; i < numbers.size(); ++i){                // i = 2 .. N
        int j = i - 1;                                      // j := i - 1
        while(j >= 0 &&                                     // j > 0 and
            numbers.at(j) > numbers.at(j + 1)){             // X[j] > X[j + 1]
                int temp = numbers.at(j);                   // s := X[j]
                numbers.at(j) = numbers.at(j + 1);          // x[j] := X[j + 1]
                numbers.at(j + 1) = temp;                   // X[j + 1] := s
                --j;                                        // j := j - 1
        }
    }
}

void enhanced_insertion_sort(std::vector<int>& numbers){    // input: N, X[1..N], [>] ExE -> L, output: X'[1..N]
    for(int i = 1; i < numbers.size(); ++i){                // i = 2 .. N
        int insert = numbers.at(i);                         // s := X[i]
        int j = i - 1;                                      // j := i - 1
        while(j >= 0 && numbers.at(j) > insert){            // j > 0 and X[j] > s
            numbers.at(j + 1) = numbers.at(j);              // X[j + 1] := X[j]
            --j;                                            // j := j - 1
        }
        numbers.at(j + 1) = insert;                         // X[j + 1] := s
    }
}

std::vector<int> division_sort(const std::vector<int> numbers){ // input: N, X[1..N]
    std::vector<int> result(int(numbers.size()) + 1);
    for(int i = 0; i < numbers.size(); ++i){                    // i = 1 .. N
        result.at(numbers.at(i)) = numbers.at(i);               // Y[X[i]] := X[i] (or Y[X[i].key] := X[i] type 'record')
    }
    result.erase(result.begin());
    return result;                                              // output: Y[1..N]
}

// Multiset containing values from 1 to M, |Multiset| = N
std::vector<int> counting_division_sort(const std::vector<int> numbers, int max_value){ //input: N, M, X[1..N]
    std::vector<int> result(int(numbers.size()));
    std::vector<int> count(max_value + 1, 0);                                           // Count[1..M] := 0
    for(int i = 0; i < numbers.size(); ++i){                                            // i = 1 .. N
        ++count.at(numbers.at(i));                                                      // Count[X[i]] := Count[X[i]] + 1
    }
    std::vector<int> first_element(max_value + 1);
    first_element.at(0) = 1;                                                            // First[1] := 1
    for(int i = 1; i <= max_value - 1; ++i){                                            // i = 1 .. M - 1
        first_element.at(i + 1) = first_element.at(i) + count.at(i);                    // First[i + 1] := First[i] + Count[i]
    }
    for(int i = 0; i < numbers.size(); ++i){                                            // i = 1 .. N
        result.at(first_element.at(numbers.at(i))) = numbers.at(i);                     // Y[First[X[i]]] := X[i]
        first_element.at(numbers.at(i)) = first_element.at(numbers.at(i)) + 1;          // First[X[i]] := First[X[i]] + 1
    }
    return result;                                                              // output: Y[1..N]
}

std::vector<int> counting_sort(std::vector<int>& numbers){                      // input: N, X[1..N]
    std::vector<int> result(int(numbers.size()));
    std::vector<int> count(int(numbers.size()), 0);                             // Count[1..N] := 0
    for(int i = 0; i < numbers.size() - 1; ++i){                                // i = 1 .. N - 1
        for(int j = i + 1; j < numbers.size(); ++j){                            // j = i + 1 .. N
            if(numbers.at(i) > numbers.at(j)){                                  // X[i] > X[j] -> L
                ++count.at(i);                                                  // Count[i] := Count[i] + 1
            }else{
                ++count.at(j);                                                  // Count[j] := Count[j] + 1
            }
        }
    }
    for(int i = 0; i < numbers.size(); ++i){                                    // i = 1 .. N
        result.at(count.at(i)) = numbers.at(i);                                 // Y[Count[i] + 1] := X[i]
    }
    return result;                                                              // output: Y[1..N]
}

//
// Searching in sorted sequence
//

found_item logarithmic_search(const std::vector<int> numbers, const int value){     // input: N, X[1..N], Y (value)
    int i = 0;                                                                      // i := 1
    while(i < numbers.size() && numbers.at(i) < value){                             // i <= N and X[i] < Y
        ++i;                                                                        // i := i + 1
    }
    return {i < numbers.size(), i};                                                 // output: (FOUND, index)
}

found_item binary_search(const std::vector<int> numbers, const int value){          // input: N, X[1..N], Y (value)
    int start = 0;                                                                  // e := 1
    int end = numbers.size() - 1;                                                   // u := N
    int middle = floor((start + end) / 2);
    do{
        middle = floor((start + end) / 2);                                          // k := (e + u) div 2
        if(numbers.at(middle) > value){                                             // X[k] > Y
            end = middle - 1;                                                       // u := k - 1
        }else if(numbers.at(middle) < value){                                       // X[k] < Y
            start = middle + 1;                                                     // e := k + 1
        }
    }while(start <= end && numbers.at(middle) != value);                            // e <= u and X[k] != Y
    return {numbers.at(middle) == value, middle};                                   // output: (FOUND, index)
}

// utility methods

void shuffle_numbers(std::vector<int>& numbers){
    for(int i = 0; i < numbers.size() - 1; ++i){
        for(int j = i + 1; j < numbers.size(); ++j){
            if(std::rand() % 2){
                int temp = numbers.at(i);
                numbers.at(i) = numbers.at(j);
                numbers.at(j) = temp;
            }
        }
    }
}

void print_vector(const std::vector<int>& vect){
    std::cout << "< ";
    for(int i : vect){
        std::cout << i << " ";
    }
    std::cout << ">";
}

int main(){
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> numbers_multiset = { 1, 1, 1, 2, 2, 3, 4, 5, 5, 6};

    std::cout << std::endl;
    std::cout << "Basic sorting and searching algorithms" << std::endl;
    std::cout << std::endl;
    
    shuffle_numbers(numbers);
    std::cout << "1. Simple swap sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    simple_swap_sort(numbers);
    std::cout << "Sorted number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << std::endl;

    shuffle_numbers(numbers);
    std::cout << "2. Minimum search sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    minimum_search_sort(numbers);
    std::cout << "Sorted number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << std::endl;
    
    shuffle_numbers(numbers);
    std::cout << "3. Bubble sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    bubble_sort(numbers);
    std::cout << "Sorted number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << std::endl;
    
    shuffle_numbers(numbers);
    std::cout << "4. Enhanced bubble sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    enhanced_bubble_sort(numbers);
    std::cout << "Sorted number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << std::endl;
    
    shuffle_numbers(numbers);
    std::cout << "5. Insertion sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    insertion_sort(numbers);
    std::cout << "Sorted number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << std::endl;
    
    shuffle_numbers(numbers);
    std::cout << "6. Enhanced insertion sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    enhanced_insertion_sort(numbers);
    std::cout << "Sorted number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << std::endl;
    
    shuffle_numbers(numbers);
    std::cout << "7. Division sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << "Sorted number sequence: ";
    print_vector(division_sort(numbers));
    std::cout << std::endl;
    std::cout << std::endl;

    shuffle_numbers(numbers_multiset);
    std::cout << "8. Counting division sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers_multiset);
    std::cout << std::endl;
    std::cout << "Sorted number sequence: ";
    print_vector(counting_division_sort(numbers_multiset, 6));
    std::cout << std::endl;
    std::cout << std::endl;
    
    shuffle_numbers(numbers);
    std::cout << "9. Counting sort" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << "Sorted number sequence: ";
    print_vector(counting_sort(numbers));
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "10. Logarithmic search on ordered sequence" << std::endl;
    std::cout << "Initial number sequence: ";
    simple_swap_sort(numbers);
    print_vector(numbers);
    std::cout << std::endl;
    int LOGARITHMIC_SEARCHED_NUMBER = 10;
    found_item logarithmic_item = logarithmic_search(numbers, LOGARITHMIC_SEARCHED_NUMBER);
    std::cout << "The number: " << LOGARITHMIC_SEARCHED_NUMBER
                                << (logarithmic_item.found ? " can " : " can't ") << "be found in the sequence";
    std::cout << std::endl;
    logarithmic_item.found ? std::cout << "On position: " << logarithmic_item.index + 1 << std::endl : std::cout << "";
    std::cout << std::endl;

    std::cout << "11. Binary search on ordered sequence" << std::endl;
    std::cout << "Initial number sequence: ";
    print_vector(numbers);
    std::cout << std::endl;
    int BINARY_SEARCHED_NUMBER = 1;
    found_item binary_item = binary_search(numbers, BINARY_SEARCHED_NUMBER);
    std::cout << "The number: " << BINARY_SEARCHED_NUMBER
                                << (binary_item.found ? " can " : " can't ") << "be found in the sequence";
    std::cout << std::endl;
    binary_item.found ? std::cout << "On position: " << binary_item.index + 1 << std::endl : std::cout << "";
    std::cout << std::endl;

    return 0;
}