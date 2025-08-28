#include <cassert>
#include <iostream>
#include "avl_tree.hpp"

bool test_insert_and_contains() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    assert(tree.contains(10));
    assert(tree.contains(20));
    assert(tree.contains(5));
    assert(!tree.contains(15));
    std::cout << "Insert and Contains: Passed\n";
    return true;
}

bool test_in_order_traversal() {
    AVLTree tree;
    int values[] = {30, 20, 40, 10, 25};
    for (int v : values) tree.insert(v);
    std::cout << "InOrder Traversal: ";
    tree.printInOrder();
    std::cout << "InOrder Traversal: Completed\n";
    return true;
}

bool test_delete_leaf() {
    AVLTree tree;
    int values[] = {20, 10, 30};
    for (int v : values) tree.insert(v);
    tree.remove(10);
    assert(!tree.contains(10));
    assert(tree.contains(20));
    assert(tree.contains(30));
    std::cout << "Delete Leaf: Passed\n";
    return true;
}

bool test_delete_node_with_two_children() {
    AVLTree tree;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for (int v : values) tree.insert(v);
    tree.remove(30);
    assert(!tree.contains(30));
    assert(tree.contains(20));
    assert(tree.contains(40));
    std::cout << "Delete Node with Two Children: Passed\n";
    return true;
}

int main() {
    std::cout << "Running AVL Tree Tests\n";
    test_insert_and_contains();
    test_in_order_traversal();
    test_delete_leaf();
    test_delete_node_with_two_children();
    std::cout << "All tests passed!\n";
    return 0;
}
