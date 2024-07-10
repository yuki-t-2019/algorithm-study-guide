/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: euclidean.h
 */

#ifndef EUCLIDEAN_SRC_EUCLIDEAN_H_
#define EUCLIDEAN_SRC_EUCLIDEAN_H_

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

// Constants for input validation
constexpr int MIN_COORD = -1000000;
constexpr int MAX_COORD = 1000000;

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
bool InputValidation(int x1, int y1, int x2, int y2);

/**
 * @brief Calculates the greatest common divisor (GCD) of two integers using the Euclidean algorithm.
 * 
 * @param a The first integer.
 * @param b The second integer.
 * @return The greatest common divisor of a and b.
 */
int GCD(int a, int b);

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
int Euclidean(int x1, int y1, int x2, int y2);

#endif  // EUCLIDEAN_SRC_EUCLIDEAN_H_
