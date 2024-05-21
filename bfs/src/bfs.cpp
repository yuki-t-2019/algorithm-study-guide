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
 * @param startX Reference to the x-coordinate of the start position.
 * @param startY Reference to the y-coordinate of the start position.
 * @param goalX Reference to the x-coordinate of the goal position.
 * @param goalY Reference to the y-coordinate of the goal position.
 */
void findStartAndGoal(
  const int& N, const int& M, const char maze[MAX_N + 1][MAX_M + 1],
  int &startX, int &startY, int &goalX, int &goalY) {
  startX = startY = goalX = goalY = -1; // Initialize with invalid positions

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if (maze[x][y] == 'S') {
        startX = x;
        startY = y;
      } else if (maze[x][y] == 'G') {
        goalX = x;
        goalY = y;
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
 * @param startX Reference to the x-coordinate of the start position.
 * @param startY Reference to the y-coordinate of the start position.
 * @param goalX Reference to the x-coordinate of the goal position.
 * @param goalY Reference to the y-coordinate of the goal position.
 * @throws std::invalid_argument if the maze size is out of the allowed range.
 * @throws std::runtime_error if the start or goal positions are not found.
 */
void inputValidation(
  const int& N, const int& M, const char maze[MAX_N + 1][MAX_M + 1],
  int& startX, int& startY, int& goalX, int& goalY){

  // Validates the size of the maze.
  if (N <= 0 || N > MAX_N || M <= 0 || M > MAX_M) {
    throw std::invalid_argument(
      "Maze size is out of the allowed range: 1 <= N, M <= 100");
  }

  if (startX == -1 || startY == -1) {
    throw std::runtime_error("Start position not found!");
  }

  if (goalX == -1 || goalY == -1) {
    throw std::runtime_error("Goal position not found!");
  }
}

/**
 * @brief 
 * @param 
 * @return 
 */
int rtnMinimumTurns(
  const int& N, const int& M, const char maze[MAX_N + 1][MAX_M + 1],
  int& startX, int& startY, int& goalX, int& goalY){
  // minimum number of turns
  int turns[MAX_N][MAX_M + 1];

  // direction vector
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};

  // search minimum distance to goal from start
  std::queue<P> que;

  // initialization
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      turns[i][j] = INF;
    }
  }
  que.push(P(startX, startY));
  turns[startX][startY] = 0;

  while (!que.empty()) {
    P now = que.front(); que.pop();

    // break if now status is goal
    if (now.first == goalX && now.second == goalY) {
      break;
    }

    // search 4 direction
    for (int i = 0; i < 4; i++) {
      int movedX = now.first + dx[i];
      int movedY = now.second + dy[i];

      if (0 <= movedX && movedX < N && 0 <= movedY && movedY < M) {
        if (maze[movedX][movedY] != '#' && turns[movedX][movedY] == INF) {
          que.push(P(movedX, movedY));
          turns[movedX][movedY] = turns[now.first][now.second] + 1;
        }
      }
    }
  }

  return turns[goalX][goalY];
}


/**
 * @brief 
 * @param 
 * @return 
 */
int Bfs(
  const int& N, const int& M, const char maze[MAX_N + 1][MAX_M + 1]) {
  
  try {
    // Call the function to find the start and goal positions
    int startX, startY, goalX, goalY;
    findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);

    // Input constraints validation
    inputValidation(N, M, maze, startX, startY, goalX, goalY);

    return rtnMinimumTurns(N, M, maze, startX, startY, goalX, goalY);

  } catch (const std::exception& e) {
    // Print the error message
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  return -1;
}
