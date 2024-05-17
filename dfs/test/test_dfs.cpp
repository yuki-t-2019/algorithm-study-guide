/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: test_dfs.cpp
 */

#include "src/dfs.h"
#include <gtest/gtest.h>
#include <limits>

// Input constraints tests
TEST(DFSTest, ThrowsExceptionForEmptyInputList) {
    std::vector<int> elements; // empty input list
    int target_sum = 0;
    EXPECT_THROW(Dfs(0, 0, elements, target_sum), std::invalid_argument);
}

TEST(DFSTest, ExceedingMaxElements) {
    std::vector<int> elements(21, 1);  // More than 20 elements
    int target_sum = 10;
    EXPECT_THROW(Dfs(0, 0, elements, target_sum), std::invalid_argument);
}

TEST(DFSTest, NegativeElementOutOfBounds) {
    std::vector<int> elements = {kLowerBound - 1};  // Less than -10^8
    int target_sum = 0;
    EXPECT_THROW(Dfs(0, 0, elements, target_sum), std::out_of_range);
}

TEST(DFSTest, PositiveElementOutOfBounds) {
    std::vector<int> elements = {kUpperBound + 1};  // More than 10^8
    int target_sum = 0;
    EXPECT_THROW(Dfs(0, 0, elements, target_sum), std::out_of_range);
}

TEST(DFSTest, TargetSumOutOfBoundsNegative) {
    std::vector<int> elements = {1, 2, 3};
    int target_sum = kLowerBound - 1;  // Less than -10^8
    EXPECT_THROW(Dfs(0, 0, elements, target_sum), std::out_of_range);
}

TEST(DFSTest, TargetSumOutOfBoundsPositive) {
    std::vector<int> elements = {1, 2, 3};
    int target_sum = kUpperBound + 1;  // More than 10^8
    EXPECT_THROW(Dfs(0, 0, elements, target_sum), std::out_of_range);
}

// algorithm tests
TEST(DFSTest, SingleElementListMatchingTargetSum) {
    std::vector<int> elements = {9};
    int target_sum = 9;
    EXPECT_TRUE(Dfs(0, 0, elements, target_sum));
}

TEST(DFSTest, SingleElementListNotMatchingTargetSum) {
    std::vector<int> elements = {5};
    int target_sum = 9;
    EXPECT_FALSE(Dfs(0, 0, elements, target_sum));
}

TEST(DFSTest, MultipleElementListMatchingTargetSum) {
    std::vector<int> elements = {1, 2, 3, 4, 5};
    int target_sum = 9;
    EXPECT_TRUE(Dfs(0, 0, elements, target_sum));
}

TEST(DFSTest, MultipleElementListNotMatchingTargetSum) {
    std::vector<int> elements = {1, 2, 3, 4, 5};
    int target_sum = 20;
    EXPECT_FALSE(Dfs(0, 0, elements, target_sum));
}

TEST(DFSTest, DuplicateElementsInInputList) {
    std::vector<int> elements = {2, 3, 4, 2}; // List containing duplicate elements
    int target_sum = 6;
    EXPECT_TRUE(Dfs(0, 0, elements, target_sum));
}

TEST(DFSTest, NegativeElementsInInputList) {
    std::vector<int> elements = {-1, 3, 5}; // List containing negative elements
    int target_sum = 4;
    EXPECT_TRUE(Dfs(0, 0, elements, target_sum));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
