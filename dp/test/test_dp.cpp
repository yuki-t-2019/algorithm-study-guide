/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_dp.cpp
 */

#include <gtest/gtest.h>
#include "src/dp.h"

class DpTest : public ::testing::Test {
 protected:
  std::vector<Item> items;
  int max_weight;

  void SetUp() override {
    // Initialize common resources for tests
  }

  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(DpTest, BasicCase) {
  items = {{2, 3}, {1, 2}, {3, 3}, {2, 2}};
  max_weight = 5;
  EXPECT_EQ(dp(items, max_weight), 7);
}

TEST_F(DpTest, SingleItemFits) {
  items = {{5, 10}};
  max_weight = 5;  // Only one item, it fits exactly
  EXPECT_EQ(dp(items, max_weight), 10);
}

TEST_F(DpTest, SingleItemDoesNotFit) {
  items = {{6, 10}};
  max_weight = 5;  // Only one item, it does not fit
  EXPECT_EQ(dp(items, max_weight), 0);
}

TEST_F(DpTest, MaximumConstraintsCase) {
  std::vector<Item> items(100);
  for (int i = 0; i < 100; ++i) {
    items[i] = {100, 100};
  }
  max_weight = 10000;  // Max value is 10000
  EXPECT_EQ(dp(items, max_weight), 10000);
}

TEST_F(DpTest, ZeroWeightCapacity) {
  items = {{2, 3}, {1, 2}, {3, 4}, {2, 2}};
  max_weight = 0;  // No items can be added
  EXPECT_EQ(dp(items, max_weight), 0);
}

TEST_F(DpTest, ZeroItems) {
  items = {};
  max_weight = 10;  // No items to add
  EXPECT_EQ(dp(items, max_weight), -1);
}

TEST_F(DpTest, ExceedingMaxWeightCase) {
  items = {{1, 1}, {2, 2}};
  max_weight = 10001;  // Exceeds max weight capacity
  EXPECT_EQ(dp(items, max_weight), -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
