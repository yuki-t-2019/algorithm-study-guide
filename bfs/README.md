# Maze Solver using BFS
This repository contains a C++ program that solves the maze shortest path problem using the Breadth-First Search (BFS) algorithm.

## Breadth-First Search (BFS)
Breadth-First Search (BFS) is a graph traversal algorithm that explores all neighbors of a node before moving on to their neighbors. It is commonly used for finding the shortest path in unweighted graphs, making it ideal for solving maze and pathfinding problems.

```mermaid
---
title: Breadth-First Search (BFS) Algorithm
config:
  theme: dark
---
graph TD
    A([Start])
    B[Initialize a queue Q]
    C[Enqueue the starting node]
    D[Mark the starting node as visited]
    E{While Q<br/>is not<br/>empty}
    F[Dequeue node u from Q]
    G[For each unvisited neighbor v of u]
    H[Mark v as visited]
    I[Enqueue v into Q]
    J([End])

    A --> B
    B --> C
    C --> D
    D --> E
    E --> |yes|F
    F --> G
    G --> H
    H --> I
    I --> E
    E --> |no|J
```

## Problem Description
Given a maze of size `N x M` composed of passages and walls, determine the minimum number of turns required to move from the start to the goal. You can move to adjacent cells (up, down, left, right) in one turn. It is guaranteed that there is a path from the start to the goal.

### Constraints
- `1 <= N, M <= 100`

### Input
- An integer `N`: the number of rows in the maze.
- An integer `M`: the number of columns in the maze.
- A `N x M` grid representing the maze, where `'#'` denotes a wall, `'+'` denotes a passage, `'S'` denotes the start, and `'G'` denotes the goal.

### Output
- An integer representing the minimum number of turns required to move from the start to the goal.

#### Input & Output sample
```
10 10
#S######+#
++++++#++#
+#+##+##+#
+#++++++++
##+##+####
++++#++++#
+#######+#
++++#+++++
+####+###+
++++#+++G#

22
```

## Author
Yuki Tsuboi