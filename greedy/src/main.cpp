/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: This program solves the coin problem using the Greedy algorithm.
 *
 * Input:
 * - Six integers representing the quantities of
 *   1¢, 5¢, 10¢, 25¢, 50¢, and 100¢ coins.
 * - A single integer representing the target amount in cents.
 *
 * Output:
 * - An integer representing the minimum number of coins
 *   required to make the target amount.
 *   If it is not possible to make the target amount with the given quantities,
 *   the program outputs `-1`.
 */

#include "src/greedy.h"

int main() {
  // Prompt the user for input
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  // Coin denominations and their respective quantities
  std::vector<Coin> coins = {
    {100, 0},
    {50, 0},
    {25, 0},
    {10, 0},
    {5, 0},
    {1, 0}
  };

  std::cout << "Enter the quantities of 1¢, 5¢, 10¢, 25¢, 50¢, and 100¢ coins:" << std::endl;
  for (int i = 5; i >= 0; --i) {
      std::cin >> coins[i].quantity;
  }

  int a;
  std::cout << "Enter the target amount:" << std::endl;
  std::cin >> a;

  int result = Greedy(coins, a);
  std::cout << std::endl << result << std::endl;

  return 0;
}
