
/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: Main file for handling user input, validating input, calling the binary search function, and outputting the result.
 *
 * Input:
 * - The first line contains two integers, n and k.
 * - The next line contains n integers representing the array elements.
 *
 * Output:
 * - The smallest index i such that ai >= k, or n if no such index exists.
 */

#include "src/binary_search.h"

/**
 * @brief Checks if a given string represents a valid integer.
 * 
 * This function attempts to convert the input string to an integer using
 * a stringstream. If the conversion succeeds and there are no remaining
 * characters in the stream, the function returns true.
 * Otherwise, it returns false.
 * 
 * @param s The input string to be checked.
 * @return true if the string represents a valid integer, false otherwise.
 */
bool IsInteger(const std::string& s) {
  std::istringstream iss(s);
  int x;
  return (iss >> x) && (iss.eof());
}

int main() {
  // Prompt the user for input
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;

  // Read the number of elements (n) and the target value (k)
  std::cout << "Enter n and k:" << std::endl;
  std::cin >> n >> k;

  // Validate input for n and k
  if (!IsInteger(std::to_string(n)) || !IsInteger(std::to_string(k))) {
    std::cerr << "Error: n and k must be integers." << std::endl;
    return -1;
  }

  std::vector<int> array(n);
  std::cout << "Enter the array elements:" << std::endl;
  for (int i = 0; i < n; ++i) {
    std::cin >> array[i];
    if (!IsInteger(std::to_string(array[i]))) {
      std::cerr << "Error: All array elements must be integers." << std::endl;
      return -1;
    }
  }

  int result = BinarySearch(n, k, array);
  std::cout << "\n" << "Result: " << result << std::endl;

  return 0;
}
