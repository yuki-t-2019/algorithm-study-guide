/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: This program solves the truck fueling problem
 *              using a heap (priority queue) approach.
 *
 * Input:
 * - An integer `N` representing the number of fuel stations.
 * - An integer `L` representing the total distance to travel.
 * - An integer `P` representing the initial amount of fuel.
 * - A list of `N` integers `A`
 *   representing the distances of the fuel stations from the start.
 * - A list of `N` integers `B`
 *   representing the amount of fuel each station provides.
 *
 * Output:
 * - An integer representing the minimum number of refueling
 *   needed to reach the destination.
 *   If the journey is not possible, it outputs `-1`.
 */

#include "src/heap.h"


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
bool isInteger(const std::string& s) {
  std::istringstream iss(s);
  int x;
  return (iss >> x) && (iss.eof());
}

int main() {
  // Prompt the user for input
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string input;
  int N, L, P;

  // Read the number of fuel stations
  std::cout << "Enter the number of fuel stations:" << std::endl;
  std::cin >> input;
  if (!isInteger(input)) {
    std::cerr << "Error: Invalid input. Please enter an integer." << std::endl;
    return -1;
  }
  N = std::stoi(input);

  // Read the total distance to travel
  std::cout << '\n' << "Enter the total distance to travel:" << std::endl;
  std::cin >> input;
  if (!isInteger(input)) {
    std::cerr << "Error: Invalid input. Please enter an integer." << std::endl;
    return -1;
  }
  L = std::stoi(input);

  // Read the initial amount of fuel
  std::cout << '\n' << "Enter the initial amount of fuel:" << std::endl;
  std::cin >> input;
  if (!isInteger(input)) {
    std::cerr << "Error: Invalid input. Please enter an integer." << std::endl;
    return -1;
  }
  P = std::stoi(input);

  // Read the distances of each fuel station from the start
  std::vector<int> A(N), B(N);
  std::cout << '\n'
    << "Enter the distances of each fuel station from the start:" << std::endl;
  for (int i = 0; i < N; ++i) {
    std::cin >> input;
    if (!isInteger(input)) {
      std::cerr
        << "Error: Invalid input. Please enter an integer." << std::endl;
      return -1;
    }
    A[i] = std::stoi(input);
  }

  // Read the amount of fuel each station provides
  std::cout << '\n'
    << "Enter the amount of fuel each station provides:" << std::endl;
  for (int i = 0; i < N; ++i) {
    std::cin >> input;
    if (!isInteger(input)) {
      std::cerr
        << "Error: Invalid input. Please enter an integer." << std::endl;
      return -1;
    }
    B[i] = std::stoi(input);
  }

  int result = heap(N, L, P, A, B);
  std::cout << std::endl << result << std::endl;

  return 0;
}
