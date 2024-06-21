/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: dijkstra.cpp
 */

#include "src/dijkstra.h"

/**
 * @brief Validates the input constraints for N and R.
 * 
 * Checks if N and R are within the specified valid ranges.
 * 
 * @param N Number of intersections.
 * @param R Number of bidirectional roads.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int N, int R) {
  return (MIN_N <= N && N <= MAX_N && MIN_R <= R && R <= MAX_R);
}

int dijkstra(int N, int R,
             const std::vector<std::tuple<int, int, int>>& roads){
    if (!InputValidation(N, R)) {
    std::cerr << "Error: Input constraints violated. N must be in range ["
              << MIN_N << ", " << MAX_N << "], "
              << "and R must be in range ["
              << MIN_R << ", " << MAX_R << "]." << std::endl;
    return -1;
  }
    return 0;
}