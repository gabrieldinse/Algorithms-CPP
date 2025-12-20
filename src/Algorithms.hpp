#pragma once

#include <iterator>
#include <optional>
#include <vector>

/* Section 2.1 */
namespace DSA { // Data Structures and Algorithms
template <typename T> void insertionSort(std::vector<T> &elements) {
  for (std::size_t i = 1; i != elements.size(); i++) {
    // This is the position to be inserted into the [0, i] subarray
    T key = elements[i];
    auto j = i;
    while (j > 0 and elements[j - 1] > key) {
      // Move the element to the right if its higher than key
      elements[j] = elements[j - 1];
      j--;
    }

    // This is the position to insert the key
    elements[j] = key;
  }
}

// Testing purposes
template <typename RandomIt>
void insertionSortIt(RandomIt begin, RandomIt end) {
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

// Section 2.3.1 - Merge sort
template <typename T>
void merge(std::vector<T> &elements, std::size_t leftPos, std::size_t midPos,
           std::size_t rightPos) {
  std::vector<T> left(elements.begin() + leftPos,
                      elements.begin() + midPos + 1);
  std::vector<T> right(elements.begin() + midPos + 1,
                       elements.begin() + rightPos + 1);

  std::size_t i = 0;
  std::size_t j = 0;
  std::size_t k = leftPos;
  // The first time merge is called, the piles will have a single element (yet
  // leftPos < rightPos). This guarantees left and right will always be sorted
  // for consecutive merges and this is how elements will be entirely sorted in
  // the end.
  // The range elements[0:k] will always be sorted
  while (i < left.size() and j < right.size()) {
    if (elements[i] < elements[j]) {
      elements[k] = elements[i];
      i++;
    } else {
      elements[k] = elements[j];
      j++;
    }
    k++;
  }

  // If either left or right still contains elements, we know that:
  // 1- Their elements are sorted
  // 2- All their elements are greather than the range elements[0:k]
  // This means left or right can be simply copied to elements[k+1:rightPos]
  while (i < left.size()) {
    elements[k] = elements[i];
    i++;
    k++;
  }

  while (j < right.size()) {
    elements[k] = elements[j];
    j++;
    k++;
  }
}

template <typename T>
void mergeSort(std::vector<T> &elements, std::size_t leftPos,
               std::size_t rightPos) {
  if (leftPos >= rightPos) {
    return;
  }

  std::size_t midPos = (leftPos + rightPos) / 2;
  mergeSort(elements, leftPos, midPos);
  mergeSort(elements, midPos + 1, rightPos);

  merge(elements, leftPos, midPos, rightPos);
}

// Exercise 2.3-5
template <typename T>
void recursiveInsertionSort(std::vector<T> &elements, std::size_t rightPos) {
  if (rightPos == 0) {
    return;
  }

  recursiveInsertionSort(elements, rightPos - 1);

  T key = elements[rightPos];
  while (rightPos > 0 and elements[rightPos - 1] > key) {
    // Move the element to the right if its higher than key
    elements[rightPos] = elements[rightPos - 1];
    rightPos--;
  }

  // This is the position to insert the key
  elements[rightPos] = key;
}

// Exercise 2.3-6
template <typename T>
std::optional<std::size_t> binarySearch(const std::vector<T> sortedElements,
                                        T lookupValue, std::size_t leftPos,
                                        std::size_t rightPos) {
  if (leftPos == rightPos) {
    return std::nullopt;
  }

  std::size_t middlePos = (leftPos + rightPos) / 2;
  T middleValue = sortedElements[middlePos];
  if (middleValue == lookupValue) {
    return middlePos;
  }

  if (lookupValue < middleValue) {
    return binarySearch(sortedElements, lookupValue, leftPos, middlePos);
  }

  return binarySearch(sortedElements, lookupValue, middlePos + 1, rightPos);
}
} // namespace DSA
