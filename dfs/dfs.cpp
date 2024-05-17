#include "dfs.h"

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
  // Input constraints validation
  if (elements.size() < 1 || elements.size() > kMaxElements) {
    throw std::invalid_argument("The number of elements must be between 1 and " + std::to_string(kMaxElements) + ".");
  }
  
  for (size_t i = 0; i < elements.size(); ++i) {
    if (elements[i] < kLowerBound || elements[i] > kUpperBound) {
      throw std::out_of_range("Element at index " + std::to_string(i) + " is out of range.");
    }
  }

  if (target_sum < kLowerBound || target_sum > kUpperBound) {
    throw std::out_of_range("Target sum is out of range.");
  }

  if (index == elements.size()) return current_sum == target_sum;
  if (Dfs(index + 1, current_sum, elements, target_sum)) return true;
  if (Dfs(index + 1, current_sum + elements[index], elements, target_sum)) return true;
  return false;
}
