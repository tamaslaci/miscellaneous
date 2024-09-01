//
// Assort apart (in place) algorithm
// which uses the input array variable as the output array
// and assort the elements to the front and back by the given property
//
// input: N, X[1..N]
// output: COUNT, Y[1..N]
// COUNT = SUM[1..N] 1 : T(X[i]) , Y = Permutation(X)
// i(1 <= i <= COUNT): T(Y[i])
// i(COUNT + 1 <= i <= N): not T(Y[i])
// Y = X, same variable, modified content sequence
//

#include "assort_apart_in_place.h"

bool search_from_back(int& front, int& back, const std::vector<int>& numbers){  // input: e, u, X[1..N]
    while(front < back && numbers.at(back) % 2 != 0){                           // e < u -> L, T(X[u])
        --back;                                                                 // u := u - 1
    }
    return front < back;                                                        // output: FOUND := e < u
}

bool search_from_front(int& front, int& back, const std::vector<int>& numbers){ // input: e, u, X[1..N]
    while(front < back && numbers.at(front) % 2 == 0){                          // e < u -> L, T(X[e])
        ++front;                                                                // e := e + 1
    }
    return front < back;                                                        // output: FOUND := e < u
}

int assort_apart_in_place(std::vector<int>& numbers){       // input: N, X[1..N]
    int front = 0;                                          // e := 1; first in assort
    int back = numbers.size() - 1;                          // u := N; last in assort
    int start = numbers.at(front);                          // y := X[e]; first taken out element
    while(front < back){                                    // e < u -> L
        if(search_from_back(front, back, numbers)){         // FoundFromBack(e, u, FOUND)
            numbers.at(front) = numbers.at(back);           // X[e] := X[u]
            ++front;                                        // e := e + 1
            if(search_from_front(front, back, numbers)){    // FoundFromFront(e, u, FOUND)
                numbers.at(back) = numbers.at(front);       // X[u] := X[e]
                --back;                                     // u := u - 1
            }
        }
    }
    numbers.at(front) = start;                              // X[e] := y; filling the last (first) element in place
    return numbers.at(front) % 2 == 0 ? front + 1 : front;  // output: T(y) -> COUNT, Y[1..N] (Y = X)
}

int main(){
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    std::vector<int> even_numbers = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};           // stability check 1
    std::vector<int> odd_numbers = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};             // stability check 2

    std::cout << std::endl;
    std::cout << "Assort apart a number sequence in place as evens and odds\n(first part evens, second part odds)" << std::endl;
    std::cout << std::endl;
    std::cout << "Initial number sequence:" << std::endl;
    std::cout << "< ";
    for(int i : numbers){
        std::cout << i << " ";
    }
    std::cout << ">" << std::endl;
    std::cout << std::endl;
    std::cout << "Sorted number sequence:" << std::endl;
    int count = assort_apart_in_place(numbers);
    std::cout << "< ";
    for(int i : numbers){
        std::cout << i << " ";
    }
    std::cout << ">" << std::endl;
    std::cout << "Number of evens: " << count << std::endl;
    std::cout << "Number of odds: " << numbers.size() - count << std::endl;
    std::cout << std::endl;
    
    // Stability check 1 - swapping first and last elements with evens
    int count_evens = assort_apart_in_place(even_numbers);
    std::cout << std::endl;
    std::cout << "Checking function with full of evens:" << std::endl;
    std::cout << "< ";
    for(int i : even_numbers){
        std::cout << i << " ";
    }
    std::cout << ">" << std::endl;
    std::cout << "Number of evens: " << count_evens << std::endl;
    std::cout << "Number of odds: " << even_numbers.size() - count_evens << std::endl;
    std::cout << std::endl;

    //Stability check 2 - no elements swapped
    int count_odds = assort_apart_in_place(odd_numbers);
    std::cout << std::endl;
    std::cout << "Checking function with full of odds:" << std::endl;
    std::cout << "< ";
    for(int i : odd_numbers){
        std::cout << i << " ";
    }
    std::cout << ">" << std::endl;
    std::cout << "Number of evens: " << count_odds << std::endl;
    std::cout << "Number of odds: " << odd_numbers.size() - count_odds << std::endl;
    std::cout << std::endl;
    return 0;
}