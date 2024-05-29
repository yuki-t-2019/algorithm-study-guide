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
Enter the number of items:
4

Enter the weight and value of each item:
2 3
1 2
3 3
2 2

Enter the maximum weight capacity:
5
```

#### Output
```
7
```
Explanation: By selecting the items with weights and values (2, 3), (1, 2), and (2, 2), the total weight is 5 and the total value is 7, which is the maximum possible value without exceeding the weight limit.

### Recurrence Relation
The dynamic programming solution is built using the following recurrence relation:

- `dp_memo[i][j]` represents the maximum value that can be achieved using the items from index `i` to the end, with a remaining capacity of `j`.

- If the weight of the item at index `i` is greater than the remaining capacity `j`:

```
dp_memo[i][j] = dp_memo[i + 1][j]
```
This means the item cannot be included in the knapsack.

- Otherwise:
```
dp_memo[i][j] = max(dp_memo[i + 1][j], dp_memo[i + 1][j - items[i].weight] + items[i].value)
```
This means the maximum value is the greater of either including the item or not including the item.


## Author
Yuki Tsuboi