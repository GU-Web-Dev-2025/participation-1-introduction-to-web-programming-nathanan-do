#include "bst.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>
// #include <algorithm>

Node::Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
}

Node::~Node() {
    if (left != nullptr){
        delete left;
        left = nullptr;
    }
    if (right != nullptr){
        delete right;
        right = nullptr;
    }
}

BST::BST() {
    root = nullptr;
}

BST::~BST() {
    if (root != nullptr) {
        delete root;
        root = nullptr;
    }
}

void BST::insert(int val) {
    insert(root, val);
}

bool BST::search(int val) {
    return search(root, val);
}

void BST::in_order_traversal() {
    in_order_traversal(root);
    std::cout << std::endl;
}

void BST::pre_order_traversal() {
    pre_order_traversal(root);
    std::cout << std::endl;
}

void BST::post_order_traversal() {
    post_order_traversal(root);
    std::cout << std::endl;
}

void BST::delete_node(int val) {
    root = delete_node(root, val);
}

int BST::calculate_depth() {
    return calculate_depth(root);
}

void BST::print_tree() {
    print_tree(root, 0);
}

void BST::insert(Node*& node, int val) {
    if(node==nullptr){
        Node* new_node = new Node(val);
        node = new_node;
        return;
    }else if(val < node->data){
        insert(node->left, val);
    }else{
        insert(node->right, val);
    }

}

bool BST::search(Node* node, int val) {
    if(node == nullptr){
        return false;
    }else if(node->data == val){
        return true;
    }else if(node->data > val){
        return search(node->left, val);
    }else
    {return search(node->right, val);}

}

void BST::in_order_traversal(Node* node) {
    if (node == nullptr){
        return;
    }else{
        in_order_traversal(node->left);
        std::cout << node->data << "  ";
        in_order_traversal(node->right);
    }
}

void BST::pre_order_traversal(Node* node) {
    if(node == nullptr)
        {return;}
    else{
        std::cout << node->data << "  ";
        pre_order_traversal(node->left);
        pre_order_traversal(node->right);
    }
}

void BST::post_order_traversal(Node* node) {
    if(node==nullptr){return;}
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
    std::cout << node->data << "  ";
}

Node* BST::delete_node(Node* node, int val) {
    return node;
}

Node* BST::find_min(Node* node) {
    return node;
}

int BST::calculate_depth(Node* node) {
    return 0;
}

void BST::print_tree(Node* node, int space) {
    if (node == nullptr) {
        return;
    }
    space += 5;
    print_tree(node->right, space);
    std::cout << std::endl;
    for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << " /"<< std::setw(2)<< " " << "Right: " << std::setw(14) << node->right << " |" << std::endl;
    for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << "|" << std::setw(3) << node->data << " at " << std::setw(17) << node << " |" << std::endl;
     for (int i = 5; i < space; i++) {
        std::cout << " ";
    }
    std::cout << " \\"<< std::setw(2)<< " " << "Left : " << std::setw(14) << node->left << " |" << std::endl;
    print_tree(node->left, space);
}
