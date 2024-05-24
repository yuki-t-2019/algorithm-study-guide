/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_greedy.cpp
 */

#include <gtest/gtest.h>
#include "src/greedy.h"

class GreedyTest : public ::testing::Test {
 protected:
  std::vector<Coin> coins;
  int target_amount;
  
  void SetUp() override {
    // Initialize common resources for tests
  }
  
  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(GreedyTest, BasicCase) {
  coins = {{100, 10}, {50, 10}, {25, 10}, {10, 10}, {5, 10}, {1, 10}};
  target_amount = 287; // 2*100 + 1*50 + 1*25 + 1*10 + 2*1 = 7 coins
  EXPECT_EQ(Greedy(coins, target_amount), 7);
}

TEST_F(GreedyTest, InsufficientCoinsCase) {
  coins = {{100, 1}, {50, 1}, {25, 1}, {10, 1}, {5, 1}, {1, 1}};
  target_amount = 287; // Not enough coins
  EXPECT_EQ(Greedy(coins, target_amount), -1);
}

TEST_F(GreedyTest, MaximumConstraintsCase) {
  coins = {{100, 1000000000}, {50, 1000000000}, {25, 1000000000},
           {10, 1000000000}, {5, 1000000000}, {1, 1000000000}};
  target_amount = 1000000000; // 10000000*100 = 10000000 coins
  EXPECT_EQ(Greedy(coins, target_amount), 10000000);
}

TEST_F(GreedyTest, ZeroCoinsCase) {
  coins = {{100, 0}, {50, 0}, {25, 0}, {10, 0}, {5, 0}, {1, 0}};
  target_amount = 50; // Not enough coins
  EXPECT_EQ(Greedy(coins, target_amount), -1);
}

TEST_F(GreedyTest, ZeroTargetAmountCase) {
  coins = {{100, 10}, {50, 10}, {25, 10}, {10, 10}, {5, 10}, {1, 10}};
  target_amount = 0; // No coins needed
  EXPECT_EQ(Greedy(coins, target_amount), 0);
}

TEST_F(GreedyTest, ExceedingMaxCoinsCase) {
  coins = {{100, 1000000001}, {50, 1000000001}, {25, 1000000001},
           {10, 1000000001}, {5, 1000000001}, {1, 1000000001}};
  target_amount = 1000; // Input exceeds constraints
  EXPECT_EQ(Greedy(coins, target_amount), -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
