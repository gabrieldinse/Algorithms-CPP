#include <algorithm>
#include <print>

#include "gtest/gtest.h"

#include "Algorithms.hpp"
#include "Utils.hpp"

class AlgorithmsTest : public testing::Test {
protected:
  static constexpr size_t inputSize = 10000;
  static std::vector<int> originalInput;
  // Use this one for each test
  std::vector<int> input;

  static void SetUpTestSuite() {
    originalInput = Utils::randomVector(inputSize);
  }

  void SetUp() override {
    input = originalInput; // fresh copy
  }
};

std::vector<int> AlgorithmsTest::originalInput;

TEST_F(AlgorithmsTest, InsertionSort) {
  DSA::insertionSort(input);
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end()));
  // std::print("{}", input);
}

TEST_F(AlgorithmsTest, InsertionSortIt) {
  DSA::insertionSortIt(input.begin(), input.end());
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end()));
  // std::print("{}", input);
}

TEST_F(AlgorithmsTest, InsertionSortDecreasing) {
  DSA::insertionSortDecreasing(input.begin(), input.end());
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end(), std::greater<>()));
  // std::print("{}", input);
}

TEST_F(AlgorithmsTest, SumBinaryNumbers) {
  std::vector<int> numA = {1, 0, 1, 1};           // 13
  std::vector<int> numB = {1, 1, 0, 1};           // 11
  std::vector<int> expectedSum = {0, 0, 0, 1, 1}; // 24
  auto result = DSA::sumBinaryNumbers(numA, numB);
  EXPECT_EQ(result, expectedSum);
}

TEST_F(AlgorithmsTest, SelectionSort) {
  DSA::selectionSort(input);
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end()));
  // std::print("{}", input);
}

TEST_F(AlgorithmsTest, MergeSort) {
  DSA::mergeSort(input, 0, input.size() - 1);
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end()));
  // std::print("{}", input);
}

TEST_F(AlgorithmsTest, RecursiveInsertionSort) {
  DSA::recursiveInsertionSort(input, input.size() - 1);
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end()));
  // std::print("{}", input);
}

TEST_F(AlgorithmsTest, BinarySearch) {
  std::size_t targetPos = inputSize / 2;
  int target = input[targetPos];
  DSA::insertionSort(input);
  auto result = DSA::binarySearch(input, target, 0, input.size() - 1);
  EXPECT_TRUE(result.has_value());
  EXPECT_EQ(input[result.value()], target);
}

TEST_F(AlgorithmsTest, TwoSumSorting) {
  int targetSum = input[1200] + input[9000];
  bool result = DSA::twoSumSorting(input, targetSum);
  EXPECT_TRUE(result);

  targetSum = -1; // impossible sum
  result = DSA::twoSumSorting(input, targetSum);
  EXPECT_FALSE(result);

  int targetSum2 = input[0] + input[1];
  ;
  result = DSA::twoSumSorting(input, targetSum2);
  EXPECT_TRUE(result);
}

TEST_F(AlgorithmsTest, MergeSortWithInsertionSort) {
  const std::size_t k = 10;
  DSA::mergeSortWithInsertionSort(input, 0, input.size() - 1, k);
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end()));
  // std::print("{}", input);
}

TEST_F(AlgorithmsTest, Bubblesort) {
  DSA::bubblesort(input);
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end()));
  // std::print("{}", input);
}