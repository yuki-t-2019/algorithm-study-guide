/*
 * Copyright (c) 2024 Yuki Tsuboi
 *
 * File: main.cpp
 * Description: This program processes a series of queries on a set of numbers
 *              using a Binary Search Tree (BST) approach.
 *
 * Input:
 * - An integer `Q` representing the number of queries.
 * - Query lines follow, each containing:
 *   - Ti=1 for a Type 1 query.
 *   - Ti=2 for a Type 2 query.
 *
 * Output:
 * - For each Type 2 query, outputs the `X`-th smallest number in the set.
 */

#include "src/bst.h"

/**
 * @brief Checks if a given string represents a valid integer.
 * 
 * This function attempts to convert the input string to an integer using
 * a stringstream. If the conversion succeeds and there are no remaining
 * characters in the stream, the function returns true.
 * Otherwise, it returns false.
 * 
 * @param s The input string to be checked.
 * @return true if the string represents a valid integer, false otherwise.
 */
bool isInteger(const std::string& s) {
  std::istringstream iss(s);
  int x;
  return (iss >> x) && (iss.eof());
}

int main() {
    // Prompt the user for input
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string input;
    int Q;

    // Read the number of queries
    std::cout << "Enter the number of queries:" << std::endl;
    std::cin >> input;
    if (!isInteger(input)) {
        std::cerr << "Error: Invalid input. Please enter an integer." << std::endl;
        return -1;
    }
    Q = std::stoi(input);

    std::vector<std::pair<int, int>> queries;
    std::cout << '\n' << "Enter the queries:" << std::endl;
    for (int i = 0; i < Q; ++i) {
        int type, X;
        std::cin >> type >> X;
        if ((type != 1 && type != 2) || !isInteger(std::to_string(X))) {
            std::cerr << "Error: Invalid input. Please enter valid queries." << std::endl;
            return -1;
        }
        queries.push_back({type, X});
    }

    // Call the bst function with the collected queries
    bst(Q, queries);

    return 0;
}
