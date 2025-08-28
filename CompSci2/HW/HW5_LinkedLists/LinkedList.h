#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include<iostream>

class LinkedList{
    public:

        /*
        *   Name:           Default Constructor
        *   Parameters:     None
        *   Return:         None
        *   Description:    Creates a LinkedList object with no Nodes.
        *                   The head pointer should be nullptr.
        */
        LinkedList();


        /*
        *   Name:           Parameterized Constructor
        *   Parameters:     int value - the value to be added to the LinkedList.
        *   Return:         None
        *   Description:    Creates a LinkedList object with one Node.
        *                   The head pointer should point to a new Node that contains
        *                   the value passed in as a parameter.
        */
        LinkedList(int value);

        /*
        *   Name:           Destructor
        *   Parameters:     None
        *   Return:         None
        *   Description:    Deletes the Linked List. Frees up all heap memory.
        */
        ~LinkedList();

        /*
        *   Name:           PrintList
        *   Parameters:     None
        *   Return:         std::string - a string representing the list
        *   Description:    Creates and returns a string that represents
        *                   the entire linked list from start to end.
        *                   The returned string should not include a \n char
        *                   at the end
        *                   Format should look like this:
        *                       For a list with no elements:
        *                           nullptr
        *                       For a list with one element whose value is 13:
        *                           13->nullptr
        *                       For a list containing the numbers 3, 4, 5, 6:
        *                           3->4->5->6->nullptr
        *                   use the value of the node if present, otherwise use
        *                   the word nullptr. Seperate values with an arrow ->
        */
        std::string printList();

        /*
        *   Name:           addToEnd
        *   Parameters:     int value - the value to add to the end of the list
        *   Return:         None
        *   Description:    Adds the integer value to the end of the Linked List.
        */
        void addToEnd(int value);
        
        /*
        *   Name:           removeValue
        *   Parameters:     int value - the value to remove from the list
        *   Return:         None
        *   Description:    Searches the Linked List for the value, then removes
        *                   that Node from the list.
        *                   If multiple occurances of the same value exist in the
        *                   list, remove only the first occurance.
        *                   If the value doesn't exist in the list, do nothing.
        */
        void removeValue(int value);

        /*
        *   Name:           contains
        *   Parameters:     int value - the value we are searching for
        *   Return:         bool - return true if the value is found in the list.
        *                          return false if the value is not found in the list.
        *   Description:    Search the Linked List for the value, return true or false
        *                   if the list contains the value or not.
        */
        bool contains(int value);

        /*
        *   Name:           insertValue
        *   Parameters:     int value - the value to be inserted into the list
        *                   int index - the location to insert the value
        *   Return:         None
        *   Description:    Inserts a new node containing the value into the list
        *                   at the specified index. Indexing starts at 0.
        *                   e.g. If the list looks like: 0->1->2->3->4->nullptr
        *                       inserting the value 99 at index 3 would change 
        *                       the list to: 0->1->2->99->3->4->nullptr
        */
        void insertValue(int value, int index);
        
    private:

        // head is the beginning node of the linked list
        Node * head;
};

#endif