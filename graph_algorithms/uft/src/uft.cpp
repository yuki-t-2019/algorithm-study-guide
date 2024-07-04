/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: uft.cpp
 */

#include "src/uft.h"

/**
 * @brief Constructs a UnionFind object with a given number of elements.
 * 
 * Initializes the Union-Find data structure with path compression and union by rank.
 * 
 * @param n The number of elements in the Union-Find structure.
 */
UnionFind::UnionFind(int n) {
  parent_.resize(n + 1);
  rank_.resize(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    parent_[i] = i;
  }
}

/**
 * @brief Finds the root of the set containing element x with path compression.
 * 
 * This function compresses the path, making future queries faster.
 * 
 * @param x The element whose root needs to be found.
 * @return The root of the set containing x.
 */
int UnionFind::Find(int x) {
  if (parent_[x] != x) {
    parent_[x] = Find(parent_[x]);  // Path compression
  }
  return parent_[x];
}

/**
 * @brief Unites the sets containing elements x and y using union by rank.
 * 
 * This function merges two sets by attaching the root of one to the root of the other, 
 * based on the rank (size) of each set.
 * 
 * @param x The first element.
 * @param y The second element.
 */
void UnionFind::Union(int x, int y) {
  int rootX = Find(x);
  int rootY = Find(y);

  if (rootX != rootY) {
    // Union by rank
    if (rank_[rootX] > rank_[rootY]) {
      parent_[rootY] = rootX;
    } else if (rank_[rootX] < rank_[rootY]) {
      parent_[rootX] = rootY;
    } else {
      parent_[rootY] = rootX;
      rank_[rootX]++;
    }
  }
}

/**
 * @brief Validates the input constraints for N and k.
 * 
 * Checks if N and k are within the specified valid ranges.
 * 
 * @param N Number of elements.
 * @param k Number of queries.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int N, int k) {
  return (MIN_N <= N && N <= MAX_N && MIN_K <= k && k <= MAX_K);
}

/**
 * @brief Processes the queries using the Union-Find data structure.
 * 
 * This function handles the queries, updating the Union-Find structure and counting
 * the number of invalid queries based on the given constraints and logic.
 * 
 * @param N Number of elements.
 * @param k Number of queries.
 * @param queries A vector of queries.
 * @return The number of invalid queries.
 */
int uft(int N, int k, const std::vector<std::tuple<int, int, int>>& queries) {
  if (!InputValidation(N, k)) {
    std::cerr << "Error: Input constraints violated. N must be in range [1, " << MAX_N << "], "
              << "and k must be in range [0, " << MAX_K << "]." << std::endl;
    return -1;
  }

  // Init
  UnionFind uf(3 * N);
  int invalidCount = 0;

  for (const auto& query : queries) {
    int type = std::get<0>(query);
    int x = std::get<1>(query);
    int y = std::get<2>(query);

    if (x < 1 || x > N || y < 1 || y > N) {
      // Invalid animal number, skip this query
      invalidCount++;
      continue;
    }

    int xA = x, xB = x + N, xC = x + 2 * N;
    int yA = y, yB = y + N, yC = y + 2 * N;

    if (type == 1) {  // Same type
      if (uf.Find(xA) == uf.Find(yB) || uf.Find(xA) == uf.Find(yC)) {
        invalidCount++;
      } else {
        uf.Union(xA, yA);
        uf.Union(xB, yB);
        uf.Union(xC, yC);
      }
    } else if (type == 2) {  // x eats y
      if (uf.Find(xA) == uf.Find(yA) || uf.Find(xA) == uf.Find(yC)) {
        invalidCount++;
      } else {
        uf.Union(xA, yB);
        uf.Union(xB, yC);
        uf.Union(xC, yA);
      }
    }
  }

  return invalidCount;
}
