/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: bellman-ford.h
 */

#ifndef BELLMAN_FORD_SRC_DBELLMAN_FORD_H_
#define BELLMAN_FORD_SRC_DBELLMAN_FORD_H_

#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

// Define the constraints for validation
constexpr int MAX_N = 1000;
constexpr int MIN_N = 2;
constexpr int MAX_ML_MD = 10000;
constexpr int MIN_ML_MD = 1;
constexpr int MIN_NUMBER_COW = 1;
constexpr int MAX_DISTANCE = 1000000;
constexpr int MIN_DISTANCE = 1;
constexpr int INF = std::numeric_limits<int>::max();

bool InputValidation(int N, int ML, int MD, const std::vector<std::tuple<int, int, int>>& goodRelations,
                     const std::vector<std::tuple<int, int, int>>& badRelations);

int bellmanFord(int N, int ML, int MD, const std::vector<std::tuple<int, int, int>>& goodRelations,
                const std::vector<std::tuple<int, int, int>>& badRelations);


#endif  // BELLMAN_FORD_SRC_DBELLMAN_FORD_H_
