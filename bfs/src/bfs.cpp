/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: bfs.cpp
 */

#include "src/bfs.h"
#include "bfs.h"

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
  const int& N, const int& M, const char maze[MAX_N][MAX_M + 1],
  int &startX, int &startY, int &goalX, int &goalY) {
  startX = startY = goalX = goalY = -1; // Initialize with invalid positions

  for (int y = 0; y < N; ++y) {
    for (int x = 0; x < M; ++x) {
      if (maze[y][x] == 'S') {
        startX = x;
        startY = y;
      } else if (maze[y][x] == 'G') {
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
  const int& N, const int& M, const char maze[MAX_N][MAX_M + 1],
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
int Bfs(
  const int& N, const int& M, const char maze[MAX_N][MAX_M + 1]) {
  
  try {
    // Call the function to find the start and goal positions
    int startX, startY, goalX, goalY;
    findStartAndGoal(N, M, maze, startX, startY, goalX, goalY);

    // Input constraints validation
    inputValidation(N, M, maze, startX, startY, goalX, goalY);
    // Debug: Print the start and goal positions
    std::cout << "Start Position: (" << startX << ", " << startY << ")" << std::endl;
    std::cout << "Goal Position: (" << goalX << ", " << goalY << ")" << std::endl;

  } catch (const std::exception& e) {
    // Print the error message
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  return 0;
}
