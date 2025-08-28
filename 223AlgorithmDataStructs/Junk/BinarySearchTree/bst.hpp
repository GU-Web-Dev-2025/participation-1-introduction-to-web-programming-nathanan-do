#ifndef BST_HPP
#define BST_HPP

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val);
    ~Node();
};

class BST {
public:
    BST();
    ~BST();
    void insert(int val);
    bool search(int val);
    void in_order_traversal();
    void pre_order_traversal();
    void post_order_traversal();
    void delete_node(int val);
    int calculate_depth();
    void print_tree();
    Node* get_root(){ return root; }
    void search_test(){};

private:
    Node* root;
    void insert(Node*& node, int val);
    bool search(Node* node, int val);
    void in_order_traversal(Node* node);
    void pre_order_traversal(Node* node);
    void post_order_traversal(Node* node);
    Node* delete_node(Node* node, int val);
    Node* find_min(Node* node);
    int calculate_depth(Node* node);
    void print_tree(Node* node, int space);
};

#endif