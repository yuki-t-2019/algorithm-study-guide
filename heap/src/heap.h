/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: heap.cpp
 */

#ifndef HEAP_SRC_HEAP_H_
#define HEAP_SRC_HEAP_H_

#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <vector>


const int MIN_FUEL_STATIONS = 1;
const int MAX_FUEL_STATIONS = 10000;
const int MIN_DISTANCE = 1;
const int MAX_DISTANCE = 1000000;
const int MIN_INITIAL_FUEL = 1;
const int MAX_INITIAL_FUEL = 1000000;
const int MIN_FUEL_AMOUNT = 1;
const int MAX_FUEL_AMOUNT = 100;

/**
 * @brief A class representing a max heap.
 */
class MaxHeap {
 public:
  /**
   * @brief Constructs a new MaxHeap object.
   */
  MaxHeap();

  /**
   * @brief Inserts a value into the heap.
   * @param value The value to be inserted.
   */
  void Push(int value);

  /**
   * @brief Retrieves the maximum value in the heap.
   * @return The maximum value.
   * @throws std::out_of_range If the heap is empty.
   */
  int Top() const;

  /**
   * @brief Removes the maximum value from the heap.
   * @throws std::out_of_range If the heap is empty.
   */
  void Pop();

  /**
   * @brief Checks if the heap is empty.
   * @return True if the heap is empty, false otherwise.
   */
  bool Empty() const;

  /**
   * @brief Retrieves the number of elements in the heap.
   * @return The number of elements.
   */
  size_t Size() const;

 private:
  std::vector<int> heap_;

  /**
   * @brief Restores the heap property by moving the element at index up.
   * @param index The index of the element to move up.
   */
  void HeapifyUp(int index);

  /**
   * @brief Restores the heap property by moving the element at index down.
   * @param index The index of the element to move down.
   */
  void HeapifyDown(int index);
};

void InputValidation(const int& N, const int& L, const int& P,
                     const std::vector<int>& A, const std::vector<int>& B);

int heap(const int& N, const int& L, const int& P,
         const std::vector<int>& A, const std::vector<int>& B);

#endif  // HEAP_SRC_HEAP_H_
