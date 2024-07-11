/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_sieve-of-eratosthenes.cpp
 */

#include <gtest/gtest.h>
#include "src/sieve-of-eratosthenes.h"

class SieveOfEratosthenesTest : public ::testing::Test {
 protected:
  int n;

  void SetUp() override {
    // Initialize default values for tests
    n = 1000000;
  }

  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(SieveOfEratosthenesTest, BasicPrimeCount) {
  // Test basic prime count up to n
  EXPECT_TRUE(InputValidation(n));
  EXPECT_EQ(SieveOfEratosthenes(n), 78498);
}

TEST_F(SieveOfEratosthenesTest, MinValue) {
  // Test the validation of input where n is at its minimum value
  n = 1;
  EXPECT_TRUE(InputValidation(n));
  EXPECT_EQ(SieveOfEratosthenes(n), 0);
}

TEST_F(SieveOfEratosthenesTest, MaxValue) {
  // Test the validation of input where n exceeds the maximum allowed
  n = kMaxN;
  EXPECT_TRUE(InputValidation(n));
}

TEST_F(SieveOfEratosthenesTest, OverMaxValue) {
  // Test the validation of input where n exceeds the maximum allowed
  n = kMaxN + 1;
  EXPECT_FALSE(InputValidation(n));
}

TEST_F(SieveOfEratosthenesTest, InvalidInput) {
  // Test invalid input
  n = -1;
  EXPECT_FALSE(InputValidation(n));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
