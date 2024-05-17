#ifndef DFS_H
#define DFS_H

#include <iostream>
#include <vector>

// Constants for input constraints
const int kLowerBound = -100000000;
const int kUpperBound = 100000000;
const int kMaxElements = 20;

bool Dfs(std::vector<int>::size_type index, int current_sum, const std::vector<int>& elements, int target_sum);

#endif // DFS_H
