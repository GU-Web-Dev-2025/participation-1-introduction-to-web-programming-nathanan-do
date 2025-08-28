/*
    *Name:              Nathan Doan
    *Last Modified:     5 Febrary 2025
    *Class:             223-01 Algorithm & Abstract Data
    *Professor:         Prof. Johnson
*/

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class DLLNode {
    
    public:
        
        int value;
        DLLNode* next;
        DLLNode* prev;

        // Constructors
        DLLNode() : value(0), next(nullptr), prev(nullptr){}
        DLLNode(int v) : value(v), next(nullptr), prev(nullptr){}
        DLLNode(DLLNode* n) : value(0), next(n), prev(nullptr){}
        DLLNode(int v, DLLNode* n) : value(v), next(n), prev(nullptr){}
        
        // Destructor
       ~DLLNode(){
            
            next = nullptr;
            prev = nullptr;
       }
};

class DoublyLinkedList {
    
    private: 

        DLLNode* head;
        DLLNode* tail;

    public:

        // Constructors
        DoublyLinkedList() : head(nullptr), tail(nullptr){}
        
        // Destructor - prevents recursive Deletion of nodes
        ~DoublyLinkedList(){ 
            while(head){
                DLLNode* temp = head;
                head = head->next;
                delete temp;
            }
        }

        bool push_back(int v);
        bool push_front(int v);
        bool insert(int v, int i);
        int at(int i);
        int search(int v);
        bool is_empty();
        int size();
        bool remove(int i);
        bool remove_value(int v);
        void print();
        void print_reverse(); // added function
        DLLNode* get_head() { return head; }
        DLLNode* get_tail() { return tail; } // added function

};

#endif