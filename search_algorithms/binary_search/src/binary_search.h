/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: binary_search.h
 */

#ifndef BINARY_SEARCH_SRC_BINARY_SEARCH_H_
#define BINARY_SEARCH_SRC_BINARY_SEARCH_H_

#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

constexpr int MIN_N = 1;
constexpr int MAX_N = 1000000;
constexpr int MIN_VAL = 0;
constexpr int MAX_VAL = 1000000000;

/**
 * @brief Validates the input constraints for n, k, and array elements.
 * 
 * @param n Number of elements in the array.
 * @param k Target value to find.
 * @param array The array of elements.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int n, int k, const std::vector<int>& array);

/**
 * @brief Performs binary search to find the smallest index i such that ai >= k.
 * 
 * @param n Number of elements in the array.
 * @param k Target value to find.
 * @param array The array of elements.
 * @return The smallest index i such that ai >= k, or n if no such index exists.
 */
int BinarySearch(int n, int k, const std::vector<int>& array);


#endif  // BINARY_SEARCH_SRC_BINARY_SEARCH_H_
