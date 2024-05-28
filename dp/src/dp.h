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

struct Item {
    int weight;
    int value;
};

void InputValidation(const std::vector<Item>& items, const int& W);
int dp(const std::vector<Item>& items, const int& W);

#endif  // DP_SRC_DP_H_
