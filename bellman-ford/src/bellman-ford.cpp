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
 * @brief Updates a variable if a smaller value is found, and sets an update flag.
 * 
 * @param x Variable to update.
 * @param y New value to compare.
 * @param updated Flag to indicate if an update was made.
 */
void update(int& x, int y, bool& updated) {
  if (x > y) {
    x = y;
    updated = true;
  }
}

/**
 * @brief Executes the Bellman-Ford algorithm to update the distances.
 * 
 * This function updates the distances between cows using the Bellman-Ford algorithm,
 * considering both good and bad relations.
 * 
 * @param N Number of cows.
 * @param ML Number of good relations.
 * @param MD Number of bad relations.
 * @param goodRelations Vector of tuples representing good relations (AL, BL, DL).
 * @param badRelations Vector of tuples representing bad relations (AD, BD, DD).
 * @param distance Vector of distances to update.
 * @param updated Boolean flag to indicate if any update was made.
 */
void bellmanFord(int N, int ML, int MD, const std::vector<std::tuple<int, int, int>>& goodRelations,
                const std::vector<std::tuple<int, int, int>>& badRelations, 
                std::vector<int>& distance, bool& updated) {
  // Relax edges up to N-1 times
  for (int i = 0; i <= N; ++i) {
    updated = false;

    for (int j = 1; j < N; j++) {
      if (distance[j + 1] < INF) {
        update(distance[j], distance[j + 1], updated);
      }
    }

    // Process good relations
    for (const auto& rel : goodRelations) {
      int AL, BL, DL;
      std::tie(AL, BL, DL) = rel;
      if (distance[AL] < INF) {
        update(distance[BL], distance[AL] + DL, updated);
      }
    }

    // Process bad relations
    for (const auto& rel : badRelations) {
      int AD, BD, DD;
      std::tie(AD, BD, DD) = rel;
      if (distance[BD] < INF) {
        update(distance[AD], distance[BD] - DD, updated);
      }
    }

    // if (!updated) {
    //   break;
    // }
  }
}

/**
 * @brief Solves the problem using the Bellman-Ford algorithm.
 * 
 * This function computes the maximum distance between cow 1 and cow N that satisfies
 * all given constraints. It uses the Bellman-Ford algorithm to find the shortest paths
 * considering both good and bad relations.
 * 
 * @param N Number of cows.
 * @param ML Number of good relations.
 * @param MD Number of bad relations.
 * @param goodRelations Vector of tuples representing good relations (AL, BL, DL).
 * @param badRelations Vector of tuples representing bad relations (AD, BD, DD).
 * @return The maximum distance between cow 1 and cow N. If no valid arrangement exists, returns -1.
 */
int solve(int N, int ML, int MD, const std::vector<std::tuple<int, int, int>>& goodRelations,
                const std::vector<std::tuple<int, int, int>>& badRelations) {
  if (!InputValidation(N, ML, MD, goodRelations, badRelations)) {
    std::cerr << "Error: Input constraints violated." << std::endl;
    return -1;
  }

  bool updated = false;

  // Negative cycle detected
  std::vector<int> distanceCheck(N + 1, 0);
  bellmanFord(N, ML, MD, goodRelations, badRelations, distanceCheck, updated);
  if (updated) {
    return -1;
  }

  std::vector<int> distance(N + 1, INF);
  distance[1] = 0;
  bellmanFord(N, ML, MD, goodRelations, badRelations, distance, updated);

  // Return the distance from cow 1 to cow N
  return (distance[N] == INF) ? -2 : distance[N];
}
