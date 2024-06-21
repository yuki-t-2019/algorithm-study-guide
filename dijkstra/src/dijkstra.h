/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: dijkstra.h
 */

#ifndef DIJKSTRA_SRC_DIJKSTRA_H_
#define DIJKSTRA_SRC_DIJKSTRA_H_

#include <iostream>
#include <limits>
#include <queue>
#include <sstream>
#include <tuple>
#include <vector>

constexpr int MIN_N = 1;
constexpr int MAX_N = 5000;
constexpr int MIN_R = 1;
constexpr int MAX_R = 100000;
constexpr int INF = std::numeric_limits<int>::max();

/**
 * @brief Validates the input constraints for N and R.
 * @param N Number of intersections.
 * @param R Number of bidirectional roads.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int N, int R);

/**
 * @brief Finds the length of the second shortest path from the first intersection to the N-th intersection.
 * @param N Number of intersections.
 * @param R Number of bidirectional roads.
 * @param roads A vector of tuples representing the roads. Each tuple contains three integers: u, v, and w.
 *              u and v are the endpoints of a road, and w is the weight (length) of the road.
 * @return The length of the second shortest path from intersection 1 to intersection N. If no such path exists, returns -1.
 */
int dijkstra(int N, int R,
             const std::vector<std::tuple<int, int, int>>& roads);

#endif  // DIJKSTRA_SRC_DIJKSTRA_H_
