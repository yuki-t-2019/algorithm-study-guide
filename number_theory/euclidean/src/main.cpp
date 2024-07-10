/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: Main file for handling user input and calling the Euclidean algorithm.
 *
 * Input:
 * - Two sets of coordinates (x1, y1) and (x2, y2) representing two lattice points.
 *
 * Output:
 * - The number of lattice points on the line segment between (x1, y1) and (x2, y2), excluding the endpoints.
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

  std::string x1_str, y1_str, x2_str, y2_str;
  int x1, y1, x2, y2;

  std::cout << "Enter coordinates x1, y1, x2, y2:" << std::endl;
  std::cin >> x1_str >> y1_str >> x2_str >> y2_str;

  // Validate input
  if (!IsInteger(x1_str) || !IsInteger(y1_str) || !IsInteger(x2_str) || !IsInteger(y2_str)) {
      std::cerr << "Error: All coordinates must be integers." << std::endl;
      return -1;
  }

  x1 = std::stoi(x1_str);
  y1 = std::stoi(y1_str);
  x2 = std::stoi(x2_str);
  y2 = std::stoi(y2_str);

  int result = Euclidean(x1, y1, x2, y2);

  std::cout << "\n" << result << std::endl;

  return 0;
}
