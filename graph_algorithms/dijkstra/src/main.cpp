/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: This program solves the single-source second shortest path problem for graphs
 *              using a Dijkstra's algorithm .
 *
 * Input:
 * - The first line contains two integers, N and R.
 * - The next R lines each contain three integers: u, v, and w.
 *   - u and v are the endpoints of a road.
 *   - w is the weight (length) of the road.
 *
 * Output:
 * - The length of the second shortest path from intersection 1 to intersection N.
 *   If no such path exists, output -1.
 */

#include "dijkstra.h"

int main() {
  // Prompt the user for input
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string input;
  int N, R;

  // Read the number of intersections (N) and number of roads (R)
  std::cout << "Enter N and R:" << std::endl;
  if (!(std::cin >> N >> R)) {
    std::cerr << "Error: N and R must be integers." << std::endl;
    return -1;
  }

  std::vector<std::tuple<int, int, int>> roads;
  std::cout << "Enter the roads (u v w):" << std::endl;
  for (int i = 0; i < R; ++i) {
    int u, v, w;
    if (!(std::cin >> u >> v >> w)) {
      std::cerr << "Error: Invalid input. Please enter valid roads." << std::endl;
      return -1;
    }
    roads.emplace_back(u, v, w);
  }

  int result = dijkstra(N, R, roads);
  std::cout << "\n" << "Length of the second shortest path: " << result << std::endl;

  return 0;
}
