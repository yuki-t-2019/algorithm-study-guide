# Knapsack Problem Solver using Dynamic Programming

This repository contains a C++ program that solves the knapsack problem using Dynamic Programming.

## Dynamic Programming
Dynamic Programming (DP) is an algorithmic paradigm that solves problems by breaking them down into simpler subproblems and solving each of these subproblems just once, storing their solutions. The next time the same subproblem occurs, instead of recomputing its solution, one simply looks up the previously computed solution, thereby saving computation time at the expense of storage space.

## Problem Description
Given `n` items, each with a weight `wi` and a value `vi`, determine the maximum total value of items that can be included in a knapsack of capacity `W`. The goal is to maximize the sum of the values of the items in the knapsack without exceeding its weight capacity.

### Constraints
- `1 <= n <= 100` (number of items)
- `1 <= wi, vi <= 100` (weight and value of each item)
- `1 <= W <= 10000` (maximum capacity of the knapsack)

### Input
- An integer `n` representing the number of items.
- A list of `n` pairs `(wi, vi)`, where each pair contains two integers representing the weight and value of an item.
- An integer `W` representing the maximum weight capacity of the knapsack.

### Output
- A single integer representing the maximum total value of items that can be included in the knapsack without exceeding its weight capacity.

### Input & Output Sample
#### Input
```
4
2 3
1 2
3 3
2 2
5
```

#### Output
```
7
```
Explanation: By selecting the items with weights and values (2, 3), (1, 2), and (2, 2), the total weight is 5 and the total value is 7, which is the maximum possible value without exceeding the weight limit.

## Author
Yuki Tsuboi