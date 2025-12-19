#pragma once

#include <iterator>
#include <vector>

/* Section 2.1 */
namespace DSA { // Data Structures and Algorithms
template <typename RandomIt> void insertionSort(RandomIt begin, RandomIt end) {
  for (auto it = begin + 1; it != end; it++) {
    // This is the position to be inserted into the [0, i] subarray
    auto key = *it;
    auto j = it;
    while (j > begin and *(j - 1) > key) {
      // Move the element to the right if its higher than key
      *j = *(j - 1);
      j--;
    }
    // This is the position to insert the key
    *j = key;
  }
}

template <typename RandomIt>
void insertionSortDecreasing(RandomIt begin, RandomIt end) {
  for (auto it = begin + 1; it != end; it++) {
    // This is the position to be inserted into the [0, i] subarray
    auto key = *it;
    auto j = it;
    while (j > begin and *(j - 1) < key) {
      // Move the element to the right if its higher than key
      *j = *(j - 1);
      j--;
    }
    // This is the position to insert the key
    *j = key;
  }
}

template <typename T>
std::vector<T> sumBinaryNumbers(const std::vector<T> numA,
                                const std::vector<T> numB) {
  T carry = 0;
  std::vector<T> result(numA.size());
  for (size_t i = 0; i < result.size(); i++) {
    T sum = carry + numA[i] + numB[i];
    result[i] = sum % 2;
    carry = sum / 2;
  }

  if (carry) {
    result.push_back(carry);
  }

  return result;
}

// Exercise 2.2-2
template <typename T> void selectionSort(std::vector<T> &elements) {
  for (std::size_t i = 0; i < elements.size() - 1; ++i) {
    std::size_t selectionIndex = i;
    for (std::size_t j = i; j < elements.size(); ++j) {
      if (elements[j] < elements[selectionIndex]) {
        selectionIndex = j;
      }
    }

    if (selectionIndex != i) {
      std::swap(elements[i], elements[selectionIndex]);
    }
  }
}
} // namespace DSA
