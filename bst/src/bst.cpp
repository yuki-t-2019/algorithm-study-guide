/*
 * Copyright (c) 2024 Yuki Tsuboi
 * 
 * File: bst.cpp
 */

#include "src/bst.h"

/**
 * @brief Represents a node in the binary search tree.
 */
struct BSTNode {
  int value;
  BSTNode* left;
  BSTNode* right;
  explicit BSTNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief Constructs a new BST object.
 */
BST::BST() : root_(nullptr) {}

/**
 * @brief Inserts a value into the BST.
 * @param value The value to be inserted.
 */
void BST::Insert(int value) {
  root_ = InsertRec(root_, value);
}

/**
 * @brief Retrieves the k-th smallest value in the BST.
 * @param k The order of the smallest value to retrieve.
 * @return The k-th smallest value.
 * @throws std::out_of_range If k is larger than the size of the BST.
 */
int BST::FindKthSmallest(int k) {
  if (root_ == nullptr) {
    throw std::out_of_range("BST is empty");
  }
  return FindKthSmallestRec(root_, k);
}

/**
 * @brief Deletes the k-th smallest value from the BST.
 * @param k The order of the smallest value to delete.
 * @throws std::out_of_range If k is larger than the size of the BST.
 */
void BST::DeleteKthSmallest(int k) {
  root_ = DeleteKthSmallestRec(root_, k);
}

/**
 * @brief Helper function to insert a value into the BST.
 * @param node The current node in the BST.
 * @param value The value to be inserted.
 * @return The new root of the BST.
 */
BSTNode* BST::InsertRec(BSTNode* node, int value) {
  if (node == nullptr) {
    return new BSTNode(value);
  }
  if (value < node->value) {
    node->left = InsertRec(node->left, value);
  } else {
    node->right = InsertRec(node->right, value);
  }
  return node;
}

/**
 * @brief Helper function to find the k-th smallest value in the BST.
 * @param node The current node in the BST.
 * @param k The order of the smallest value to retrieve.
 * @return The k-th smallest value.
 */
int BST::FindKthSmallestRec(BSTNode* node, int k) {
  int left_size = Size(node->left);
  if (k == left_size + 1) {
    return node->value;
  } else if (k <= left_size) {
    return FindKthSmallestRec(node->left, k);
  } else {
    return FindKthSmallestRec(node->right, k - left_size - 1);
  }
}

/**
 * @brief Helper function to delete the k-th smallest value from the BST.
 * @param node The current node in the BST.
 * @param k The order of the smallest value to delete.
 * @return The new root of the BST.
 */
BSTNode* BST::DeleteKthSmallestRec(BSTNode* node, int k) {
  int left_size = Size(node->left);
  if (k == left_size + 1) {
    if (node->left == nullptr) {
      BSTNode* right_node = node->right;
      delete node;
      return right_node;
    } else if (node->right == nullptr) {
      BSTNode* left_node = node->left;
      delete node;
      return left_node;
    } else {
      BSTNode* min_node = FindMin(node->right);
      node->value = min_node->value;
      node->right = DeleteRec(node->right, min_node->value);
    }
  } else if (k <= left_size) {
    node->left = DeleteKthSmallestRec(node->left, k);
  } else {
    node->right = DeleteKthSmallestRec(node->right, k - left_size - 1);
  }
  return node;
}

/**
 * @brief Helper function to find the minimum value node in the BST.
 * @param node The current node in the BST.
 * @return The node with the minimum value.
 */
BSTNode* BST::FindMin(BSTNode* node) {
  while (node->left != nullptr) {
    node = node->left;
  }
  return node;
}

/**
 * @brief Helper function to delete a node with a specific value from the BST.
 * @param node The current node in the BST.
 * @param value The value to be deleted.
 * @return The new root of the BST.
 */
BSTNode* BST::DeleteRec(BSTNode* node, int value) {
  if (node == nullptr) {
    return nullptr;
  }
  if (value < node->value) {
    node->left = DeleteRec(node->left, value);
  } else if (value > node->value) {
    node->right = DeleteRec(node->right, value);
  } else {
    if (node->left == nullptr) {
      BSTNode* right_node = node->right;
      delete node;
      return right_node;
    } else if (node->right == nullptr) {
      BSTNode* left_node = node->left;
      delete node;
      return left_node;
    } else {
      BSTNode* min_node = FindMin(node->right);
      node->value = min_node->value;
      node->right = DeleteRec(node->right, min_node->value);
    }
  }
  return node;
}

/**
 * @brief Returns the size of the subtree rooted at the given node.
 * @param node The root of the subtree.
 * @return The size of the subtree.
 */
int BST::Size(BSTNode* node) {
  if (node == nullptr) {
    return 0;
  }
  return 1 + Size(node->left) + Size(node->right);
}

/**
 * @brief Validates the input parameters for the BST problem.
 *
 * This function checks if the given inputs meet the problem's constraints.
 * It ensures that the number of queries and the values in each query
 * are within the specified ranges. If any input is invalid, the function
 * throws an `std::invalid_argument` exception.
 *
 * @param q The number of queries.
 * @param queries A vector of pairs representing the queries.
 * @throws std::invalid_argument if any input is invalid.
 */
void InputValidation(int q, const std::vector<std::pair<int, int>>& queries) {
  if (q < MIN_QUERY || q > MAX_QUERY) {
    throw std::invalid_argument("The number of queries (q) is out of range.");
  }
  for (const auto& query : queries) {
    int type = query.first;
    int x = query.second;
    if (type != 1 && type != 2) {
      throw std::invalid_argument("Invalid query type.");
    }
    if (x < MIN_NUMBER || x > MAX_NUMBER) {
      throw std::invalid_argument("Query value (x) is out of range.");
    }
  }
}

/**
 * @brief Processes a series of BST operations based on input queries.
 *
 * This function reads the input queries, validates them,
 * performs the corresponding BST operations (insert or find k-th smallest),
 * and prints the results of the FindKthSmallest operations.
 *
 * @param q The number of queries.
 * @param queries A vector of pairs representing the queries.
 *                Each pair consists of a query type and a value.
 *                Query type 1 indicates insertion of the value.
 *                Query type 2 indicates finding and deleting the k-th smallest value.
 * @return 0 on success, -1 on failure (invalid input or out-of-range access).
 */
int bst(int q, const std::vector<std::pair<int, int>>& queries) {
  std::vector<int> results;
  std::set<int> currentSet;

  try {
    InputValidation(q, queries);
    
    BST tree;
    for (const auto& query : queries) {
      int type = query.first;
      int x = query.second;
      
      if (type == 1) {
        // Before processing a Type 1 query, ensure that X is not in the set S
        if (currentSet.find(x) != currentSet.end()) {
          throw std::invalid_argument("Value already in set for Type 1 query.");
        }
        tree.Insert(x);
        currentSet.insert(x);
      } else if (type == 2) {
        // Before processing a Type 2 query, ensure that the set S contains at least X numbers
        if (currentSet.size() < x) {
          throw std::out_of_range("Not enough elements in set for Type 2 query.");
        }
        int result = tree.FindKthSmallest(x);
        results.push_back(result);
        tree.DeleteKthSmallest(x);
        currentSet.erase(result);
      }
    }
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  } catch (const std::out_of_range& e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return -1;
  }

  std::cout << "\n" << std::endl;
  for (const auto& result : results) {
    std::cout << result << std::endl;
  }

  return 0;
}
