/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: This program solves the single-source second shortest path problem for graphs
 *              using the Bellman-Ford algorithm.
 *
 * Input:
 * - The first line contains three integers, N, ML, and MD.
 *   - N: Number of cows (intersections).
 *   - ML: Number of good relations (pairs of cows that want to be close).
 *   - MD: Number of bad relations (pairs of cows that want to be far apart).
 * - The next ML lines each contain three integers: AL, BL, and DL.
 *   - AL and BL: Indices of cows that want to be close (1 <= AL < BL <= N).
 *   - DL: Maximum distance between cow AL and cow BL.
 * - The next MD lines each contain three integers: AD, BD, and DD.
 *   - AD and BD: Indices of cows that want to be far apart (1 <= AD < BD <= N).
 *   - DD: Minimum distance between cow AD and cow BD.
 *
 * Output:
 * - The maximum distance between cow 1 and cow N that satisfies all constraints.
 *   If no such arrangement is possible, output -1.
 *   If cows can be infinitely far apart, output -2.
 */

#include "bellman-ford.h"

int main() {
  // Prompt the user for input
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string input;
  int N, ML, MD;

  // Read the number of intersections (N) and number of roads (R)
  std::cout << "Enter N, ML and MD:" << std::endl;
  if (!(std::cin >> N >> ML >> MD)) {
    std::cerr << "Error: N, ML and MD must be integers." << std::endl;
    return -1;
  }

  std::cout << "Enter good relations (AL BL DL), and bad relations(AD BD DD):" << std::endl;
  std::vector<std::tuple<int, int, int>> goodRelations, badRelations;
  for (int i = 0; i < ML; ++i) {
    int AL, BL, DL;
    if (!(std::cin >> AL >> BL >> DL)) {
      std::cerr << "Error: Invalid input. Please enter valid number." << std::endl;
      return -1;
    }
    goodRelations.emplace_back(AL, BL, DL);
  }

  for (int i = 0; i < MD; ++i) {
    int AD, BD, DD;
    if (!(std::cin >> AD >> BD >> DD)) {
      std::cerr << "Error: Invalid input. Please enter valid number." << std::endl;
      return -1;
    }
    badRelations.emplace_back(AD, BD, DD);
  }

  // Call Bellman-Ford algorithm function
  int result = -1;
  // int result = bellmanFord(N, ML, MD, goodRelations, badRelations);

  // Output the result
  std::cout << "\n" << "Maximum distance between cow 1 and cow " << N << ": " << result << std::endl;

  return 0;
}
