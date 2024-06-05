/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_bst.cpp
 */

#include <gtest/gtest.h>
#include "src/bst.h"

class BSTTest : public ::testing::Test {
 protected:
  std::vector<std::pair<int, int>> queries;
  int Q;

  void SetUp() override {
    // Initialize default values for tests
    Q = 5;
    queries = {{1, 11}, {1, 29}, {1, 89}, {2, 2}, {2, 2}};
  }

  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(BSTTest, BasicInsertAndFind) {
  // Test basic insertion and finding the k-th smallest elements
  EXPECT_NO_THROW(InputValidation(Q, queries));
  EXPECT_EQ(bst(Q, queries), 0);
}

TEST_F(BSTTest, InsertDuplicate) {
  // Test inserting a duplicate element which should throw an error
  queries.push_back({1, 11});
  Q++;
  EXPECT_THROW(InputValidation(Q, queries), std::invalid_argument);
}

TEST_F(BSTTest, FindKthSmallestWithInsufficientElements) {
  // Test finding k-th smallest element with insufficient elements in the set
  queries = {{1, 11}, {1, 29}, {2, 3}};
  Q = 3;
  EXPECT_THROW(InputValidation(Q, queries), std::out_of_range);
}

TEST_F(BSTTest, MinNumberOfQueries) {
  // Test the validation of input where the number of queries is less than the minimum allowed
  Q = MIN_QUERY - 1;
  EXPECT_THROW(InputValidation(Q, queries), std::invalid_argument);
}

TEST_F(BSTTest, MaxNumberOfQueries) {
  // Test the validation of input where the number of queries exceeds the maximum allowed
  Q = MAX_QUERY + 1;
  EXPECT_THROW(InputValidation(Q, queries), std::invalid_argument);
}

TEST_F(BSTTest, MinQueryValue) {
  // Test the validation of input where the query value is less than the minimum allowed
  queries = {{1, MIN_NUMBER - 1}};
  EXPECT_THROW(InputValidation(Q, queries), std::invalid_argument);
}

TEST_F(BSTTest, MaxQueryValue) {
  // Test the validation of input where the query value exceeds the maximum allowed
  queries = {{1, MAX_NUMBER + 1}};
  EXPECT_THROW(InputValidation(Q, queries), std::invalid_argument);
}

TEST_F(BSTTest, InvalidQueryType) {
  // Test the validation of input where the query type is invalid
  queries = {{3, 11}};
  EXPECT_THROW(InputValidation(Q, queries), std::invalid_argument);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
