/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: binary_search.cpp
 */

#include "src/binary_search.h"

/**
 * @brief Validates the input constraints for n, k, and array elements.
 * 
 * Checks if n, k, and array elements are within the specified valid ranges.
 * 
 * @param n Number of elements in the array.
 * @param k Target value to find.
 * @param array The array of elements.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int n, int k, const std::vector<int>& array) {
  if (n < 1 || n > 1000000) return false;
  if (k < 0 || k > 1000000000) return false;
  for (const int& val : array) {
    if (val < 0 || val > 1000000000) return false;
  }
  return true;
}

/**
 * @brief Performs binary search to find the smallest index i such that ai >= k.
 * 
 * This function implements the binary search algorithm to find the target index.
 * 
 * @param n Number of elements in the array.
 * @param k Target value to find.
 * @param array The array of elements.
 * @return The smallest index i such that ai >= k, or n if no such index exists.
 */
int BinarySearch(int n, int k, const std::vector<int>& array) {
  if (!InputValidation(n, k, array)) {
    std::cerr << "Error: Input validation failed." << std::endl;
    return -1;
  }
  
  int left = 0;
  int right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;
    if (array[mid] >= k) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
