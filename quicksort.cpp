#include "quicksort.h"

void quicksort(std::vector<int>& numbers) {                     // A : T[n]
  quicksort(numbers, 0, numbers.size() - 1);                    // Sort A[0..(n-1)]
}

void quicksort(std::vector<int>& numbers, int start, int end) { // A : T[n]; p, r : int; Sort A[p..r]
  if (start < end) {                                            // p < r
    int pivot = partition(numbers, start, end);                 // q := partition(A, p, r)
    quicksort(numbers, start, pivot - 1);                       // quicksort(A, p, q - 1)
    quicksort(numbers, pivot + 1, end);                         // quicksort(A, q + 1, r)
  }
}

int partition(std::vector<int>& numbers, int start, int end) {  // (A : T[n]; p, r : int) -> int
  int i = std::rand() % (end - start) + start;                  // i := random(p, r)
  std::swap(numbers.at(i), numbers.at(end));                    // swap(A[i], A[r])
  i = start;                                                    // i := p
  while (i < end &&
         numbers.at(i) <= numbers.at(end)) {                    // i < r and A[i] <= A[r]
    ++i;                                                        // i := i + 1
  }
  if (i < end) {                                                // i < r
    int j = i + 1;                                              // j := i + 1
    while (j < end) {                                           // j < r
      if (numbers.at(j) < numbers.at(end)) {                    // A[j] < A[r]
        std::swap(numbers.at(i), numbers.at(j));                // swap(A[i], A[j])
        ++i;                                                    // i := i + 1
      }
      ++j;                                                      // j := j + 1
    }
    std::swap(numbers.at(i), numbers.at(end));                  // swap(A[i], A[r])
  }                                                             // else i == end, A[p..r) <= A[r]
  return i;
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
    std::cout << "Initial vector before quicksort: ";
    print_vector(numbers);
    std::cout << std::endl;

    quicksort(numbers);

    std::cout << "Vector after quicksort: ";
    print_vector(numbers);
    std::cout << std::endl;
    std::cout << std::endl;
}