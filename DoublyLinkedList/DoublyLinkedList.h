//
// Created by nickb on 7/9/2021.
//

#ifndef DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H

#include "iostream"

using namespace std;

template<typename T>

class DoublyLinkedList {

private:

    /*
     * Purpose: Defines DoublyLinkedList Nodes.
     * Description: Node struct for building Linked Lists. Contains T (template) data and a Node pointer next, which
     * points to the address of the next Node in the list.
     */
    struct Node {
        T data;
        Node* prev = nullptr;
        Node* next = nullptr;
    };

    // List head. Initialized to nullptr (empty list).
    Node* head = nullptr;

public:

    // Destructor
    ~DoublyLinkedList();

    void insert(T pData);

    void display();
};

/*
 * Purpose: Destructor for the LinkedList class.
 * Description: Destructor for the LinkedList class. Deallocates memory used by a linked list.
 */
template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
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

template<typename T>
void DoublyLinkedList<T>::insert(T pData) {

    if(head == nullptr) {
        head = new Node();
        head->data = pData;
    } else {
        Node* trav = head;
        while(trav->next != nullptr) {
            trav = trav->next;

        }

        trav->next = new Node();
        trav->next->prev = trav;
        trav->next->data = pData;
    }
}

template<typename T>
void DoublyLinkedList<T>::display() {
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


#endif //DOUBLYLINKEDLIST_DOUBLYLINKEDLIST_H
