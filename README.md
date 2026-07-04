# 🌲 LinkBinaryTree - Robust Linked Binary Tree Implementation in C

[![Language](https://img.shields.io/badge/Language-C99-blue.svg)](https://en.wikipedia.org/wiki/C99)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-Binary%20Tree-orange.svg)]()
[![Algorithm](https://img.shields.io/badge/Algorithm-DFS%20%2F%20BFS-red.svg)]()

A pure **C implementation** of a linked binary tree, showcasing core algorithms and data structure operations. Built with strict defensive checks against null pointers and precise memory management, this project aligns with production-grade standards and technical interview expectations.

---

## 🛠️ Core Functions & API Matrix

The system implements key tree operations utilizing efficient divide-and-conquer and recursive patterns:

### 1. Base Management & Search
*   `BTNode* BuyNode(BNTDataType x)`: Safely allocates memory for a new node with built-in `malloc` verification.
*   `BTNode* BinaryTreeCreate()`: Constructs a static binary tree for structural testing.
*   `BTNode* BinaryTreeFind(BTNode* root, BNTDataType x)`: Recursively locates a node by its value. Uses local pointer caching to return the target instantly up the call stack upon discovery.
*   `void BinaryTreeDestroy(BTNode** root)` / `BinaryTreeDestroy(BTNode* root)`: Safely deallocates the entire tree using post-order traversal to prevent memory leaks and dangling pointers.

### 2. The Four Tree Traversals
*   **Pre-Order (`PreOrder`)**: Root $\rightarrow$ Left $\rightarrow$ Right (Classic Depth-First Search).
*   **In-Order (`InOrder`)**: Left $\rightarrow$ Root $\rightarrow$ Right.
*   **Post-Order (`PostOrder`)**: Left $\rightarrow$ Right $\rightarrow$ Root.
*   **Level-Order (`LevelOrder`)**: Breadth-First Search (BFS) utilizing a custom FIFO Queue.

### 3. Divide-and-Conquer Metrics
*   `BinaryTreeSize`: Counts the total number of nodes in the tree.
*   `BinaryTreeLeafSize`: Identifies and counts all leaf nodes (nodes with no children).
*   `BinaryTreeLevelSize`: Calculates the number of nodes present at a specific depth $k$.
*   `BinaryTreeDepth`: Computes the maximum height of the tree using performance-optimized depth tracking.

---

## 📐 Test Tree Topology

The default tree structure constructed for testing is organized as follows:

```text
      A          —— Level 1
     / \
    B   C        —— Level 2
   /   / \
  D   E   F      —— Level 3
