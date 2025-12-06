#pragma once

#include <concepts>
#include <vector>

namespace DSA { // Data Structures and Algorithms
  template <typename T>
  requires std::totally_ordered<T>
  void insertionSort(std::vector<T> &elements) {

  }
}