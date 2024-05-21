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
const int MAX_N = 100;
const int MAX_M = 100;

const int INF = 100000000;

// function
void findStartAndGoal(
  const int& N, const int& M, const char maze[MAX_N + 1][MAX_M + 1],
  int &startX, int &startY, int &goalX, int &goalY);

void inputValidation(
  const int& N, const int& M, const char maze[MAX_N + 1][MAX_M + 1],
  int& startX, int& startY, int& goalX, int& goalY);

int rtnMinimumTurns(
  const int& N, const int& M, const char maze[MAX_N + 1][MAX_M + 1],
  int& startX, int& startY, int& goalX, int& goalY);

int Bfs(
  const int& N, const int& M, const char maze[MAX_N + 1][MAX_M + 1]);

#endif  // BFS_SRC_BFS_H_
