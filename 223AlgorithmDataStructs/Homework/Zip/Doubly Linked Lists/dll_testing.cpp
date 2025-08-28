/*
    * For educational purposes, ChatGPT was used to create this testing environment *
*/

#include <cassert>
#include <iostream>
#include <stdexcept>
#include "doubly_linked_list.hpp"

bool DLL_test_push_front() {
    DoublyLinkedList dll;
    bool return_test_1 = dll.push_front(1);
    bool return_test_2 = dll.push_front(2);
    assert(return_test_1);
    assert(return_test_2);
    assert(dll.at(0) == 2);
    assert(dll.at(1) == 1);
    std::cout << "Push Front: Passed\n";
    return true;
}

bool DLL_test_push_back() {
    DoublyLinkedList dll;
    bool return_test_1 = dll.push_back(1);
    bool return_test_2 = dll.push_back(2);
    assert(return_test_1);
    assert(return_test_2);
    assert(dll.at(0) == 1);
    assert(dll.at(1) == 2);
    std::cout << "Push Back: Passed\n";
    return true;
}

bool DLL_test_is_empty() {
    DoublyLinkedList dll;
    assert(dll.is_empty());
    dll.push_front(1);
    assert(!dll.is_empty());
    std::cout << "Is Empty: Passed\n";
    return true;
}

bool DLL_test_size() {
    DoublyLinkedList dll;
    assert(dll.size() == 0);
    dll.push_front(1);
    assert(dll.size() == 1);
    dll.push_front(2);
    assert(dll.size() == 2);
    std::cout << "Size: Passed\n";
    return true;
}

bool DLL_test_insert() {
    DoublyLinkedList dll;
    assert(dll.insert(1, 0));
    assert(dll.insert(2, 1));
    assert(dll.insert(3, 1));
    assert(dll.at(0) == 1);
    assert(dll.at(1) == 3);
    assert(dll.at(2) == 2);
    std::cout << "Insert: Passed\n";
    return true;
}

bool DLL_test_at() {
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    assert(dll.at(0) == 1);
    assert(dll.at(1) == 2);
    assert(dll.at(2) == 3);
    std::cout << "At: Passed\n";
    return true;
}

bool DLL_test_search() {
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    assert(dll.search(1) == 0);
    assert(dll.search(2) == 1);
    assert(dll.search(3) == 2);
    assert(dll.search(4) == -1);
    std::cout << "Search: Passed\n";
    return true;
}

bool DLL_test_remove() {
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    assert(dll.remove(1));
    assert(dll.size() == 2);
    assert(dll.at(1) == 3);
    std::cout << "Remove: Passed\n";
    return true;
}

bool DLL_test_remove_value() {
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    assert(dll.remove_value(2));
    assert(dll.size() == 2);
    assert(dll.at(1) == 3);
    std::cout << "Remove Value: Passed\n";
    return true;
}

bool DLL_test_print() {
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.print();
    std::cout << "Print: Completed\n";
    return true;
}

bool DLL_test_print_reverse() {
    DoublyLinkedList dll;
    dll.push_back(1);
    dll.push_back(2);
    dll.push_back(3);
    dll.print_reverse();
    std::cout << "Print Reverse: Completed\n";
    return true;
}

int main() {
    std::cout << "Starting Doubly Linked List Tests" << std::endl;
    DLL_test_push_front();
    DLL_test_push_back();
    DLL_test_is_empty();
    DLL_test_size();
    DLL_test_insert();
    DLL_test_at();
    DLL_test_search();
    DLL_test_remove();
    DLL_test_remove_value();
    DLL_test_print();
    DLL_test_print_reverse();
    std::cout << "All tests completed!" << std::endl;
    return 0;
}