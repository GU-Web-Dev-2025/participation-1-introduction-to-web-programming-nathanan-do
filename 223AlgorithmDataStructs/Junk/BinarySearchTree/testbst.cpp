#include <iostream>
#include <cassert>
#include "bst.hpp"

using namespace std;


bool test_insert(){
    //setup
    BST b;

    //execution
    b.insert(10); //empty case
    b.insert(15);
    b.insert(4);
    b.insert(2);
    b.insert(12);

    //validation
    Node* root = b.get_root();
    assert(root->data == 10); // incorrect root value
    cout << "10 passed" << endl;
    assert(root->right->data == 15);
    cout << "15 passed" << endl;
    assert(root->left->data == 4);
    cout << "4 passed" << endl;
    assert(root->left->left->data == 2);
    assert(root->right->left->data == 12);
    assert(root->right->right->right == nullptr);
    // assert(root != nullptr);

    //cleanup
    return true;


}
bool search_test(){
    // set up
    BST b;

    // execution
    b.insert(10);
    b.insert(5);
    b.insert(7);
    b.insert(12);
    b.insert(15);
    b.insert(11);
    b.insert(4);
    b.insert(16);

    // validation
    assert(!b.search(6));
    
    // cleanup
    return true;
}

bool in_order_print(){
    BST b;

    b.insert(10);
    b.insert(5);
    b.insert(7);
    b.insert(12);
    b.insert(15);
    b.insert(11);
    b.insert(4);
    b.insert(16);

    b.in_order_traversal();

    cout << "10 5 7";

    return true;
}

bool pre_order_print(){
    BST b;

    
    b.insert(10);
    b.insert(5);
    b.insert(7);
    b.insert(12);
    b.insert(15);
    b.insert(11);
    b.insert(4);
    b.insert(16);

    b.pre_order_traversal();

    cout << "10 5 4";

    return true;
}


int main(){
    cout << "Insert Test: " << (test_insert() ? "Passed" : "Failed") << endl;
    pre_order_print();
}