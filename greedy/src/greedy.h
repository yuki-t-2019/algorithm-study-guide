/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: greedy.cpp
 */

#ifndef GREEDY_SRC_GREEDY_H_
#define GREEDY_SRC_GREEDY_H_

#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>
#include <cstdint>  // For int64_t

constexpr int64_t MAX_COIN_QUANTITY = 1000000000;
constexpr int64_t MAX_AMOUNT = 1000000000;

struct Coin {
    int value;
    int64_t quantity;  // Changed from long to int64_t
};

void InputValidation(const std::vector<Coin>& coins, const int& a);
int Greedy(const std::vector<Coin>& coins, const int& a);

#endif  // GREEDY_SRC_GREEDY_H_
