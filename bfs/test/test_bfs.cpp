/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_bfs.cpp
 */

#include <gtest/gtest.h>
#include "src/bfs.h"

class BfsTest : public ::testing::Test {
 protected:
  int n_;
  int m_;
  char maze_[kMaxN + 1][kMaxM + 1];
  int start_x_, start_y_, goal_x_, goal_y_;

  void SetUp() override {
    n_ = 10;
    m_ = 10;
    snprintf(maze_[0], sizeof(maze_[0]), "#S######+#");
    snprintf(maze_[1], sizeof(maze_[1]), "++++++#++#");
    snprintf(maze_[2], sizeof(maze_[2]), "+#+##+##+#");
    snprintf(maze_[3], sizeof(maze_[3]), "+#++++++++");
    snprintf(maze_[4], sizeof(maze_[4]), "##+##+####");
    snprintf(maze_[5], sizeof(maze_[5]), "++++#++++#");
    snprintf(maze_[6], sizeof(maze_[6]), "+#######+#");
    snprintf(maze_[7], sizeof(maze_[7]), "++++#+++++");
    snprintf(maze_[8], sizeof(maze_[8]), "+####+###+");
    snprintf(maze_[9], sizeof(maze_[9]), "++++#+++G#");
    start_x_ = start_y_ = goal_x_ = -1;
  }

  void TearDown() override {
    // No dynamic memory or resources to free in this test case
    // If there were resources to release, they would be released here
  }
};

TEST_F(BfsTest, MazeSizeWithinConstraints) {
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  ASSERT_NO_THROW(
    InputValidation(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_));
}

TEST_F(BfsTest, StartPositionExists) {
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  ASSERT_NE(start_x_, -1);
  ASSERT_NE(start_y_, -1);
}

TEST_F(BfsTest, GoalPositionExists) {
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  ASSERT_NE(goal_x_, -1);
  ASSERT_NE(goal_y_, -1);
}

TEST_F(BfsTest, NSizeOutOfConstraints) {
  n_ = 101;  // Exceeds the constraint
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  EXPECT_THROW(
    InputValidation(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_),
    std::invalid_argument);
}

TEST_F(BfsTest, MSizeOutOfConstraints) {
  m_ = 101;  // Exceeds the constraint
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  EXPECT_THROW(
    InputValidation(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_),
    std::invalid_argument);
}

TEST_F(BfsTest, NSizeOutOfConstraintsNegativeOrZero) {
  n_ = 0;  // n_ is zero
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  EXPECT_THROW(
    InputValidation(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_),
    std::invalid_argument);
}

TEST_F(BfsTest, MSizeOutOfConstraintsNegativeOrZero) {
  m_ = 0;  // m_ is zero
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  EXPECT_THROW(
    InputValidation(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_),
    std::invalid_argument);
}

TEST_F(BfsTest, StartPositionNotFound) {
  snprintf(maze_[0], sizeof(maze_[0]), "########+#");  // Start position removed
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  EXPECT_THROW(
    InputValidation(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_),
    std::runtime_error);
}

TEST_F(BfsTest, GoalPositionNotFound) {
  snprintf(maze_[9], sizeof(maze_[9]), "++++#+++##");  // Goal position removed
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  EXPECT_THROW(
    InputValidation(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_),
    std::runtime_error);
}

TEST_F(BfsTest, ShortestPathExists) {
  FindStartAndGoal(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_);
  ASSERT_NO_THROW(
    InputValidation(n_, m_, maze_, &start_x_, &start_y_, &goal_x_, &goal_y_));

  // Execute BFS algorithm
  int result = Bfs(n_, m_, maze_);

  EXPECT_EQ(result, 22);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
