/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: test_heap.cpp
 */

#include <gtest/gtest.h>
#include "src/heap.h"

class HeapTest : public ::testing::Test {
 protected:
  std::vector<int> A;
  std::vector<int> B;
  int N;
  int L;
  int P;

  void SetUp() override {
    // Initialize default values for tests
    N = 4;
    L = 25;
    P = 10;
    A = {10, 14, 20, 21};
    B = {10, 5, 2, 4};
  }

  void TearDown() override {
    // Clean up common resources for tests
  }
};

TEST_F(HeapTest, BasicCase) {
  // Test a basic scenario where the truck can refuel and complete the journey
  EXPECT_NO_THROW(InputValidation(N, L, P, A, B));
  EXPECT_EQ(heap(N, L, P, A, B), 2);
}

TEST_F(HeapTest, NoRefuelNeeded) {
  // Test a scenario where the truck has enough initial fuel
  // to complete the journey without refueling
  P = 30;
  EXPECT_EQ(heap(N, L, P, A, B), 0);
}

TEST_F(HeapTest, InsufficientFuel) {
  // Test a scenario where the truck cannot complete the journey
  // due to insufficient fuel, even after refueling
  L = 40;
  EXPECT_EQ(heap(N, L, P, A, B), -1);
}

TEST_F(HeapTest, MinNumberOfStations) {
  // Test the validation of input where the number of fuel stations
  // exceeds the minimum allowed
  N = MIN_FUEL_STATIONS - 1;
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MaxNumberOfStations) {
  // Test the validation of input where the number of fuel stations
  // exceeds the maximum allowed
  N = MAX_FUEL_STATIONS + 1;
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MinDistance) {
  // Test the validation of input where the distance to travel
  // exceeds the minimum allowed
  L = MIN_DISTANCE - 1;
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MaxDistance) {
  // Test the validation of input where the distance to travel
  // exceeds the maximum allowed
  L = MAX_DISTANCE + 1;
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MinInitialFuel) {
  // Test the validation of input where the initial fuel
  // exceeds the minimum allowed
  P = MIN_INITIAL_FUEL - 1;
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MaxInitialFuel) {
  // Test the validation of input where the initial fuel
  // exceeds the maximum allowed
  P = MAX_INITIAL_FUEL + 1;
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MinFuelStationDistance) {
  // Test the validation of input
  // where one of the fuel stations is located at the start
  N = 1;
  A = {MIN_DISTANCE - 1};
  B = {10};
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MaxFuelStationDistance) {
  // Test the validation of input
  // where one of the fuel stations is located beyond the destination
  A = {10, 14, 20, L};
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MinFuelStationAmount) {
  // Test the validation of input
  // where one of the fuel stations provides more fuel than the maximum allowed
  B = {10, 5, 2, MIN_FUEL_AMOUNT - 1};
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

TEST_F(HeapTest, MaxFuelStationAmount) {
  // Test the validation of input
  // where one of the fuel stations provides less fuel than the minimum allowed
  B = {10, 5, 2, MAX_FUEL_AMOUNT + 1};
  EXPECT_THROW(InputValidation(N, L, P, A, B), std::invalid_argument);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
