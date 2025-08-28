Name:           Nathan Doan
Class:          CPSC 223
Professor:      Luke Johnson
Last Modified:  29 April 2025
Description: 
This project implements an AVL Tree in C++. It includes:
- "AVLNode" and "AVLTree" classes (in "avl_node.hpp", "avl_tree.hpp", "avl_tree.cpp")
- Unit tests in "test_avl_tree.cpp"
- "main.cpp" inserts the first 25 Fibonacci numbers and prints the tree
 
### Building and Running

compile:
g++ main.cpp avl_tree.cpp -o avl_fib

Run:
./avl_fib

### Build and Run Tests

compile:
g++ test_avl_tree.cpp avl_tree.cpp -o avl_test

Run:
./avl_test

### Files
- "avl_node.hpp": Defines the "AVLNode" struct
- "avl_tree.hpp" / "avl_tree.cpp": Implement the "AVLTree" class
- "test_avl_tree.cpp": Unit tests for core AVL Tree functionality
- "main.cpp": insert Fibonacci numbers
