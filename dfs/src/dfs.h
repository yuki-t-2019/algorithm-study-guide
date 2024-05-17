/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: dfs.h
 */

#ifndef DFS_SRC_DFS_H_
#define DFS_SRC_DFS_H_

#include <iostream>
#include <vector>

// Constants for input constraints
const int kLowerBound = -100000000;
const int kUpperBound = 100000000;
const int kMaxElements = 20;

bool Dfs(std::vector<int>::size_type index, int current_sum,
         const std::vector<int>& elements, int target_sum);

#endif  // DFS_SRC_DFS_H_
