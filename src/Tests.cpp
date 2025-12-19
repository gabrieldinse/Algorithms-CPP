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
  DSA::insertionSort(input.begin(), input.end());
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