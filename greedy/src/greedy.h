/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: greedy.h
 */

#ifndef GREEDY_SRC_GREEDY_H_
#define GREEDY_SRC_GREEDY_H_

#include <iostream>
#include <vector>
#include <algorithm>

struct Coin {
    int value;
    long long quantity;
};

int Greedy(const std::vector<Coin> coins, const int& a);

#endif  // GREEDY_SRC_GREEDY_H_
