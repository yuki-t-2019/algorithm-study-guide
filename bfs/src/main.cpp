/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: main.cpp
 * Description: This program solves the maze shortest path problem
 *              using the Breadth-First Search (BFS) algorithm.
 * 
 * Input:
 * - An integer `N`: the number of rows in the maze.
 * - An integer `M`: the number of columns in the maze.
 * - A `N x M` grid representing the maze, 
 *   where `'#'` denotes a wall, `'+'` denotes a passage,
 *         `'S'` denotes the start, and `'G'` denotes the goal.
 * 
 * Output:
 * - An integer representing the minimum number of turns
 *   required to move from the start to the goal.
 */

#include "src/bfs.h"

/**
 * @brief Main function to execute the BFS maze solver.
 *
 * @return int The exit status of the program.
 */
int main() {
  // Prompt the user for input
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int N, M;
  std::cout << "Enter the size of the maze (N M):" << std::endl;
  std::cin >> N >> M;

  char maze[kMaxN][kMaxM + 1];
  std::cout << "Enter the maze:" << std::endl;
  for (int i = 0; i < N; ++i) {
      std::cin >> maze[i];
  }

  char reversed_maze[kMaxN + 1][kMaxM + 1];
  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      reversed_maze[y][x] = maze[x][y];
    }
  }

  int result = Bfs(N, M, reversed_maze);
  std::cout << "\n" << result << std::endl;

  return 0;
}
