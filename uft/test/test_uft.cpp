/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_uft.cpp
 */

#include <gtest/gtest.h>
#include "src/uft.h"

class UFTTest : public ::testing::Test {
 protected:
  int N;
  int k;
  std::vector<std::tuple<int, int, int>> queries;

  void SetUp() override {
    // Initialize default values for tests
    N = 100;
    k = 7;
    queries = {
      {1, 101, 1},
      {2, 1, 2},
      {2, 2, 3},
      {2, 3, 3},
      {1, 1, 3},
      {2, 3, 1},
      {1, 5, 5}
    };
  }

  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(UFTTest, BasicUnionAndFind) {
  // Test basic union and find operations
  EXPECT_TRUE(InputValidation(N, k));
  EXPECT_EQ(uft(N, k, queries), 3);
}

TEST_F(UFTTest, UnionOfSameType) {
  // Test union of animals of the same type
  queries = {
    {1, 1, 2},
    {1, 3, 4},
    {1, 5, 6}
  };
  EXPECT_TRUE(InputValidation(N, k));
  EXPECT_EQ(uft(N, k, queries), 0);
}

TEST_F(UFTTest, MinNumberOfQueries) {
  // Test the validation of input where the number of queries
  // is less than the minimum allowed
  k = MIN_K - 1;
  EXPECT_FALSE(InputValidation(N, k));
}

TEST_F(UFTTest, MaxNumberOfQueries) {
  // Test the validation of input where the number of queries
  // exceeds the maximum allowed
  k = MAX_K + 1;
  EXPECT_FALSE(InputValidation(N, k));
}

TEST_F(UFTTest, MinAnimalNumber) {
  // Test the validation of input where the animal number
  // is less than the minimum allowed
  N = MIN_N - 1;
  EXPECT_FALSE(InputValidation(N, k));
}

TEST_F(UFTTest, MaxAnimalNumber) {
  // Test the validation of input where the animal number
  // exceeds the maximum allowed
  N = MAX_N + 1;
  EXPECT_FALSE(InputValidation(N, k));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
