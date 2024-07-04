/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_dijkstra.cpp
 */

#include <gtest/gtest.h>
#include "src/dijkstra.h"

class DijkstraTest : public ::testing::Test {
 protected:
  int N;
  int R;
  std::vector<std::tuple<int, int, int>> roads;

  void SetUp() override {
    // Initialize default values for tests
    N = 4;
    R = 4;
    roads = {
        {1, 2, 100}, {2, 3, 250}, {2, 4, 200}, {3, 4, 100}
    };
  }

  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(DijkstraTest, BasicInput) {
  // Test a basic scenario
  EXPECT_EQ(dijkstra(N, R, roads), 450);
}

TEST_F(DijkstraTest, MinNumberOfIntersections) {
  // Test the validation of input where the number of intersections
  N = MIN_N - 1;
  EXPECT_FALSE(InputValidation(N, R));
}

TEST_F(DijkstraTest, MaxNumberOfIntersections) {
  // Test the validation of input where the number of intersections
  N = MAX_N + 1;
  EXPECT_FALSE(InputValidation(N, R));
}

TEST_F(DijkstraTest, MinNumberOfRoads) {
  // Test the validation of input where the number of bidirectional roads
  R = MIN_R - 1;
  EXPECT_FALSE(InputValidation(N, R));
}

TEST_F(DijkstraTest, MaxNumberOfRoads) {
  // Test the validation of input where the number of bidirectional roads
  R = MAX_R + 1;
  EXPECT_FALSE(InputValidation(N, R));
}

TEST_F(DijkstraTest, NoValidSecondShortestPath) {
  // Test a scenario where there is no valid second shortest path
  N = 3;
  R = 2;
  roads = {{1, 2, 1}, {2, 3, 1}};
  EXPECT_EQ(dijkstra(N, R, roads), -1);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
