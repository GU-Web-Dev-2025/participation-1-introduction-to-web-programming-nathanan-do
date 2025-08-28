#ifndef AVL_NODE_HPP
#define AVL_NODE_HPP

struct AVLNode {
    int pos;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int k) : pos(k), left(nullptr), right(nullptr), height(1) {}
};

#endif // AVL_NODE_HPP
