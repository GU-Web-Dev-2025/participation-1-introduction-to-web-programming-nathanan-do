#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include "avl_node.hpp"
#include <iostream>

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node);
    int getBalance(AVLNode* node);
    AVLNode* rotateLeft(AVLNode* x);
    AVLNode* rotateRight(AVLNode* y);
    AVLNode* insert(AVLNode* node, int pos);
    AVLNode* deleteNode(AVLNode* node, int pos);
    AVLNode* minValueNode(AVLNode* node);
    bool contains(AVLNode* node, int pos);
    void printInOrder(AVLNode* node);
    void printPreOrder(AVLNode* node);

public:
    AVLTree();
    ~AVLTree();

    void insert(int pos);
    void remove(int pos);
    bool contains(int pos);
    void printInOrder();
    void printPreOrder();
};

#endif // AVL_TREE_HPP
