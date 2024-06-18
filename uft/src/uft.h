/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: uft.h
 */

#ifndef UFT_SRC_UFT_H_
#define UFT_SRC_UFT_H_

#include <iostream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <vector>
#include <tuple>

constexpr int MIN_N = 1;
constexpr int MAX_N = 50000;
constexpr int MIN_K = 0;
constexpr int MAX_K = 100000;

/**
 * @brief Represents a Union-Find data structure with path compression and union by rank.
 */
class UnionFind {
 public:
  /**
   * @brief Constructs a UnionFind object with a given number of elements.
   * @param n The number of elements in the Union-Find structure.
   */
  explicit UnionFind(int n);

  /**
   * @brief Finds the root of the set containing element x with path compression.
   * @param x The element whose root needs to be found.
   * @return The root of the set containing x.
   */
  int Find(int x);

  /**
   * @brief Unites the sets containing elements x and y using union by rank.
   * @param x The first element.
   * @param y The second element.
   */
  void Union(int x, int y);

 private:
  std::vector<int> parent_;
  std::vector<int> rank_;
};

/**
 * @brief Validates the input constraints.
 * @param N Number of elements.
 * @param k Number of queries.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int N, int k);

/**
 * @brief Union-Find operations function.
 * @param N Number of elements.
 * @param k Number of queries.
 * @param queries A vector of queries.
 * @return The number of invalid queries.
 */
int uft(int N, int k, const std::vector<std::tuple<int, int, int>>& queries);

#endif  // UFT_SRC_UFT_H_
