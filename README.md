# Algorithm Study Guide
This repository contains a variety of algorithms implemented in C++. 
While primarily intended as a personal study guide, others are welcome to reference and provide comments on it.

## Table of Contents
- [Getting Started](#getting-started)
- [Folder Structure](#folder-structure)
- [Algorithms](#algorithms)
- [Usage](#usage)
- [License](#license)


## Getting Started
### Prerequisites
- C++ compiler (e.g., g++ 11.4.0 or later)
- CMake (version 3.22.1 or later)

### Installation
Clone the repository:
```bash
git clone https://github.com/yuki-t-2019/algorithm-study-guide.git
cd algorithm-study-guide
```


## Folder Structure
The repository is organized by algorithm type.
Each algorithm has its own directory containing the implementation and relevant examples.
```
algorithm-study-guide/
├── dynamic_programming
│   └── dp
│       ├── CMakeLists.txt
│       ├── README.md
│       ├── scripts
│       │   ├── build_and_run.sh
│       │   └── build_test_and_run.sh
│       ├── src
│       │   ├── dp.cpp
│       │   ├── dp.h
│       │   └── main.cpp
│       └── test
│           └── test_dp.cpp
├── graph_algorithms
│   ├── bellman-ford
│   ├── bfs
│   ├── dfs
│   ├── dijkstra
│   └── uft
├── greedy_algorithms
│   └── greedy
├── tree_algorithms
│   ├── bst
│   └── heap
├── LICENSE.txt
└── README.md
```

## Algorithms

### Graph Algorithms
#### Bellman-Ford Algorithm
The Bellman-Ford Algorithm is a graph search algorithm that computes the shortest paths from a single source vertex to all other vertices in a weighted graph. It is capable of handling graphs with negative weight edges. The algorithm works by repeatedly relaxing all edges in the graph, ensuring that the shortest path to each vertex is found. Unlike Dijkstra's Algorithm, the Bellman-Ford Algorithm can detect negative weight cycles and report their existence.

#### Breadth-First Search (BFS)
Breadth-First Search (BFS) is a graph traversal algorithm that explores vertices in the order of their distance from the source vertex. It starts at the source vertex and explores all of its neighbors before moving to the next level of vertices.

#### Depth-First Search (DFS)
Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It traverses deep into the graph structure before exploring neighboring vertices.

#### Dijkstra's Algorithm
Dijkstra's Algorithm is a graph search algorithm that solves the single-source shortest path problem for a graph with non-negative edge weights. It finds the shortest path from a starting vertex to all other vertices in the graph. The algorithm maintains a set of unvisited vertices and calculates tentative distances to each vertex, updating them as shorter paths are found. Once the shortest path to a vertex is determined, it is marked as visited and the process continues until all vertices are visited. The algorithm uses a priority queue to efficiently select the next vertex with the smallest tentative distance.

#### Union-Find (Disjoint Set Union, UFT)
Union-Find (also known as Disjoint Set Union or UFT) is a data structure that efficiently supports union and find operations on disjoint sets. It is useful for problems involving dynamic connectivity, such as determining connected components in graphs or managing equivalence relations. The structure maintains a collection of disjoint sets and supports operations to unite two sets and find the representative element of a set. Path compression and union by rank/heuristic are commonly used techniques to optimize these operations.

### Tree Algorithms
#### Binary Search Tree (BST)
A Binary Search Tree (BST) is a node-based binary tree data structure where each node has at most two children referred to as the left child and the right child. For each node, the left subtree contains only nodes with keys less than the node's key, and the right subtree contains only nodes with keys greater than the node's key. BSTs allow efficient insertion, deletion, and lookup operations.

#### Heap
A heap is a specialized tree-based data structure that satisfies the heap property. In a max heap, the value of each node is greater than or equal to the values of its children. A max heap ensures that the parent node is always greater than or equal to its child nodes, making it useful for efficiently retrieving the maximum element. Heaps are commonly used to implement priority queues. They are commonly implemented using binary trees.

### Dynamic Programming
#### Dynamic Programming (DP)
Dynamic Programming (DP) is an algorithmic paradigm used to solve problems by breaking them down into simpler subproblems and storing their solutions. It optimizes recursive problems with overlapping subproblems.

### Greedy Algorithms
#### Greedy Algorithms
Greedy algorithms are problem-solving strategies that make the locally optimal choice at each stage with the hope of finding a global optimum. These algorithms make decisions based solely on the information available at the current step without considering future consequences.

**Note:**
While these algorithms are implemented for educational purposes, many of them are available in standard libraries of various programming languages. For practical applications, it is recommended to use these libraries for optimized and well-tested implementations.



## Usage
### Using a simple Script:
```
cd [algo-directory]/scripts
./build_and_run.sh
```
### WithTests:
```
cd [algo-directory]/scripts
./build_test_and_run.sh
```


## License
This project is licensed under the MIT License - see the LICENSE.txt file for details.
