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

/**
 * @brief Finds the length of the second shortest path from the first intersection to the N-th intersection.
 * 
 * This function uses a modified Dijkstra's algorithm to calculate both the shortest and second shortest paths.
 * 
 * @param N Number of intersections.
 * @param R Number of bidirectional roads.
 * @param roads A vector of tuples representing the roads. Each tuple contains three integers: u, v, and w.
 *              u and v are the endpoints of a road, and w is the weight (length) of the road.
 * @return The length of the second shortest path from intersection 1 to intersection N. If no such path exists, returns -1.
 */
int dijkstra(int N, int R, const std::vector<std::tuple<int, int, int>>& roads) {
  if (!InputValidation(N, R)) {
    std::cerr << "Error: Input constraints violated. N must be in range ["
              << MIN_N << ", " << MAX_N << "], "
              << "and R must be in range ["
              << MIN_R << ", " << MAX_R << "]." << std::endl;
    return -1;
  }

  // Create the adjacency list
  std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
  for (const auto& road : roads) {
    int u, v, w;
    std::tie(u, v, w) = road;
    graph[u].emplace_back(v, w);
    graph[v].emplace_back(u, w);
  }

  // Distance arrays
  std::vector<int> dist1(N + 1, INF);
  std::vector<int> dist2(N + 1, INF);
  dist1[1] = 0;

  // Priority queue for Dijkstra's algorithm
  using T = std::tuple<int, int>;
  std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
  pq.emplace(0, 1);

  while (!pq.empty()) {
    int d, u;
    std::tie(d, u) = pq.top();
    pq.pop();

    if (d > dist2[u]) continue;

    for (const auto& edge : graph[u]) {
      int v, w;
      std::tie(v, w) = edge;

      int new_dist = d + w;

      if (new_dist < dist1[v]) {
        dist2[v] = dist1[v];
        dist1[v] = new_dist;
        pq.emplace(dist1[v], v);
        pq.emplace(dist2[v], v);
      } else if (new_dist > dist1[v] && new_dist < dist2[v]) {
        dist2[v] = new_dist;
        pq.emplace(dist2[v], v);
      }
    }
  }

  return (dist2[N] == INF) ? -1 : dist2[N];
}
