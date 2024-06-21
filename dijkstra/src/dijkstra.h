/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: dijkstra.h
 */

#ifndef DIJKSTRA_SRC_DIJKSTRA_H_
#define DIJKSTRA_SRC_DIJKSTRA_H_

#include <iostream>
#include <sstream>
#include <tuple>
#include <vector>

constexpr int MIN_N = 1;
constexpr int MAX_N = 5000;
constexpr int MIN_R = 1;
constexpr int MAX_R = 100000;

/**
 * @brief Validates the input constraints for N and R.
 * @param N Number of intersections.
 * @param R Number of bidirectional roads.
 * @return true if the input constraints are valid, false otherwise.
 */
bool InputValidation(int N, int R);

int dijkstra(int N, int R,
             const std::vector<std::tuple<int, int, int>>& roads);

#endif  // DIJKSTRA_SRC_DIJKSTRA_H_
