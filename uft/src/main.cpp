/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: Main file for handling user input and calling the UFT function.
 *
 * Input:
 * - The first line contains two integers, N and k.
 * - The next k lines each contain a query in the form of three integers: type, x, and y.
 *   - type is either 1 or 2.
 *   - x and y are the elements involved in the query.
 *
 * Output:
 * - The number of invalid queries based on the given constraints and logic.
 */

#include "src/uft.h"

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

  std::string input;
  int N, k;

  // Read the number of elements (N) and number of queries (k)
  std::cout << "Enter N and k:" << std::endl;
  std::cin >> N >> k;

  // Validate input for N and k
  if (!IsInteger(std::to_string(N)) || !IsInteger(std::to_string(k))) {
    std::cerr << "Error: N and k must be integers." << std::endl;
    return -1;
  }

  std::vector<std::tuple<int, int, int>> queries;
  std::cout << "Enter the queries (type x y):" << std::endl;
  for (int i = 0; i < k; ++i) {
    int type, x, y;
    std::cin >> type >> x >> y;

    // Check if x and y are integers
    if ((type != 1 && type != 2)
        || !IsInteger(std::to_string(x))
        || !IsInteger(std::to_string(y))) {
      std::cerr << "Error: Invalid input. Please enter valid queries."
        << std::endl;
      return -1;
    }
    queries.emplace_back(type, x, y);
  }

  int invalidCount = uft(N, k, queries);
  std::cout << "\n" << "Number of invalid queries: " << invalidCount << std::endl;

  return 0;
}
