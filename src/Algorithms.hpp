#pragma once

#include <algorithm>
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
void merge(std::vector<T> &elements, std::size_t leftPos, std::size_t middlePos,
           std::size_t rightPos) {
  std::vector<T> left(elements.begin() + leftPos,
                      elements.begin() + middlePos + 1);
  std::vector<T> right(elements.begin() + middlePos + 1,
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
    if (left[i] < right[j]) {
      elements[k] = left[i];
      i++;
    } else {
      elements[k] = right[j];
      j++;
    }
    k++;
  }

  // If either left or right still contains elements, we know that:
  // 1- Their elements are sorted
  // 2- All their elements are greather than the range elements[0:k]
  // This means left or right can be simply copied to elements[k+1:rightPos]
  while (i < left.size()) {
    elements[k] = left[i];
    i++;
    k++;
  }

  while (j < right.size()) {
    elements[k] = right[j];
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

  std::size_t middlePos = (rightPos - leftPos) / 2 + leftPos;
  mergeSort(elements, leftPos, middlePos);
  mergeSort(elements, middlePos + 1, rightPos);

  merge(elements, leftPos, middlePos, rightPos);
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
std::optional<std::size_t> binarySearch(const std::vector<T> &sortedElements,
                                        T lookupValue, std::size_t leftPos,
                                        std::size_t rightPos) {
  if (leftPos > rightPos) {
    return std::nullopt;
  }

  // Calculate the middle position to avoid the overflow that could be caused by
  // (leftPos + rightPos) / 2
  std::size_t middlePos = (rightPos - leftPos) / 2 + leftPos;
  T middleValue = sortedElements[middlePos];
  if (middleValue == lookupValue) {
    return middlePos;
  }

  if (lookupValue < middleValue) {
    return binarySearch(sortedElements, lookupValue, leftPos, middlePos);
  }

  return binarySearch(sortedElements, lookupValue, middlePos + 1, rightPos);
}

// Exercise 2.3-8
template <typename T>
bool twoSumSorting(std::vector<T> &elements, T targetSum) {
  std::size_t leftPos = 0;
  std::size_t rightPos = elements.size() - 1;
  mergeSort(elements, leftPos, rightPos);

  while (leftPos < rightPos) {
    T sum = elements[leftPos] + elements[rightPos];
    if (sum == targetSum) {
      return true;
    }

    if (sum < targetSum) {
      leftPos++;
    } else {
      rightPos--;
    }
  }

  return false;
}

// Problem 2-1
template <typename T>
void mergeSortWithInsertionSort(std::vector<T> &elements, std::size_t leftPos,
                                std::size_t rightPos, std::size_t k) {
  if (rightPos - leftPos + 1 <= k) {
    // This insertion sort expects iterators, so we should use right + 1 (past
    // end)
    insertionSortIt(elements.begin() + leftPos,
                    elements.begin() + rightPos + 1);
  } else {
    std::size_t middlePos = (rightPos - leftPos) / 2 + leftPos;
    mergeSortWithInsertionSort(elements, leftPos, middlePos, k);
    mergeSortWithInsertionSort(elements, middlePos + 1, rightPos, k);

    merge(elements, leftPos, middlePos, rightPos);
  }
}

// Problem 2-2
template <typename T> void bubblesort(std::vector<T> &elements) {
  for (std::size_t i = 1; i < elements.size() - 1; i++) {
    for (std::size_t j = elements.size() - 1; j >= i; j--) {
      if (elements[j] < elements[j - 1]) {
        std::swap(elements[j], elements[j - 1]);
      }
    }
  }
}

// Problem 2-4.d) Count the number of inversions in an array using merge sort
template <typename T>
std::size_t mergeAndCountInversions(std::vector<T> &elements,
                                    std::size_t leftPos, std::size_t middlePos,
                                    std::size_t rightPos) {
  std::vector<T> left(elements.begin() + leftPos,
                      elements.begin() + middlePos + 1);
  std::vector<T> right(elements.begin() + middlePos + 1,
                       elements.begin() + rightPos + 1);

  std::size_t i = 0;
  std::size_t j = 0;
  std::size_t k = leftPos;
  std::size_t inversions = 0;

  while (i < left.size() and j < right.size()) {
    if (left[i] < right[j]) {
      // No inversions, because left[i] is smaller than all remaining elements
      // in right
      elements[k] = left[i];
      i++;
    } else {
      // Every remaining element in left is greater than right[j]
      inversions += (left.size() - i);
      elements[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < left.size()) {
    // These leftovers where already counted in the first while loop
    elements[k] = left[i];
    i++;
    k++;
  }

  while (j < right.size()) {
    elements[k] = right[j];
    j++;
    k++;
  }

  return inversions;
}

template <typename T>
std::size_t countInversions(std::vector<T> &elements, std::size_t leftPos,
                            std::size_t rightPos) {
  if (leftPos >= rightPos) {
    return 0;
  }

  std::size_t middlePos = (rightPos - leftPos) / 2 + leftPos;
  std::size_t inversionsLeft = countInversions(elements, leftPos, middlePos);
  std::size_t inversionsRight =
      countInversions(elements, middlePos + 1, rightPos);

  std::size_t inversionsSplit =
      mergeAndCountInversions(elements, leftPos, middlePos, rightPos);

  return inversionsLeft + inversionsRight + inversionsSplit;
}
} // namespace DSA
