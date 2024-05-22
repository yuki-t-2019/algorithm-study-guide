/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: bfs.cpp
 */

#include "src/bfs.h"

/**
 * @brief Finds the start (S) and goal (G) positions in the maze.
 *
 * @param N Number of rows in the maze.
 * @param M Number of columns in the maze.
 * @param maze 2D character array containing the maze structure.
 * @param start_x Reference to the x-coordinate of the start position.
 * @param start_y Reference to the y-coordinate of the start position.
 * @param goal_x Reference to the x-coordinate of the goal position.
 * @param goal_y Reference to the y-coordinate of the goal position.
 */
void FindStartAndGoal(const int& N, const int& M, const char maze[kMaxN + 1][kMaxM + 1],
                      int& start_x, int& start_y, int& goal_x, int& goal_y) {
  start_x = start_y = goal_x = goal_y = -1;  // Initialize with invalid positions

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if (maze[x][y] == 'S') {
        start_x = x;
        start_y = y;
      } else if (maze[x][y] == 'G') {
        goal_x = x;
        goal_y = y;
      }
    }
  }
}

/**
 * @brief Validates the maze size and ensures that start and goal positions exist.
 *
 * @param N Number of rows in the maze.
 * @param M Number of columns in the maze.
 * @param maze 2D character array containing the maze structure.
 * @param start_x Reference to the x-coordinate of the start position.
 * @param start_y Reference to the y-coordinate of the start position.
 * @param goal_x Reference to the x-coordinate of the goal position.
 * @param goal_y Reference to the y-coordinate of the goal position.
 * @throws std::invalid_argument if the maze size is out of the allowed range.
 * @throws std::runtime_error if the start or goal positions are not found.
 */
void InputValidation(const int& N, const int& M, const char maze[kMaxN + 1][kMaxM + 1],
                     int& start_x, int& start_y, int& goal_x, int& goal_y) {
  // Validate the size of the maze.
  if (N <= 0 || N > kMaxN || M <= 0 || M > kMaxM) {
    throw std::invalid_argument("Maze size is out of the allowed range: 1 <= N, M <= 100");
  }

  if (start_x == -1 || start_y == -1) {
    throw std::runtime_error("Start position not found!");
  }

  if (goal_x == -1 || goal_y == -1) {
    throw std::runtime_error("Goal position not found!");
  }
}

/**
 * @brief Returns the minimum number of turns required to move from the start to the goal.
 *
 * @param N Number of rows in the maze.
 * @param M Number of columns in the maze.
 * @param maze 2D character array containing the maze structure.
 * @param start_x Reference to the x-coordinate of the start position.
 * @param start_y Reference to the y-coordinate of the start position.
 * @param goal_x Reference to the x-coordinate of the goal position.
 * @param goal_y Reference to the y-coordinate of the goal position.
 * @return Minimum number of turns from start to goal.
 */
int RtnMinimumTurns(const int& N, const int& M, const char maze[kMaxN + 1][kMaxM + 1],
                    int& start_x, int& start_y, int& goal_x, int& goal_y) {
  int turns[kMaxN][kMaxM + 1];

  // Direction vectors
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  // Initialize turns array
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      turns[i][j] = kInf;
    }
  }

  std::queue<P> que;
  que.push(P(start_x, start_y));
  turns[start_x][start_y] = 0;

  while (!que.empty()) {
    P now = que.front();
    que.pop();

    // Break if current position is the goal
    if (now.first == goal_x && now.second == goal_y) {
      break;
    }

    // Explore 4 directions
    for (int i = 0; i < 4; i++) {
      int moved_x = now.first + dx[i];
      int moved_y = now.second + dy[i];

      if (0 <= moved_x && moved_x < N && 0 <= moved_y && moved_y < M) {
        if (maze[moved_x][moved_y] != '#' && turns[moved_x][moved_y] == kInf) {
          que.push(P(moved_x, moved_y));
          turns[moved_x][moved_y] = turns[now.first][now.second] + 1;
        }
      }
    }
  }

  return turns[goal_x][goal_y];
}

/**
 * @brief Executes the BFS algorithm to find the shortest path in the maze.
 *
 * @param N Number of rows in the maze.
 * @param M Number of columns in the maze.
 * @param maze 2D character array containing the maze structure.
 * @return Minimum number of turns required to move from the start to the goal, or -1 on error.
 */
int Bfs(const int& N, const int& M, const char maze[kMaxN + 1][kMaxM + 1]) {
  try {
    // Call the function to find the start and goal positions
    int start_x, start_y, goal_x, goal_y;
    FindStartAndGoal(N, M, maze, start_x, start_y, goal_x, goal_y);

    // Input constraints validation
    InputValidation(N, M, maze, start_x, start_y, goal_x, goal_y);

    return RtnMinimumTurns(N, M, maze, start_x, start_y, goal_x, goal_y);

  } catch (const std::exception& e) {
    // Print the error message
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  return -1;
}
