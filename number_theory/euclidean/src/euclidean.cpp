/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: euclidean.cpp
 */

#include "src/euclidean.h"

/**
 * @brief Validates the input coordinates.
 * 
 * Checks if the coordinates are within the specified valid ranges.
 * 
 * @param x1 The x-coordinate of the first point.
 * @param y1 The y-coordinate of the first point.
 * @param x2 The x-coordinate of the second point.
 * @param y2 The y-coordinate of the second point.
 * @return true if the input coordinates are valid, false otherwise.
 */
bool InputValidation(int x1, int y1, int x2, int y2) {
  return (MIN_COORD <= x1 && x1 <= MAX_COORD &&
          MIN_COORD <= y1 && y1 <= MAX_COORD &&
          MIN_COORD <= x2 && x2 <= MAX_COORD &&
          MIN_COORD <= y2 && y2 <= MAX_COORD);
}

/**
 * @brief Calculates the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
 * 
 * This function repeatedly applies the Euclidean algorithm to find the GCD of two integers.
 * 
 * @param a The first integer.
 * @param b The second integer.
 * @return The greatest common divisor of a and b.
 */
int GCD(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

/**
 * @brief Calculates the number of lattice points on the line segment between (x1, y1) and (x2, y2).
 * 
 * This function uses the GCD to determine the number of lattice points on the line segment,
 * excluding the endpoints.
 * 
 * @param x1 The x-coordinate of the first point.
 * @param y1 The y-coordinate of the first point.
 * @param x2 The x-coordinate of the second point.
 * @param y2 The y-coordinate of the second point.
 * @return The number of lattice points on the line segment between (x1, y1) and (x2, y2), excluding the endpoints.
 */
int Euclidean(int x1, int y1, int x2, int y2) {
  if (!InputValidation(x1, y1, x2, y2)) {
    std::cerr << "Error: Input constraints violated. (x, y) must be in range [" 
      << MIN_COORD << ", " << MAX_COORD << "]" << std::endl;
    return -1;
  }

  int dx = abs(x2 - x1);
  int dy = abs(y2 - y1);
  return GCD(dx, dy) - 1;
}
