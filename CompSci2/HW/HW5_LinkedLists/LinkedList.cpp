#include "LinkedList.h"

/*
        *   Name:           Default Constructor
        *   Parameters:     None
        *   Return:         None
        *   Description:    Creates a LinkedList object with no Nodes.
        *                   The head pointer should be nullptr.
        */
LinkedList::LinkedList(){
    
    head = nullptr;

};


        /*
        *   Name:           Parameterized Constructor
        *   Parameters:     int value - the value to be added to the LinkedList.
        *   Return:         None
        *   Description:    Creates a LinkedList object with one Node.
        *                   The head pointer should point to a new Node that contains
        *                   the value passed in as a parameter.
        */
LinkedList::LinkedList(int value){

    Node* newNode = new Node; // Create new node with the given value
    newNode->value = value;
    newNode->next = nullptr; // new node is the only node, so next is nullptr
    head = newNode; // Set head pointer to new node

};

        /*
        *   Name:           Destructor
        *   Parameters:     None
        *   Return:         None
        *   Description:    Deletes the Linked List. Frees up all heap memory.
        */
LinkedList::~LinkedList(){

    Node* current = head; // Pointer to traverse the list and delete nodes
    while (current != nullptr) {
    
        Node* temp = current;
        current = current->next;
        delete temp;
    
    }

};

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
std::string LinkedList::printList(){
    std::string output;
    Node* current = head;
    if (!current){
        output = "nullptr";
    } else{
        while (current){
            output += std::to_string(current->value);
            if (current->next){
                output += "->";
            }
            current = current->next;
        }
        output += "->nullptr";
    }
    return output;
}

        /*
        *   Name:           addToEnd
        *   Parameters:     int value - the value to add to the end of the list
        *   Return:         None
        *   Description:    Adds the integer value to the end of the Linked List.
        */
void LinkedList::addToEnd(int value){
        
    Node* newNode = new Node; // Create new node
    newNode->value = value;
    newNode->next = nullptr; // New node will be the last node, so next is nullptr
 
    if (head == nullptr) {// If the list is empty, set head to the new node
        
        head = newNode;

    } else {

        Node* current = head;// Traverse to the end of the list
        while (current->next != nullptr){
        
            current = current->next;

        }

        current->next = newNode; // Link the last node to the new node

    }

};
        
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
void LinkedList::removeValue(int value){
    
    if (head == nullptr) { // If list is empty, do nothing

        return;

    }

    if (head->value == value) { // If value is at head, remove the head node

        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head; // Traverse the list to find the node before the one to be removed
    while (current->next != nullptr && current->next->value != value) {

        current = current->next;

    }

    if (current->next != nullptr) { // If the value is found, remove the node


        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;

    }

};

        /*
        *   Name:           contains
        *   Parameters:     int value - the value we are searching for
        *   Return:         bool - return true if the value is found in the list.
        *                          return false if the value is not found in the list.
        *   Description:    Search the Linked List for the value, return true or false
        *                   if the list contains the value or not.
        */
bool LinkedList::contains(int value){

    Node* current = head; // Starts from the head of the list
    while (current != nullptr) { // Traverse the list to search for the value

        if (current->value == value){

            return true; // Value found

        }

        current = current->next; // Move to the next node

    }
    
    return false; // Value not found

};

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
void LinkedList::insertValue(int value, int index){

    Node* newNode = new Node; // Create a new node with the given value
    newNode->value = value;
    newNode->next = nullptr;

    if (index == 0) { // If inserting at the head (index 0)

        newNode->next = head;
        head = newNode;
        return;

    }

    Node* current = head; // Traverse the list to find the position before the insertion point
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index - 1){
    
        current = current->next;
        currentIndex++;

    }

    if (current == nullptr) { // If current is nullptr, the index is out of bounds

        delete newNode; // Prevent memory leak
        return;

    }

    newNode->next = current->next; // Insert the new node
    current->next = newNode;

};

