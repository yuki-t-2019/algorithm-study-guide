# Union-Find Tree (Disjoint Set)
This repository contains a C++ program that utilizes Union-Find (Disjoint Set) data structure to manage a set of animals categorized into three types.

## Union-Find Tree (Disjoint Set)
Union-Find (Disjoint Set) is a data structure that efficiently manages a collection of disjoint sets. It supports two main operations:
- **Find**: Determine which subset a particular element is in.
- **Union**: Merge two subsets into a single subset.

## Problem Description
There are N animals numbered from 1 to N, each belonging to one of three types: A, B, or C. Type relationships are as follows:
- A eats B
- B eats C
- C eats A

You are given k pieces of information in sequence:
- **Type 1**: Animals x and y belong to the same type.
- **Type 2**: Animal x eats animal y.

Some of these pieces of information might be contradictory or incorrect (e.g., referring to non-existent animal numbers). Your task is to determine how many of these pieces of information are valid and can be processed.

### Constraints
- 1 <= N <= 50,000
- 0 <= k <= 100,000

### Input
```
N k
type x y
```
- An integer `N` representing the number of animals.
- An integer `k` representing the number of information pieces.
- `type`: Either `1` (same type) or `2` (eats relationship).
- `x` and `y`: Integers representing animal numbers (1 to N).

### Output
An integer representing the number of valid pieces of information that can be processed without contradictions or errors.

### Example
#### Input
```
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
```

#### Output
```
3
```
Explanation: Out of the 7 pieces of information, 3 are valid and can be processed correctly.

## Solution Approach
To solve this problem efficiently using Union-Find:
1. **Initialize** a Union-Find structure with N elements, one for each animal.
2. **Process** each information piece:
   - For Type 1 (`1 x y`), union the sets containing animals x and y.
   - For Type 2 (`2 x y`), check if animals x and y are in different sets to avoid creating a cycle.
3. **Count** and output the number of valid information pieces processed.

## Author
Your Name