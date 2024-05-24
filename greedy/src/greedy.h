/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: greedy.h
 */

#ifndef GREEDY_SRC_GREEDY_H_
#define GREEDY_SRC_GREEDY_H_

#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>

constexpr int MAX_COIN_QUANTITY = 1000000000;
constexpr int MAX_AMOUNT = 1000000000;

struct Coin {
    int value;
    long long quantity;
};

void InputValidation(const std::vector<Coin>& coins, const int& a);
int Greedy(const std::vector<Coin>& coins, const int& a);

#endif  // GREEDY_SRC_GREEDY_H_
