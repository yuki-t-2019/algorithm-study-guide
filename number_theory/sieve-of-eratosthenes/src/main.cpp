/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: Main file for handling user input, checking if the input is a valid integer, 
 *              calling the Sieve of Eratosthenes function, and printing the result.
 *
 * Input:
 * - A single integer n.
 *
 * Output:
 * - The number of prime numbers less than or equal to n.
 */

#include "src/sieve-of-eratosthenes.h"

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
    int n;

    // Read the integer n
    std::cout << "Enter an integer n:" << std::endl;
    std::cin >> input;

    // Validate input for n
    if (!IsInteger(input)) {
        std::cerr << "Error: n must be an integer." << std::endl;
        return -1;
    }

    n = std::stoi(input);

    // Call the Sieve of Eratosthenes function and print the result
    int primeCount = SieveOfEratosthenes(n);
    std::cout << "\n" << "Number of prime numbers: " << primeCount << std::endl;

    return 0;
}