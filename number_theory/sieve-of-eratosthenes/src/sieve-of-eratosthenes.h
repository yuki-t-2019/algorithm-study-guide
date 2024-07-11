/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: sieve-of-eratosthenes.h
 */

#ifndef SIEVE_OF_ERATOSTHENES_SRC_SIEVE_OF_ERATOSTHENES_H_
#define SIEVE_OF_ERATOSTHENES_SRC_SIEVE_OF_ERATOSTHENES_H_

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>

const int kMaxN = 1000000;

/**
 * @brief Validates the input constraints for n.
 * 
 * Checks if n is within the specified valid range.
 * 
 * @param n The upper limit for finding prime numbers.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int n);

/**
 * @brief Uses the Sieve of Eratosthenes algorithm to count the number of prime numbers up to n.
 * 
 * @param n The upper limit for finding prime numbers.
 * @return The number of prime numbers less than or equal to n.
 */
int SieveOfEratosthenes(int n);

#endif  // SIEVE_OF_ERATOSTHENES_SRC_SIEVE_OF_ERATOSTHENES_H_
