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
 * @throws std::invalid_argument if any item weight or value, or the maximum weight capacity is out of the valid range.
 */
void InputValidation(const std::vector<Item>& items, const int& W) {
  if (W < MIN_WEIGHT_CAPACITY || W > MAX_WEIGHT_CAPACITY) {
    throw std::invalid_argument("Maximum weight capacity is out of valid range.");
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

  return 0;
}

