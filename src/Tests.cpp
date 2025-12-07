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

TEST_F(AlgorithmsTest, insertionSortDecreasing) {
  DSA::insertionSortDecreasing(input.begin(), input.end());
  EXPECT_TRUE(std::is_sorted(input.begin(), input.end(), std::greater<>()));
  // std::print("{}", input);
}