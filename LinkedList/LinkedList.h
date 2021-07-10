/*
 * Name: Nick Bhend
 * Version: 1.1
 * Date Last Modified: 7/9/2021
 * Description: The LinkedList class allows for the creation of LinkedList objects, which can be added to, removed from,
 * reversed, and displayed. LinkedList objects can also report their size to the user. LinkedList objects contain a Node
 * struct, which defines Nodes that make up each LinkedList object, as well as a Node pointer head, the start of each
 * individual list.
 */

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "iostream"

using namespace std;

template<typename T>

class LinkedList {

private:

    /*
     * Purpose: Defines LinkedList Nodes.
     * Description: Node struct for building Linked Lists. Contains T (template) data and a Node pointer next, which
     * points to the address of the next Node in the list.
     */
    struct Node {
        T data;
        Node* next = nullptr;
    };

    // List head. Initialized to nullptr (empty list).
    Node* head = nullptr;

public:

    // Destructor
    ~LinkedList();

    // Primary Insertion Method (Inserts at Back of List)
    void insert(T pData);

    // Secondary Insertion Method (Inserts at User-Specified Position)
    void insertAt(int idx, T pData);

    // Primary Removal Method (Removes User-Specified Item)
    void remove(T pData);

    // Secondary Removal Method (Removes Item at User-Specified Index)
    void removeAt(int idx);

    // Display Method (Prints Contents of a List)
    void display();

    // Size Method (Returns Size of a List)
    int sizeOf();

    // Reverse Method (Reverses the Order of a List)
    void reverse();

};

/*
 * Purpose: Destructor for the LinkedList class.
 * Description: Destructor for the LinkedList class. Deallocates memory used by a linked list.
 */
template<typename T>
LinkedList<T>::~LinkedList() {
    // Initialize traversal and trailing Nodes
    Node* trav = head;
    Node* trail = trav;
    // While traversal Node isn't null (end of list not yet reached)...
    while(trav != nullptr) {
        // Iterate traversal node
        trav = trav->next;
        // Delete trailing node
        delete(trail);
        // Assign trailing node to traversal node
        trail = trav;
    }
}

/*
 * Purpose: Inserts an item at the back of a list.
 * Description: Insertion method for the LinkedList class. Inserts a node at the back of a linked list, taking a
 * parameter pData, which represents a data value a user wishes to add to a given list.
 */
template<typename T>
void LinkedList<T>::insert(T pData) {
    // If head is null (empty list), initialize head with parameter data
    if(head == nullptr) {
        head = new Node();
        head->data = pData;
    // If head isn't null (populated list), insert at end of current list
    } else {
        // Create traversal Node and set to head
        Node* trav = head;
        // While traversal Node's next isn't null (end of list not yet reached), iterate to next node in the list
        while(trav->next != nullptr) {
            trav = trav->next;
        }
        // Upon reaching the end of the list, initialize traversal Node's next
        trav->next = new Node();
        // Set traversal Node's next's data to pData
        trav->next->data = pData;
    }

}

/*
 * Purpose: Inserts an item at a user-specified position within a list.
 * Description: Secondary insertion method for the LinkedList class. Takes parameters idx, which represents the position
 * within a list that a user wants to insert an item into, and pData, which represents a data value a user wishes to add
 * to a given list.
 */
template<typename T>
void LinkedList<T>::insertAt(int idx, T pData) {
    // If idx is less than 0 or greater than the size of the current list, return out of bounds error
    if(idx < 0 || idx > sizeOf()) {
        cout << "Insertion Error: Index Out of Bounds" << endl;
    } else {
        // If inserting at the start of the list...
        if(idx == 0) {
            // If head is null (empty list), initialize head with parameter data
            if(head == nullptr) {
                head = new Node();
                head->data = pData;
            // If head isn't null (populated list)...
            } else {
                // Initialize new Node
                Node* nNode = new Node();
                // Set nNode's data to parameter pData
                nNode->data = pData;
                // Set nNode's next to head
                nNode->next = head;
                // Set head to nNode
                head = nNode;
            }
        // If inserting in the middle/end of the list...
        } else {
            // Initialize traversal and trailing Nodes
            Node *trav = head;
            Node *trail = trav;
            // While idx is greater than 0 (position within list not yet reached)...
            while(idx > 0) {
                // Set trailing Node to traversal Node
                trail = trav;
                // Iterate traversal Node
                trav = trav->next;
                // Decrement idx
                idx--;
            }
            // Upon reaching index position, initialize a new Node and set its data to pData (parameter data)
            Node* nNode = new Node();
            nNode->data = pData;
            // Set new Node to trailing Node's next
            trail->next = nNode;
            // Set new Node's next to traversal Node
            nNode->next = trav;
        }
    }
}

