/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_bellman-ford.cpp
 */

#include <gtest/gtest.h>
#include "src/bellman-ford.h"

class BellmanFordTest : public ::testing::Test {
 protected:
  int N;
  int ML;
  int MD;
  std::vector<std::tuple<int, int, int>> goodRelations;
  std::vector<std::tuple<int, int, int>> badRelations;

  void SetUp() override {
    // Initialize default values for tests
    N = 4;
    ML = 2;
    MD = 1;
    goodRelations = {
        {1, 3, 10}, {2, 4, 20}
    };
    badRelations = {
        {2, 3, 3}
    };
  }

  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(BellmanFordTest, BasicInput) {
  // Test a basic scenario
  EXPECT_EQ(solve(N, ML, MD, goodRelations, badRelations), 27);
}

TEST_F(BellmanFordTest, MinNumberOfCows) {
  // Test the validation of input where the number of cows is below the minimum
  N = MIN_N - 1;
  EXPECT_FALSE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, MaxNumberOfCows) {
  // Test the validation of input where the number of cows is above the maximum
  N = MAX_N + 1;
  EXPECT_FALSE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, MinNumberOfGoodRelations) {
  // Test the validation of input where the number of good relations is below the minimum
  ML = MIN_ML_MD - 1;
  EXPECT_FALSE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, MaxNumberOfGoodRelations) {
  // Test the validation of input where the number of good relations is above the maximum
  ML = MAX_ML_MD + 1;
  EXPECT_FALSE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, MinNumberOfBadRelations) {
  // Test the validation of input where the number of bad relations is below the minimum
  MD = MIN_ML_MD - 1;
  EXPECT_FALSE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, MaxNumberOfBadRelations) {
  // Test the validation of input where the number of bad relations is above the maximum
  MD = MAX_ML_MD + 1;
  EXPECT_FALSE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, ValidGoodRelationBounds) {
  // Test valid good relation bounds
  goodRelations = {
      {1, 2, MIN_DISTANCE}, {2, 3, MAX_DISTANCE}
  };
  EXPECT_TRUE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, InvalidGoodRelationBounds) {
  // Test invalid good relation bounds
  goodRelations = {
      {0, 2, MIN_DISTANCE}, {2, 5, MAX_DISTANCE}
  };
  EXPECT_FALSE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, ValidBadRelationBounds) {
  // Test valid bad relation bounds
  badRelations = {
      {1, 2, MIN_DISTANCE}, {2, 3, MAX_DISTANCE}
  };
  EXPECT_TRUE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, InvalidBadRelationBounds) {
  // Test invalid bad relation bounds
  badRelations = {
      {0, 2, MIN_DISTANCE}, {2, 5, MAX_DISTANCE}
  };
  EXPECT_FALSE(InputValidation(N, ML, MD, goodRelations, badRelations));
}

TEST_F(BellmanFordTest, NoValidArrangement) {
  // Test a scenario where no valid arrangement exists
  badRelations = {{2, 3, 100}};
  EXPECT_TRUE(InputValidation(N, ML, MD, goodRelations, badRelations));
  EXPECT_EQ(solve(N, ML, MD, goodRelations, badRelations), -1);
}

TEST_F(BellmanFordTest, InfiniteDistance) {
  // Test a scenario where cows can be infinitely far apart
  N = 3;
  ML = 1;
  MD = 1;
  goodRelations = {{1, 2, 1}};
  badRelations = {{2, 3, 1}};
  EXPECT_EQ(solve(N, ML, MD, goodRelations, badRelations), -2);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
