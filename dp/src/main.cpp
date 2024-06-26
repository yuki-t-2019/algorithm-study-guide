/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: This program solves the knapsack problem
 *              using the dynamic programming approach.
 *
 * Input:
 * - An integer representing the number of items.
 * - A list of `n` pairs `(wi, vi)`,
 *   where each pair contains two integers
 *   representing the weight and value of an item.
 * - A single integer representing the maximum weight capacity of the knapsack.
 *
 * Output:
 * - An integer representing the maximum' value
 *   that can be obtained by selecting items
 *   such that their total weight does not exceed the maximum weight capacity.
 */

#include "src/dp.h"

int main() {
  // Prompt the user for input
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cout << "Enter the number of items:" << std::endl;
  std::string input;
  std::cin >> input;
  std::istringstream iss(input);
  if (!(iss >> n) || !(iss.eof())) {
    std::cerr << "Error: Invalid input. Please enter an integer." << std::endl;
    return -1;
  }

  std::vector<Item> items(n);
  std::cout << '\n'
            << "Enter the weight and value of each item (each line should "
               "contain two integers):" << std::endl;
  for (int i = 0; i < n; ++i) {
    int weight, value;
    if (!(std::cin >> weight >> value)) {
      std::cerr <<
        "Error: Invalid input. Please enter two integers." << std::endl;
      return -1;
    }
    items[i].weight = weight;
    items[i].value = value;

    // Clear any additional input until the end of the line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }

  int W;
  std::cout << '\n' << "Enter the maximum weight capacity:" << std::endl;
  std::cin >> input;
  std::istringstream issW(input);
  if (!(issW >> W) || !(issW.eof())) {
    std::cerr << "Error: Invalid input. Please enter an integer." << std::endl;
    return -1;
  }

  int result = dp(items, W);
  std::cout << std::endl << result << std::endl;

  return 0;
}
