#include "avl_tree.hpp"
#include <algorithm>
#include <functional>

// Constructor
AVLTree::AVLTree() : root(nullptr) {}

// Destructor
AVLTree::~AVLTree() {
    std::function<void(AVLNode*)> deletePost = [&](AVLNode* node) {
        if (!node) return;
        deletePost(node->left);
        deletePost(node->right);
        delete node;
    };
    deletePost(root);
}

// Utility functions
int AVLTree::getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalance(AVLNode* node) {
    if (!node) return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* AVLTree::rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* AVLTree::rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert pos
AVLNode* AVLTree::insert(AVLNode* node, int pos) {
    if (!node)
        return new AVLNode(pos);
    if (pos < node->pos)
        node->left = insert(node->left, pos);
    else if (pos > node->pos)
        node->right = insert(node->right, pos);
    else
        return node; // duplicates not allowed

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // LL
    if (balance > 1 && pos < node->left->pos)
        return rotateRight(node);
    // RR
    if (balance < -1 && pos > node->right->pos)
        return rotateLeft(node);
    // LR
    if (balance > 1 && pos > node->left->pos) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // RL
    if (balance < -1 && pos < node->right->pos) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Delete pos
AVLNode* AVLTree::minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left)
        current = current->left;
    return current;
}

AVLNode* AVLTree::deleteNode(AVLNode* node, int pos) {
    if (!node) return node;
    if (pos < node->pos)
        node->left = deleteNode(node->left, pos);
    else if (pos > node->pos)
        node->right = deleteNode(node->right, pos);
    else {
        if (!node->left || !node->right) {
            AVLNode* temp = node->left ? node->left : node->right;
            if (!temp) {
                temp = node;
                node = nullptr;
            } else
                *node = *temp;
            delete temp;
        } else {
            AVLNode* temp = minValueNode(node->right);
            node->pos = temp->pos;
            node->right = deleteNode(node->right, temp->pos);
        }
    }
    if (!node) return node;

    node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // LL
    if (balance > 1 && getBalance(node->left) >= 0)
        return rotateRight(node);
    // LR
    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    // RR
    if (balance < -1 && getBalance(node->right) <= 0)
        return rotateLeft(node);
    // RL
    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Public insert
void AVLTree::insert(int pos) {
    root = insert(root, pos);
}

// Public remove
void AVLTree::remove(int pos) {
    root = deleteNode(root, pos);
}

// Search
bool AVLTree::contains(AVLNode* node, int pos) {
    if (!node) return false;
    if (pos < node->pos)
        return contains(node->left, pos);
    else if (pos > node->pos)
        return contains(node->right, pos);
    else
        return true;
}

bool AVLTree::contains(int pos) {
    return contains(root, pos);
}

// Traversals
void AVLTree::printInOrder(AVLNode* node) {
    if (!node) return;
    printInOrder(node->left);
    std::cout << node->pos << " ";
    printInOrder(node->right);
}

void AVLTree::printPreOrder(AVLNode* node) {
    if (!node) return;
    std::cout << node->pos << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

void AVLTree::printInOrder() {
    printInOrder(root);
    std::cout << std::endl;
}

void AVLTree::printPreOrder() {
    printPreOrder(root);
    std::cout << std::endl;
}
