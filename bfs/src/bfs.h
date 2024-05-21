/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: bfs.h
 */

#ifndef BFS_SRC_BFS_H_
#define BFS_SRC_BFS_H_

#include <iostream>
#include <cstring>

// Constants for input constraints
const int MAX_N = 100;
const int MAX_M = 100;

void findStartAndGoal(
  const int& N, const int& M, const char maze[MAX_N][MAX_M + 1],
  int &startX, int &startY, int &goalX, int &goalY);

void inputValidation(
  const int& N, const int& M, const char maze[MAX_N][MAX_M + 1],
  int& startX, int& startY, int& goalX, int& goalY);

int Bfs(
  const int& N, const int& M, const char maze[MAX_N][MAX_M + 1]);

#endif  // BFS_SRC_BFS_H_
