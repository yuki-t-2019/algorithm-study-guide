/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: sieve-of-eratosthenes.cpp
 */

#include "src/sieve-of-eratosthenes.h"

/**
 * @brief Validates the input constraints for n.
 * 
 * Checks if n is within the specified valid range.
 * 
 * @param n The upper limit for finding prime numbers.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int n) {
  return (1 <= n && n <= kMaxN);
}

/**
 * @brief Uses the Sieve of Eratosthenes algorithm to count the number of prime numbers up to n.
 * 
 * @param n The upper limit for finding prime numbers.
 * @return The number of prime numbers less than or equal to n.
 */
int SieveOfEratosthenes(int n) {
  if (!InputValidation(n)) {
    return -1;
  }

  std::vector<bool> is_prime(n + 1, true);
  is_prime[0] = is_prime[1] = false;

  int limit = static_cast<int>(std::sqrt(n));
  for (int i = 2; i <= limit; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      }
    }
  }

  int prime_count = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      ++prime_count;
    }
  }

  return prime_count;
}
