#include "merge_sort.h"

void merge_sort(std::vector<int>& numbers_a){                                                         // A : T[n]
    std::vector<int> numbers_b(numbers_a.size());                                                     // B : T[n]
    for(int i = 0; i < numbers_a.size(); ++i){                                                        // B[0..n) := A[0..n)
        numbers_b.at(i) = numbers_a.at(i);
    }
    ms(numbers_b, numbers_a, 0, numbers_a.size());                                                    // ms(B, A, 0, n)
}

void ms(std::vector<int>& numbers_b, std::vector<int>& numbers_a, int start, int end){                // B, A : T[n]; u, v : int
    // B[u..v) = A[u..v)
    // Sort B[u..v) into A[u..v) non-non-decreasingly
    if(end - start > 1){                                                                              // v - u > 1
        int middle = std::floor((start + end) / 2);                                                   // m := Floor((u + v) / 2)
        ms(numbers_a, numbers_b, start, middle);                                                      // ms(A, B, u, m)
        ms(numbers_a, numbers_b, middle, end);                                                        // ms(A, B, m, v)
        merge(numbers_b, numbers_a, start, middle, end);                                              // merge(B, A, u, m, v)
    }
}

void merge(std::vector<int>& numbers_b, std::vector<int>& numbers_a, int start, int middle, int end){ // B, A : T[n]; u, m, v : int
    // Sorted merge of B[u..m) and B[m..v) into A[u..v)
    int current = start;                                                                              // k := u copy into A[k]
    int i = start;                                                                                    // i := u from B[i]
    int j = middle;                                                                                   // j := m or from B[j]
    while(i < middle && j < end){                                                                     // i < m and j < v
        if(numbers_b.at(i) <= numbers_b.at(j)){                                                       // B[i] <= B[j]
            numbers_a.at(current) = numbers_b.at(i);                                                  // A[k] := B[i]
            ++i;                                                                                      // i := i + 1
        }else{
            numbers_a.at(current) = numbers_b.at(j);                                                  // A[k] := B[j]
            ++j;                                                                                      // j := j + 1
        }
        ++current;                                                                                    // k := k + 1
    }
    if(i < middle){                                                                                   // i < m                                                                                      
        while(i < middle){                                                                            // A[k..v) := B[i..m)
            numbers_a.at(current) = numbers_b.at(i);
            ++current;
            ++i;
        }
    }else{                                                                                            // A[k..v) := B[j..v)
        while(j < end){
            numbers_a.at(current) = numbers_b.at(j);
            ++current;
            ++j;
        }
    }
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

// merge sort and quicksort test

int main(){
    std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    shuffle_numbers(numbers);

    std::cout << std::endl;
    std::cout << "Initial vector before merge sort: ";
    print_vector(numbers);
    std::cout << std::endl;

    merge_sort(numbers);

    std::cout << "Vector after merge sort: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << std::endl;
}