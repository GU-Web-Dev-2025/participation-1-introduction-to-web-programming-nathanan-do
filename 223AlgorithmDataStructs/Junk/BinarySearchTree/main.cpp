#include "bst.hpp"
#include <iostream>

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(90);

    std::cout << "In-order traversal: ";
    tree.in_order_traversal();

    std::cout << "Pre-order traversal: ";
    tree.pre_order_traversal();

    std::cout << "Post-order traversal: ";
    tree.post_order_traversal();

    std::cout << "Tree structure:" << std::endl;
    tree.print_tree();

    std::cout << "Search for 40: " << (tree.search(40) ? "Found" : "Not Found") << std::endl;

    tree.delete_node(50);
    std::cout << "After deleting 50: ";
    tree.print_tree();

    std::cout << "Tree depth: " << tree.calculate_depth() << std::endl;



    return 0;
}