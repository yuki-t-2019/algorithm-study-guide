/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: 
 *
 * Input:
 * -
 *
 * Output:
 * -
 */

#include "src/euclidean.h"

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

  int result = euclidean();
  std::cout << "\n" << result << std::endl;

  return 0;
}