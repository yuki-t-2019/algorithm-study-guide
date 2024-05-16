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
  if (index == elements.size()) return current_sum == target_sum;
  if (Dfs(index + 1, current_sum, elements, target_sum)) return true;
  if (Dfs(index + 1, current_sum + elements[index], elements, target_sum)) return true;
  return false;
}
