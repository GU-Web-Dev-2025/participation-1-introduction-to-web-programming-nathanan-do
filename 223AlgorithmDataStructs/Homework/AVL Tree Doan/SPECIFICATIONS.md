# Specifications and Additional Features

This document lists features added or modified beyond a basic Binary Search Tree (BST).

## 1. Self-Balancing (AVL)
- **Height Tracking**: Each `AVLNode` stores `height`.
- **Balance Factor**: Computed as `height(left) - height(right)`.
- **Rotations**: Four rotation cases implemented:
  - Left-Left (LL) case: `rotateRight`
  - Right-Right (RR) case: `rotateLeft`
  - Left-Right (LR) case: Double rotation (`rotateLeft` on left child, then `rotateRight` on node).
  - Right-Left (RL) case: Double rotation (`rotateRight` on right child, then `rotateLeft` on node).

## 2. Deletion with Rebalancing
- **deleteNode**: Recursively deletes a node, then rebalances the tree.
- **minValueNode**: Finds in-order successor for deletion of nodes with two children.

## 3. Search (contains)
- `contains(int key)`: Efficient O(log n) search using BST property.

## 4. Traversals
- `printInOrder()`: In-order traversal (sorted order).
- `printPreOrder()`: Pre-order traversal.

## 5. Utility
- **Demo in `main.cpp`**: Inserts the first 25 Fibonacci numbers.
- **Unit Tests**: Validate insertion, deletion (leaf, node with two children), and traversal.
