/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: heap.cpp
 */

#include "src/heap.h"

/**
 * @brief Validates the input parameters for the truck fueling problem.
 *
 * This function checks if the given inputs meet the problem's constraints.
 * It ensures that the number of fuel stations, total distance, initial fuel amount,
 * and the distances and fuel amounts at each station are within the specified ranges.
 * If any input is invalid, the function throws an `std::invalid_argument` exception.
 *
 * @param N The number of fuel stations.
 * @param L The total distance to travel.
 * @param P The initial amount of fuel.
 * @param A A vector of integers representing the distances of the fuel stations from the start.
 * @param B A vector of integers representing the amount of fuel each station provides.
 * @throws std::invalid_argument if any input is invalid.
 */
void InputValidation(const int& N, const int& L, const int& P,
                     const std::vector<int>& A, const std::vector<int>& B) {
  if (N < MIN_FUEL_STATIONS || N > MAX_FUEL_STATIONS) {
    throw std::invalid_argument("The number of fuel stations (N) is out of range.");
  }
  if (L < MIN_DISTANCE || L > MAX_DISTANCE) {
    throw std::invalid_argument("The total distance to travel (L) is out of range.");
  }
  if (P < MIN_INITIAL_FUEL || P > MAX_INITIAL_FUEL) {
    throw std::invalid_argument("The initial amount of fuel (P) is out of range.");
  }
  if (A.size() != N || B.size() != N) {
    throw std::invalid_argument("The size of vectors A and B must be equal to N.");
  }
  for (const auto& distance : A) {
    if (distance < MIN_DISTANCE || distance >= L) {
      throw std::invalid_argument("One or more distances in A are out of range.");
    }
  }
  for (const auto& fuel : B) {
    if (fuel < MIN_FUEL_AMOUNT || fuel > MAX_FUEL_AMOUNT) {
      throw std::invalid_argument("One or more fuel amounts in B are out of range.");
    }
  }
}

int heap(const int& N, const int& L, const int& P,
         const std::vector<int>& A, const std::vector<int>& B) {
  try {
    InputValidation(N, L, P, A, B);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }


  return 0;
}