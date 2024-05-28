/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: dp.cpp
 */

#ifndef DP_SRC_DP_H_
#define DP_SRC_DP_H_

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>

constexpr int MIN_ITEM_WEIGHT = 1;
constexpr int MAX_ITEM_WEIGHT = 100;
constexpr int MIN_ITEM_VALUE = 1;
constexpr int MAX_ITEM_VALUE = 100;
constexpr int MIN_WEIGHT_CAPACITY = 1;
constexpr int MAX_WEIGHT_CAPACITY = 10000;

struct Item {
    int weight;
    int value;
};

void InputValidation(const std::vector<Item>& items, const int& W);
int dp(const std::vector<Item>& items, const int& W);

#endif  // DP_SRC_DP_H_
