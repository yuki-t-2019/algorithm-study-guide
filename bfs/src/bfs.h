/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: bfs.h
 */

#ifndef BFS_SRC_BFS_H_
#define BFS_SRC_BFS_H_

#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <stdexcept>
#include <utility>

typedef std::pair<int, int> P;

// Constants for input constraints
const int kMaxN = 100;
const int kMaxM = 100;
const int kInf = 100000000;

// Function declarations
void FindStartAndGoal(
    const int n, const int m, const char maze[kMaxN + 1][kMaxM + 1],
    int* start_x, int* start_y, int* goal_x, int* goal_y);

void InputValidation(
    const int n, const int m, const char maze[kMaxN + 1][kMaxM + 1],
    const int* start_x, const int* start_y,
    const int* goal_x, const int* goal_y);

int RtnMinimumTurns(
    const int n, const int m, const char maze[kMaxN + 1][kMaxM + 1],
    const int* start_x, const int* start_y,
    const int* goal_x, const int* goal_y);

int Bfs(const int n, const int m, const char maze[kMaxN + 1][kMaxM + 1]);

#endif  // BFS_SRC_BFS_H_
