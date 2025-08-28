#include <iostream>
#include "doubly_linked_list.hpp"

bool DoublyLinkedList::push_back(int v) {

    if (is_empty()) {
        return push_front(v);
    }
    // tail is null if list is empty
    DLLNode* newNode = new DLLNode(v);
    tail->next = newNode;
    newNode->prev = tail; // allows for tranversal backwards
    tail = newNode;
    return true;
    
}

bool DoublyLinkedList::push_front(int v) {

    // pointer update for the front
    DLLNode* newNode = new DLLNode(v, head);
    if(head){
        head->prev = newNode; 
    }else{
        tail = newNode; // if empty, tail must match head
    }
    head = newNode;
    return true;
}

bool DoublyLinkedList::insert(int v, int i) {

    if(i > size() || i < 0){
        return false;
    } 
    else if(i == 0){
        return push_front(v);
    }
    else if(i == size()){
        return push_back(v);
    }
    DLLNode* iter = head;
    for(int count = 1; count < i; count++){
        iter = iter->next;
    }
    DLLNode* newNode = new DLLNode(v, iter->next);
    newNode->prev = iter;
    iter->next->prev = newNode; // points to the previous pointer of the next node, inserting newNode as node
    iter->next = newNode;
    return true;
    
}

int DoublyLinkedList::at(int i) {

    if (i < 0 || i >= size()) {
        throw std::out_of_range("Invalid Index for List");
    }
    else {
        DLLNode* iter = head;
        for (int count = 0; count < i; count++) {
            iter = iter->next;
        }
        return iter->value;
    }
}

int DoublyLinkedList::search(int v) {

    // searches back to front
    DLLNode* iter = head;
    int count = 0;
    while(iter){
        if(iter->value == v){
            return count;
        }
        iter = iter->next;
        count++;
    }
    return -1;
}

bool DoublyLinkedList::is_empty(){

    return head == nullptr;
}

int DoublyLinkedList::size() {

    int count = 0;
    DLLNode* iter = head;
    while(iter){
        count++;
        iter = iter->next;
    }
    return count;
}

bool DoublyLinkedList::remove(int i) {

    // Deleting is trickier because need to fix both next and prev
    if (i < 0 || i >= size()) {
        return false;
    }
    if (i == 0) {
        DLLNode* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr; // Fix the new head's prev
        } else {
            tail = nullptr; // If list empties out, tail is null too
        }
        delete temp;
        return true;
    }
    DLLNode* iter = head;
    for (int count = 0; count < i - 1; count++) {
        iter = iter->next;
    }
    DLLNode* temp = iter->next;
    iter->next = temp->next;
    if (temp->next) {
        temp->next->prev = iter; // Fix the next node's prev pointer
    } else {
        tail = iter; // If removed last node, update tail
    }
    delete temp;
    return true;
}



bool DoublyLinkedList::remove_value(int v) {

    // finding specific value
    if(is_empty()){
        return false;
    }
    if(head->value == v){
        DLLNode* temp = head;
        head = head->next;
        if(head){
            head->prev = nullptr; // Fix new head's prev
        }else{
            tail = nullptr;
        }
        delete temp;
        return true;
    }
    DLLNode* iter = head;
    while(iter->next && iter->next->value != v){
        iter = iter->next;
    }
    if(iter->next){
        DLLNode* temp = iter->next;
        iter->next = temp->next;
        if(temp->next){
            temp->next->prev = iter; // Keep pointers incheck
        }else {
            tail = iter; // If last node is removed, fix tail
        }
        delete temp;
        return true;
    }
    return false;

}

void DoublyLinkedList::print() {

    DLLNode* iter = head;
    while (iter != nullptr) {
        std::cout << iter-> value << " ";
        iter = iter->next;
    } 
    std::cout << std::endl;
}

void DoublyLinkedList::print_reverse(){
    
    DLLNode* iter = tail; // same as print() but starts at tail using prev to go back
    while(iter){
        std::cout << iter->value << " ";
        iter = iter->prev;
    }
    std::cout << std::endl;
}