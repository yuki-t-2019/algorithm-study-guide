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
constexpr int MAX_N = 1000;         /**< Maximum number of cows */
constexpr int MIN_N = 2;            /**< Minimum number of cows */
constexpr int MAX_ML_MD = 10000;    /**< Maximum number of good or bad relations */
constexpr int MIN_ML_MD = 1;        /**< Minimum number of good or bad relations */
constexpr int MIN_NUMBER_COW = 1;   /**< Minimum cow index */
constexpr int MAX_DISTANCE = 1000000;   /**< Maximum distance value */
constexpr int MIN_DISTANCE = 1;     /**< Minimum distance value */
constexpr int INF = std::numeric_limits<int>::max(); /**< Infinite distance value */

/**
 * @brief Validates the input constraints.
 * 
 * @param N Number of cows.
 * @param ML Number of good relations.
 * @param MD Number of bad relations.
 * @param goodRelations Vector of tuples representing good relations (AL, BL, DL).
 * @param badRelations Vector of tuples representing bad relations (AD, BD, DD).
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int N, int ML, int MD, const std::vector<std::tuple<int, int, int>>& goodRelations,
                     const std::vector<std::tuple<int, int, int>>& badRelations);

/**
 * @brief Updates a variable if a smaller value is found, and sets an update flag.
 * 
 * @param x Variable to update.
 * @param y New value to compare.
 * @param updated Flag to indicate if an update was made.
 */
void update(int& x, int y, bool& updated);

/**
 * @brief Executes the Bellman-Ford algorithm to update the distances.
 * 
 * @param N Number of cows.
 * @param ML Number of good relations.
 * @param MD Number of bad relations.
 * @param goodRelations Vector of tuples representing good relations (AL, BL, DL).
 * @param badRelations Vector of tuples representing bad relations (AD, BD, DD).
 */
void bellmanFord(int N, int ML, int MD, const std::vector<std::tuple<int, int, int>>& goodRelations,
                const std::vector<std::tuple<int, int, int>>& badRelations);

/**
 * @brief Solves the problem using the Bellman-Ford algorithm.
 * 
 * @param N Number of cows.
 * @param ML Number of good relations.
 * @param MD Number of bad relations.
 * @param goodRelations Vector of tuples representing good relations (AL, BL, DL).
 * @param badRelations Vector of tuples representing bad relations (AD, BD, DD).
 * @return The maximum distance between cow 1 and cow N. If no valid arrangement exists, returns -1.
 */
int solve(int N, int ML, int MD, const std::vector<std::tuple<int, int, int>>& goodRelations,
                const std::vector<std::tuple<int, int, int>>& badRelations);

#endif  // BELLMAN_FORD_SRC_DBELLMAN_FORD_H_
