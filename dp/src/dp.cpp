/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: dp.cpp
 */

#include "src/dp.h"

/**
 * @brief Validates the input items and the maximum weight capacity.
 * 
 * @param items A vector of Item structs representing the items.
 * @param W The maximum weight capacity of the knapsack.
 * @throws std::invalid_argument if any item weight or value, the maximum weight capacity is out of the valid range, or if the items vector is empty.
 */
void InputValidation(const std::vector<Item>& items, const int& W) {
  if (W < MIN_WEIGHT_CAPACITY || W > MAX_WEIGHT_CAPACITY) {
    throw std::invalid_argument("Maximum weight capacity is out of valid range.");
  }
  if (items.empty()) {
    throw std::invalid_argument("Items list is empty.");
  }
  for (const auto& item : items) {
    if (item.weight < MIN_ITEM_WEIGHT || item.weight > MAX_ITEM_WEIGHT || item.value < MIN_ITEM_VALUE || item.value > MAX_ITEM_VALUE) {
      throw std::invalid_argument("Item weight or value is out of valid range.");
    }
  }
}

/**
 * @brief Solves the knapsack problem using dynamic programming.
 * 
 * @param items A vector of Item structs representing the items.
 * @param W The maximum weight capacity of the knapsack.
 * @return The maximum value that can be obtained without exceeding the weight capacity.
 */
int dp(const std::vector<Item>& items, const int& W) {
  try {
    InputValidation(items, W);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  int n = items.size();
  std::vector<std::vector<int>> dp_memo(n + 1, std::vector<int>(W + 1, 0));
  // dp_memo[i][j] represents the maximum value that can be achieved
  // using the items from index i to the end, with a remaining capacity of j.

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j <= W; j++) {
      // If the weight of the item at index i is greater than the remaining capacity j:
      if (j < items[i].weight) {
        dp_memo[i][j] = dp_memo[i + 1][j];
      } else {
        dp_memo[i][j] = std::max(dp_memo[i + 1][j], dp_memo[i + 1][j - items[i].weight] + items[i].value);
      }
    }
  }

  return dp_memo[0][W];
}