/*
 * Purpose: Removes a user-specified item from a list.
 * Description: Removal method for the LinkedList class. Takes a parameter pData, which specifies the data a user wants
 * to remove from a list.
 */
template<typename T>
void LinkedList<T>::remove(T pData) {
    // If head is null (empty list), return 'List is empty' message
    if(head == nullptr) {
        cout << "List is empty" << endl;
    // If head's data is equal to pData (head is removal target), set head to head's next
    } else if(head->data == pData) {
        head = head->next;
    // Otherwise (removing from middle/end of list)...
    } else {
        // Initialize traversal and trailing Nodes
        Node* trav = head;
        Node* trail = trav;
        // While trav's data doesn't match pData...
        while(trav->data != pData) {
            // Update trail's value to trav's value
            trail = trav;
            // Iterate trav
            trav = trav->next;
            // If trav is null (end of list reached), break
            if(trav == nullptr) {
                break;
            }
        }
        // If trav is null (item was not found in list), return not found message
        if(trav == nullptr) {
            cout << "Remove Error: Item not found in list" << endl;
        // If item was found in list...
        } else {
            // Set trailing Node's next to trav's next and delete trav
            trail->next = trav->next;
            delete(trav);
        }
    }
}

/*
 * Purpose: Removes an item at a user-specified position within a list.
 * Description: Secondary removal method for the LinkedList class. Takes a parameter idx, which represents the position
 * of an item within a list that a user wants remove.
 */
template<typename T>
void LinkedList<T>::removeAt(int idx) {
    // If idx is less than 0 or greater than the size of the current list, return out of bounds error
    if(idx < 0 || idx >= sizeOf()) {
        cout << "Remove Error: Index Out of Bounds" << endl;
    // If list is empty, return 'List is empty' message
    } else if(head == nullptr) {
        cout << "List is empty" << endl;
    // If removing from the start of the list, set head to its next pointer
    } else if(idx == 0) {
        head = head->next;
    // If removing from the middle/end of the list...
    } else {
        // Initialize traversal and trailing Nodes
        Node* trav = head;
        Node* trail = trav;
        // While idx is greater than 0 (position within list not yet reached)...
        while (idx > 0) {
            // Set trailing Node to traversal Node
            trail = trav;
            // Iterate traversal Node
            trav = trav->next;
            // Decrement idx
            idx--;
        }
        // Set trailing Node's next to trav's next and delete trav
        trail->next = trav->next;
        delete(trav);
    }
}

/*
 * Purpose: Displays the items contained within a list to the screen.
 * Description: Display method for the LinkedList class. Prints items contained within a list to the screen. If a list
 * is empty, 'Empty List' will be printed to the screen.
 */
template<typename T>
void LinkedList<T>::display() {
    // If head is null (empty list), print 'Empty List'
    if(head == nullptr) {
        cout << "Empty List" << endl;
    // If head isn't null (populated list)...
    } else {
        // Initialize traversal Node
        Node* trav = head;
        // While traversal Node isn't null (end of list not yet reached)...
        while(trav != nullptr) {
            // Print traversal Node data
            cout << trav->data << endl;
            // Iterate to next Node
            trav = trav->next;
        }
    }
}

/*
 * Purpose: Returns the size of a list.
 * Description: Secondary removal method for the LinkedList class. Takes a parameter idx, which represents the position
 * of an item within a list that a user wants remove.
 */
template<typename T>
int LinkedList<T>::sizeOf() {
    // Initialize traversal Node
    Node* trav = head;
    // Initialize size variable with starting value 0
    int size = 0;
    // While traversal Node isn't null (end of list not yet reached)...
    while(trav != nullptr) {
        // Iterate to next Node
        trav = trav->next;
        // Increment size
        size++;
    }
    // Return size
    return size;
}

/*
 * Purpose: Reverses the Node-order of a list.
 * Description: Reverses the Node-order of a list by reversing the link pointers between each Node within a list.
 */
template<typename T>
void LinkedList<T>::reverse() {
    // Initialize traversal Node
    Node* trav = head;
    // Initialize trailing Node to hold Node previous to traversal Node
    Node* trail = nullptr;
    // While traversal Node isn't null (end of list not yet reached)...
    while(trav != nullptr) {
        // Initialize next Node to hold next Node to iterate to
        Node* next = trav->next;
        // Reverse trav's next pointer by pointing it to trailing Node
        trav->next = trail;
        // Iterate trailing Node to trav's current Node
        trail = trav;
        // Iterate trav to next Node in the list
        trav = next;
    }
    // Set head to trailing Node (new head of the reversed list)
    head = trail;
}

#endif //LINKEDLIST_LINKEDLIST_H