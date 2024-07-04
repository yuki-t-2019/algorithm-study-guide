/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: bst.h
 */

#ifndef BST_SRC_BST_H_
#define BST_SRC_BST_H_

#include <iostream>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

constexpr int MIN_QUERY = 1;
constexpr int MAX_QUERY = 200000;
constexpr int MIN_NUMBER = 1;
constexpr int MAX_NUMBER = 200000;

// Forward declaration of BSTNode structure
struct BSTNode;

/**
 * @brief Represents a binary search tree (BST).
 */
class BST {
 public:
  BST();

  /**
   * @brief Inserts a value into the BST.
   * @param value The value to be inserted.
   */
  void Insert(int value);

  /**
   * @brief Retrieves the k-th smallest value in the BST.
   * @param k The order of the smallest value to retrieve.
   * @return The k-th smallest value.
   * @throws std::out_of_range If k is larger than the size of the BST.
   */
  int FindKthSmallest(int k);

  /**
   * @brief Deletes the k-th smallest value from the BST.
   * @param k The order of the smallest value to delete.
   * @throws std::out_of_range If k is larger than the size of the BST.
   */
  void DeleteKthSmallest(int k);

 private:
  BSTNode* root_;

  /**
   * @brief Helper function to insert a value into the BST.
   * @param node The current node in the BST.
   * @param value The value to be inserted.
   * @return The new root of the BST.
   */
  BSTNode* InsertRec(BSTNode* node, int value);

  /**
   * @brief Helper function to find the k-th smallest value in the BST.
   * @param node The current node in the BST.
   * @param k The order of the smallest value to retrieve.
   * @return The k-th smallest value.
   */
  int FindKthSmallestRec(BSTNode* node, int k);

  /**
   * @brief Helper function to delete the k-th smallest value from the BST.
   * @param node The current node in the BST.
   * @param k The order of the smallest value to delete.
   * @return The new root of the BST.
   */
  BSTNode* DeleteKthSmallestRec(BSTNode* node, int k);

  /**
   * @brief Helper function to find the minimum value node in the BST.
   * @param node The current node in the BST.
   * @return The node with the minimum value.
   */
  BSTNode* FindMin(BSTNode* node);

  /**
   * @brief Helper function to delete a node with a specific value from the BST.
   * @param node The current node in the BST.
   * @param value The value to be deleted.
   * @return The new root of the BST.
   */
  BSTNode* DeleteRec(BSTNode* node, int value);

  /**
   * @brief Returns the size of the subtree rooted at the given node.
   * @param node The root of the subtree.
   * @return The size of the subtree.
   */
  int Size(BSTNode* node);
};

/**
 * @brief Validates the input parameters for the BST problem.
 * @param q The number of queries.
 * @param queries A vector of pairs representing the queries.
 * @throws std::invalid_argument if any input is invalid.
 * @throws std::out_of_range if any Type 2 query cannot be satisfied.
 */
void InputValidation(int q, const std::vector<std::pair<int, int>>& queries);

/**
 * @brief Main function to process BST operations.
 * @param q The number of queries.
 * @param queries A vector of pairs representing the queries.
 * @return 0 on success, -1 on failure.
 */
int bst(int q, const std::vector<std::pair<int, int>>& queries);


#endif  // BST_SRC_BST_H_
