/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: main.cpp
 * Description: Implementation of Depth First Search (DFS) algorithm to determine 
 *              if a given subset of integers sum to a specified value.
 * 
 * Input:
 * - n: Number of elements
 * - k: Target sum value
 * - a: List of integers
 * 
 * Output:
 * - "Yes" if a subset of a sums to k
 * - "No" otherwise
 */

#include "dfs.h"

/**
 * @brief Main function to execute the DFS algorithm.
 *
 * Prompts the user for input, reads the input values, and checks if a subset of
 * the integers sums to the specified value using the DFS algorithm.
 *
 * @return int Exit status of the program.
 */
int main() {
  // Prompt the user for input
  std::cout << "Enter the number of elements (n), the target sum (k), and the elements of the list (ai):" << std::endl;

  // Prepare for input
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int num_elements, target_sum;
  std::cin >> num_elements >> target_sum;

  std::vector<int> elements(num_elements);
  for (int i = 0; i < num_elements; ++i) {
    std::cin >> elements[i];
  }

  try {
    // Execute the DFS algorithm
    if (Dfs(0, 0, elements, target_sum)) {
      std::cout << "Yes" << std::endl;
    } else {
      std::cout << "No" << std::endl;
    }
  } catch (const std::exception& e) {
    // Print the error message
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
