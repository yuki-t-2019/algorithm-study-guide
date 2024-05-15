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

namespace {

/**
 * @brief Performs a depth-first search to determine if a subset of integers sums to a specified value.
 *
 * @param index Current index in the vector.
 * @param current_sum Current sum of the subset.
 * @param elements Vector of integers.
 * @param target_sum Target sum value.
 * @return true if a subset sums to the target value, false otherwise.
 */
bool Dfs(std::vector<int>::size_type index, int current_sum, const std::vector<int>& elements, int target_sum) {
  if (index == elements.size()) return current_sum == target_sum;
  if (Dfs(index + 1, current_sum, elements, target_sum)) return true;
  if (Dfs(index + 1, current_sum + elements[index], elements, target_sum)) return true;
  return false;
}

}  // namespace

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

  // Validate input
  if (num_elements <= 0) {
    std::cerr << "The number of elements must be a positive integer." << std::endl;
    return 1;
  }

  std::vector<int> elements(num_elements);
  for (int i = 0; i < num_elements; ++i) {
    std::cin >> elements[i];
  }

  // Execute the DFS algorithm
  if (Dfs(0, 0, elements, target_sum)) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

  return 0;
}
