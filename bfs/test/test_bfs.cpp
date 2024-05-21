/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: test_bfs.cpp
 */

#include <gtest/gtest.h>
#include <cstring>
#include "src/bfs.h"

class BfsTest : public ::testing::Test {
 protected:
  int N;
  int M;
  char maze[MAX_N][MAX_M + 1];
  int startX, startY, goalX, goalY;

  void SetUp() override {
    N = 10;
    M = 10;
    strcpy(maze[0], "#S######+#");
    strcpy(maze[1], "++++++#++#");
    strcpy(maze[2], "+#+##+##+#");
    strcpy(maze[3], "+#++++++++");
    strcpy(maze[4], "##+##+####");
    strcpy(maze[5], "++++#++++#");
    strcpy(maze[6], "+#######+#");
    strcpy(maze[7], "++++#+++++");
    strcpy(maze[8], "+####+###+");
    strcpy(maze[9], "++++#+++G#");
    startX = startY = goalX = goalY = -1;
  }

  void TearDown() override {
    // No dynamic memory or resources to free in this test case
    // If there were resources to release, they would be released here
  }
};

TEST_F(BfsTest, MazeSizeWithinConstraints) {
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  ASSERT_NO_THROW(inputValidation(N, M, maze, startX, startY, goalX, goalY));
}

TEST_F(BfsTest, StartPositionExists) {
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  ASSERT_NE(startX, -1);
  ASSERT_NE(startY, -1);
}

TEST_F(BfsTest, GoalPositionExists) {
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  ASSERT_NE(goalX, -1);
  ASSERT_NE(goalY, -1);
}

TEST_F(BfsTest, NSizeOutOfConstraints) {
  N = 101;  // Exceeds the constraint
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  EXPECT_THROW(inputValidation(N, M, maze, startX, startY, goalX, goalY), std::invalid_argument);
}

TEST_F(BfsTest, MSizeOutOfConstraints) {
  M = 101;  // Exceeds the constraint
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  EXPECT_THROW(inputValidation(N, M, maze, startX, startY, goalX, goalY), std::invalid_argument);
}

TEST_F(BfsTest, NSizeOutOfConstraintsNegativeOrZero) {
  N = 0;  // N is zero
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  EXPECT_THROW(inputValidation(N, M, maze, startX, startY, goalX, goalY), std::invalid_argument);
}

TEST_F(BfsTest, MSizeOutOfConstraintsNegativeOrZero) {
  M = 0;  // M is zero
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  EXPECT_THROW(inputValidation(N, M, maze, startX, startY, goalX, goalY), std::invalid_argument);
}

TEST_F(BfsTest, StartPositionNotFound) {
  strcpy(maze[0], "########+#");  // Start position removed
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  EXPECT_THROW(inputValidation(N, M, maze, startX, startY, goalX, goalY), std::runtime_error);
}

TEST_F(BfsTest, GoalPositionNotFound) {
  strcpy(maze[9], "++++#+++##");  // Goal position removed
  findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);
  EXPECT_THROW(inputValidation(N, M, maze, startX, startY, goalX, goalY), std::runtime_error);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
