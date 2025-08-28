#include <iostream>
#include "avl_tree.hpp"

int main() {
    AVLTree tree;
    int a = 0, b = 1;
    for (int i = 0; i < 25; ++i) {
        tree.insert(a);
        int next = a + b;
        a = b;
        b = next;
    }
    std::cout << "AVL Tree In-Order after inserting first 25 Fibonacci numbers:\n";
    tree.printInOrder();
    return 0;
}
