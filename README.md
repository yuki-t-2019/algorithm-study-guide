# Algorithm Study Guide

This repository contains a variety of algorithms implemented in C++. 
While primarily intended as a personal study guide, others are welcome to reference and provide comments on it.

## Table of Contents
- [Getting Started](#getting-started)
- [Folder Structure](#folder-structure)
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
│
├── LICENSE.txt
└── README.md

```

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

