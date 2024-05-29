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
├── bfs
│   ├── CMakeLists.txt
│   ├── README.md
│   ├── scripts
│   │   ├── build_and_run.sh
│   │   └── build_test_and_run.sh
│   ├── src
│   │   ├── bfs.cpp
│   │   ├── bfs.h
│   │   └── main.cpp
│   └── test
│       └── test_bfs.cpp
├── dfs
│   ├── ...
├── dp
│   ├── ...
├── greedy
│   ├── ...
│
├── LICENSE.txt
└── README.md
```

## Algorithms
### Breadth-First Search (BFS)
Breadth-First Search (BFS) is a graph traversal algorithm that explores vertices in the order of their distance from the source vertex. It starts at the source vertex and explores all of its neighbors before moving to the next level of vertices.

### Depth-First Search (DFS)
Depth-First Search (DFS) is a graph traversal algorithm that explores as far as possible along each branch before backtracking. It traverses deep into the graph structure before exploring neighboring vertices.

### Dynamic Programming (DP)
Dynamic Programming (DP) is an algorithmic paradigm used to solve problems by breaking them down into simpler subproblems and storing their solutions. It optimizes recursive problems with overlapping subproblems.

### Greedy Algorithms
Greedy algorithms are problem-solving strategies that make the locally optimal choice at each stage with the hope of finding a global optimum. These algorithms make decisions based solely on the information available at the current step without considering future consequences.


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
