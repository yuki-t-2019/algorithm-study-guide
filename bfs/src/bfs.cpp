/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: bfs.cpp
 */

#include "src/bfs.h"

void FindStartAndGoal(
    const int n, const int m, const char maze[kMaxN + 1][kMaxM + 1],
    int* start_x, int* start_y, int* goal_x, int* goal_y) {
  *start_x = *start_y = *goal_x = *goal_y = -1;  // Initialization

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (maze[x][y] == 'S') {
        *start_x = x;
        *start_y = y;
      } else if (maze[x][y] == 'G') {
        *goal_x = x;
        *goal_y = y;
      }
    }
  }
}

void InputValidation(
    const int n, const int m, const char maze[kMaxN + 1][kMaxM + 1],
    const int* start_x, const int* start_y,
    const int* goal_x, const int* goal_y) {

  // Validates the size of the maze.
  if (n <= 0 || n > kMaxN || m <= 0 || m > kMaxM) {
    throw std::invalid_argument(
        "Maze size is out of the allowed range: 1 <= N, M <= 100");
  }

  if (*start_x == -1 || *start_y == -1) {
    throw std::runtime_error("Start position not found!");
  }

  if (*goal_x == -1 || *goal_y == -1) {
    throw std::runtime_error("Goal position not found!");
  }
}

int RtnMinimumTurns(
    const int n, const int m, const char maze[kMaxN + 1][kMaxM + 1],
    const int* start_x, const int* start_y,
    const int* goal_x, const int* goal_y) {
  // minimum number of turns
  int turns[kMaxN][kMaxM + 1];

  // direction vector
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  // search minimum distance to goal from start
  std::queue<P> que;

  // initialization
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      turns[i][j] = kInf;
    }
  }
  que.push(P(*start_x, *start_y));
  turns[*start_x][*start_y] = 0;

  while (!que.empty()) {
    P now = que.front();
    que.pop();

    // break if now status is goal
    if (now.first == *goal_x && now.second == *goal_y) {
      break;
    }

    // search 4 direction
    for (int i = 0; i < 4; i++) {
      int moved_x = now.first + dx[i];
      int moved_y = now.second + dy[i];

      if (0 <= moved_x && moved_x < n && 0 <= moved_y && moved_y < m) {
        if (maze[moved_x][moved_y] != '#' && turns[moved_x][moved_y] == kInf) {
          que.push(P(moved_x, moved_y));
          turns[moved_x][moved_y] = turns[now.first][now.second] + 1;
        }
      }
    }
  }

  return turns[*goal_x][*goal_y];
}

int Bfs(const int n, const int m, const char maze[kMaxN + 1][kMaxM + 1]) {
  try {
    // Call the function to find the start and goal positions
    int start_x, start_y, goal_x, goal_y;
    FindStartAndGoal(n, m, maze, &start_x, &start_y, &goal_x, &goal_y);

    // Input constraints validation
    InputValidation(n, m, maze, &start_x, &start_y, &goal_x, &goal_y);

    return RtnMinimumTurns(n, m, maze, &start_x, &start_y, &goal_x, &goal_y);
  } catch (const std::exception& e) {
    // Print the error message
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  return -1;
}
