/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: heap.cpp
 */

#include "src/heap.h"

/**
 * @brief Constructs a new MaxHeap object.
 */
MaxHeap::MaxHeap() {}

/**
 * @brief Inserts a value into the heap.
 * @param value The value to be inserted.
 */
void MaxHeap::Push(int value) {
  heap_.push_back(value);
  HeapifyUp(heap_.size() - 1);
}

/**
 * @brief Retrieves the maximum value in the heap.
 * @return The maximum value.
 * @throws std::out_of_range If the heap is empty.
 */
int MaxHeap::Top() const {
  if (heap_.empty()) {
    throw std::out_of_range("Heap is empty");
  }
  return heap_[0];
}

/**
 * @brief Removes the maximum value from the heap.
 * @throws std::out_of_range If the heap is empty.
 */
void MaxHeap::Pop() {
  if (heap_.empty()) {
    throw std::out_of_range("Heap is empty");
  }
  heap_[0] = heap_.back();
  heap_.pop_back();
  HeapifyDown(0);
}

/**
 * @brief Checks if the heap is empty.
 * @return True if the heap is empty, false otherwise.
 */
bool MaxHeap::Empty() const {
  return heap_.empty();
}

/**
 * @brief Retrieves the number of elements in the heap.
 * @return The number of elements.
 */
size_t MaxHeap::Size() const {
  return heap_.size();
}

/**
 * @brief Restores the heap property by moving the element at index up.
 * @param index The index of the element to move up.
 */
void MaxHeap::HeapifyUp(int index) {
  while (index > 0) {
    int parent = (index - 1) / 2;
    if (heap_[parent] < heap_[index]) {
      std::swap(heap_[parent], heap_[index]);
      index = parent;
    } else {
      break;
    }
  }
}

/**
 * @brief Restores the heap property by moving the element at index down.
 * @param index The index of the element to move down.
 */
void MaxHeap::HeapifyDown(int index) {
  int size = heap_.size();
  while (index < size) {
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    int largest = index;

    if (left_child < size && heap_[left_child] > heap_[largest]) {
      largest = left_child;
    }

    if (right_child < size && heap_[right_child] > heap_[largest]) {
      largest = right_child;
    }

    if (largest != index) {
      std::swap(heap_[index], heap_[largest]);
      index = largest;
    } else {
      break;
    }
  }
}

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
  
  int num_of_refuel = 0;

  try {
    InputValidation(N, L, P, A, B);

    // Add the destination to the fuel station lists
    std::vector<int> distances = A;
    std::vector<int> fuel_provided = B;
    distances.push_back(L);
    fuel_provided.push_back(0);

    // Initialize a max heap to track available fuel
    MaxHeap fuel_heap;

    int current_position = 0;
    int current_fuel = P;

    for (size_t i = 0; i < distances.size(); i++) {
      // Calculate the distance to the next fuel station
      int distance_to_next = distances[i] - current_position;

      // Refuel if necessary
      while (current_fuel - distance_to_next < 0) {
        if (fuel_heap.Empty()) {
          // Cannot reach the destination
          return -1;
        }

        // Refuel from the max heap
        current_fuel += fuel_heap.Top();
        fuel_heap.Pop();
        num_of_refuel++;
      }

      // Update current position and fuel level
      current_fuel -= distance_to_next;
      current_position = distances[i];
      fuel_heap.Push(fuel_provided[i]);
    }

  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  return num_of_refuel;
}