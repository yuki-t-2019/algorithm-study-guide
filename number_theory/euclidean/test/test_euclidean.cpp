/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_euclidean.cpp
 */

#include <gtest/gtest.h>
#include "src/euclidean.h"

class EuclideanTest : public ::testing::Test {
 protected:
  void SetUp() override {
    // Initialize any common resources for tests if needed
  }

  void TearDown() override {
    // Clean up common resources for tests if needed
  }
};

/**
 * @brief Tests the GCD function with various inputs.
 */
TEST_F(EuclideanTest, TestGCD) {
  EXPECT_EQ(GCD(48, 18), 6);
  EXPECT_EQ(GCD(7, 3), 1);
  EXPECT_EQ(GCD(100, 25), 25);
  EXPECT_EQ(GCD(0, 10), 10);
  EXPECT_EQ(GCD(10, 0), 10);
  EXPECT_EQ(GCD(0, 0), 0);
}

/**
 * @brief Tests the Euclidean function with known inputs and outputs.
 */
TEST_F(EuclideanTest, TestEuclidean) {
  EXPECT_EQ(Euclidean(1, 11, 5, 3), 3);
}

/**
 * @brief Tests the InputValidation function with various inputs.
 */
TEST_F(EuclideanTest, TestInputValidation) {
  EXPECT_TRUE(InputValidation(0, 0, 6, 8));
  EXPECT_TRUE(InputValidation(MIN_COORD, MIN_COORD, MAX_COORD, MAX_COORD));
  EXPECT_FALSE(InputValidation(MIN_COORD - 1, 0, 0, 0));
  EXPECT_FALSE(InputValidation(MAX_COORD + 1, 0, 0, 0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

