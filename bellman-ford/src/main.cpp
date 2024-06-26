/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: This program solves the problem of arranging cows with constraints on their distances
 *              using the Bellman-Ford algorithm.
 *
 * Input:
 * - The first line contains three integers, N, ML, and MD.
 *   - N: Number of cows.
 *   - ML: Number of good relations.
 *   - MD: Number of bad relations.
 * - The next ML lines each contain three integers: AL, BL, and DL.
 *   - AL and BL: Indices of cows that want to be close.
 *   - DL: Maximum distance between cow AL and cow BL.
 * - The next MD lines each contain three integers: AD, BD, and DD.
 *   - AD and BD: Indices of cows that want to be far apart.
 *   - DD: Minimum distance between cow AD and cow BD.
 *
 * Output:
 * - The maximum distance between cow 1 and cow N that satisfies all constraints.
 *   If no such arrangement is possible, output -1.
 *   If cows can be infinitely far apart, output -2.
 */

#include "bellman-ford.h"

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int N, ML, MD;
  std::vector<std::tuple<int, int, int>> goodRelations, badRelations;

  // Input reading
  std::cout << "Enter the number of cows (N), good relations (ML), and bad relations (MD):" << std::endl;
  if (!(std::cin >> N >> ML >> MD)) {
    std::cerr << "Error: N, ML, and MD must be integers." << std::endl;
    return -1;
  }

  // Read good relations (within a certain maximum distance)
  std::cout << "Enter good relations (AL BL DL), and bad relations (AD BD DD):" << std::endl;
  for (int i = 0; i < ML; ++i) {
    int AL, BL, DL;
    if (!(std::cin >> AL >> BL >> DL)) {
      std::cerr << "Error: Invalid input for good relations. Please enter valid integers." << std::endl;
      return -1;
    }
    goodRelations.emplace_back(AL, BL, DL);
  }

  // Read bad relations (at least a certain minimum distance apart)
  for (int i = 0; i < MD; ++i) {
    int AD, BD, DD;
    if (!(std::cin >> AD >> BD >> DD)) {
      std::cerr << "Error: Invalid input for bad relations. Please enter valid integers." << std::endl;
      return -1;
    }
    badRelations.emplace_back(AD, BD, DD);
  }

  // Call Bellman-Ford algorithm function
  int result = bellmanFord(N, ML, MD, goodRelations, badRelations); // to be implement
  // int result = 0;

  // Output the result
  std::cout << "Maximum distance between cow 1 and cow " << N << ": " << result << std::endl;

  return 0;
}
