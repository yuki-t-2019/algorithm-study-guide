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

int heap(const int& N, const int& L, const int& P,
         const std::vector<int>& A, const std::vector<int>& B);

#endif  // HEAP_SRC_HEAP_H_
