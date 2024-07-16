/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_binary_search.cpp
 */

#include <gtest/gtest.h>
#include "src/binary_search.h"

class BinarySearchTest : public ::testing::Test {
 protected:
  int n;
  int k;
  std::vector<int> array;

  void SetUp() override {
    // Initialize default values for tests
    n = 5;
    k = 3;
    array = {2, 3, 3, 5, 6};
  }

  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(BinarySearchTest, BasicBinarySearch) {
  // Test basic binary search operation
  EXPECT_TRUE(InputValidation(n, k, array));
  EXPECT_EQ(BinarySearch(n, k, array), 1);
}

TEST_F(BinarySearchTest, NoElementGreaterOrEqual) {
  // Test case where no element is greater or equal to k
  k = 7;
  EXPECT_TRUE(InputValidation(n, k, array));
  EXPECT_EQ(BinarySearch(n, k, array), n);
}

TEST_F(BinarySearchTest, AllElementsGreaterOrEqual) {
  // Test case where all elements are greater or equal to k
  k = 1;
  EXPECT_TRUE(InputValidation(n, k, array));
  EXPECT_EQ(BinarySearch(n, k, array), 0);
}

TEST_F(BinarySearchTest, SingleElementArray) {
  // Test case with a single element array
  n = 1;
  array = {5};
  k = 5;
  EXPECT_TRUE(InputValidation(n, k, array));
  EXPECT_EQ(BinarySearch(n, k, array), 0);

  k = 6;
  EXPECT_TRUE(InputValidation(n, k, array));
  EXPECT_EQ(BinarySearch(n, k, array), 1);
}

TEST_F(BinarySearchTest, ArrayWithDuplicateElements) {
  // Test case with an array containing duplicate elements
  array = {2, 2, 2, 2, 2};
  k = 2;
  EXPECT_TRUE(InputValidation(n, k, array));
  EXPECT_EQ(BinarySearch(n, k, array), 0);
}

TEST_F(BinarySearchTest, MinNumberOfElements) {
  // Test the validation of input where the number of elements
  // is less than the minimum allowed
  n = 0;
  EXPECT_FALSE(InputValidation(n, k, array));
}

TEST_F(BinarySearchTest, MaxNumberOfElements) {
  // Test the validation of input where the number of elements
  // exceeds the maximum allowed
  n = 1000001;
  EXPECT_FALSE(InputValidation(n, k, array));
}

TEST_F(BinarySearchTest, ElementOutOfRange) {
  // Test the validation of input where an element is out of range
  array = {2, 3, 3, 5, 1000000001};
  EXPECT_FALSE(InputValidation(n, k, array));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
