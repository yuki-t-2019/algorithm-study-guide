/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: bellman-ford.cpp
 */

#include "src/bellman-ford.h"

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
                     const std::vector<std::tuple<int, int, int>>& badRelations) {
  if (N < MIN_N || N > MAX_N || ML < MIN_ML_MD || ML > MAX_ML_MD || MD < MIN_ML_MD || MD > MAX_ML_MD) {
    return false;
  }
  for (const auto& rel : goodRelations) {
    int AL, BL, DL;
    std::tie(AL, BL, DL) = rel;
    if (AL < MIN_NUMBER_COW || AL >= BL || BL > N || DL < MIN_DISTANCE || DL > MAX_DISTANCE) {
        return false;
    }
  }
  for (const auto& rel : badRelations) {
    int AD, BD, DD;
    std::tie(AD, BD, DD) = rel;
    if (AD < MIN_NUMBER_COW || AD >= BD || BD > N || DD < MIN_DISTANCE || DD > MAX_DISTANCE) {
        return false;
    }
  }
  return true;
}

/**
 * @brief Executes the Bellman-Ford algorithm to find the maximum distance between cow 1 and cow N
 *        that satisfies all constraints.
 * 
 * @param N Number of cows.
 * @param ML Number of good relations.
 * @param MD Number of bad relations.
 * @param goodRelations Vector of tuples representing good relations (AL, BL, DL).
 * @param badRelations Vector of tuples representing bad relations (AD, BD, DD).
 * @return The maximum distance between cow 1 and cow N. If no valid arrangement exists, returns -1.
 */
int bellmanFord(int N, int ML, int MD, const std::vector<std::tuple<int, int, int>>& goodRelations,
                const std::vector<std::tuple<int, int, int>>& badRelations) {
  if (!InputValidation(N, ML, MD, goodRelations, badRelations)) {
    std::cerr << "Error: Input constraints violated." << std::endl;
    return -1;
  }

  // Distance array
  std::vector<int> distance(N + 1, INF);
  distance[1] = 0;

  // Relax edges up to N-1 times
  for (int i = 1; i < N; ++i) {
    bool updated = false;

    // Process good relations
    for (const auto& rel : goodRelations) {
      int AL, BL, DL;
      std::tie(AL, BL, DL) = rel;
      if (distance[AL] != INF && distance[AL] + DL < distance[BL]) {
        distance[BL] = distance[AL] + DL;
        updated = true;
      }
    }

    // Process bad relations
    for (const auto& rel : badRelations) {
      int AD, BD, DD;
      std::tie(AD, BD, DD) = rel;
      if (distance[BD] != INF && distance[BD] - DD < distance[AD]) {
        distance[AD] = distance[BD] - DD;
        updated = true;
      }
    }

    // If no update occurred, break early
    if (!updated) break;
  }

  // Check for negative weight cycles
  for (const auto& rel : goodRelations) {
    int AL, BL, DL;
    std::tie(AL, BL, DL) = rel;
    if (distance[AL] != INF && distance[AL] + DL < distance[BL]) {
      return -1; // Negative cycle detected
    }
  }

  for (const auto& rel : badRelations) {
    int AD, BD, DD;
    std::tie(AD, BD, DD) = rel;
    if (distance[BD] != INF && distance[BD] - DD < distance[AD]) {
      return -1; // Negative cycle detected
    }
  }

  // Return the distance from cow 1 to cow N
  return (distance[N] == INF) ? -2 : distance[N];
}
