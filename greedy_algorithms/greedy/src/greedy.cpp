/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: greedy.cpp
 */

#include "src/greedy.h"

/**
 * @brief Validates the input quantities of coins and the target amount.
 * 
 * @param coins A vector of Coin structs representing the coin denominations
 *              and their quantities.
 * @param a The target amount in cents.
 * @throws std::invalid_argument if any coin quantity
 *         or the target amount is out of the valid range.
 */
void InputValidation(const std::vector<Coin>& coins, const int& a) {
  if (a < 0 || a > MAX_AMOUNT) {
    throw std::invalid_argument("Target amount is out of valid range.");
  }
  for (const auto& coin : coins) {
    if (coin.quantity < 0 || coin.quantity > MAX_COIN_QUANTITY) {
      throw std::invalid_argument("Coin quantity is out of valid range.");
    }
  }
}

/**
 * @brief Uses the Greedy algorithm to compute the minimum number of coins
 *        needed to reach the target amount.
 * 
 * @param coins A vector of Coin structs representing the coin denominations
 *              and their quantities.
 * @param a The target amount in cents.
 * @return The minimum number of coins needed, or -1 if it is invalid input
 */
int Greedy(const std::vector<Coin>& coins, const int& a) {
  try {
    // Validate input constraints
    InputValidation(coins, a);
  } catch (const std::exception& e) {
    // Print the error message
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  int remaining_amount = a;
  int total_coins = 0;

  for (const auto& coin : coins) {
    if (remaining_amount <= 0) break;
    int num_coins = std::min(
      static_cast<int64_t>(remaining_amount / coin.value), coin.quantity);
    remaining_amount -= num_coins * coin.value;
    total_coins += num_coins;
  }

  return remaining_amount == 0 ? total_coins : -1;
}
