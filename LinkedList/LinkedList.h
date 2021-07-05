//
// Created by nickb on 6/29/2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include "iostream"
#include "stdexcept"
using namespace std;

template<typename T>

class LinkedList {

private:
    struct Node {
        T data;
        Node* next = nullptr;
    };

    Node* head = nullptr;

public:

    ~LinkedList();

    void insert(T pData);

    void insertAt(int idx, T pData);

    void remove(T pData);

    void removeAt(int idx);

    void display();

    int sizeOf();

};

template<typename T>
LinkedList<T>::~LinkedList() {
    Node* trav = head;
    Node* trail = trav;
    while(trav != nullptr) {
        trav = trav->next;
        delete(trail);
        trail = trav;
    }
}

template<typename T>
void LinkedList<T>::insert(T pData) {


    // If head is null (no data present in list), initialize head with parameter data
    if(head == nullptr) {
        head = new Node();
        head->data = pData;
        // If head isn't null (populated list), insert at end of current list
    } else {
        Node* trav = head;

        while(trav->next != nullptr) {
            trav = trav->next;
        }
        trav->next = new Node();
        trav->next->data = pData;
    }

}

template<typename T>
void LinkedList<T>::insertAt(int idx, T pData) {
    if(idx < 0 || idx > sizeOf()) {
        cout << "Insertion Error: Index Out of Bounds" << endl;
    } else {
        if(idx == 0) {
            if(head == nullptr) {
                head = new Node();
                head->data = pData;
            } else {
                Node* nNode = new Node();
                nNode->data = pData;
                nNode->next = head;
                head = nNode;
            }
        } else {
            Node *trav = head;
            Node *trail = trav;

            while(idx > 0) {
                trail = trav;
                trav = trav->next;
                idx--;
            }

            Node* nNode = new Node();
            nNode->data = pData;

            trail->next = nNode;
            nNode->next = trav;
        }
    }
}

template<typename T>
void LinkedList<T>::remove(T pData) {
    if(head == nullptr) {
        cout << "List is empty" << endl;
    } else if(head->data == pData) {
        head = head->next;
    } else {
        Node* trav = head;
        Node* trail = trav;

        while(trav->data != pData) {
            trail = trav;
            trav = trav->next;
            if(trav == nullptr) {
                break;
            }
        }

        if(trav == nullptr) {
            cout << "Remove Error: Item not found in list" << endl;
        } else {
            trail->next = trav->next;
            delete(trav);
        }
    }
}

template<typename T>
void LinkedList<T>::removeAt(int idx) {
    if(idx < 0 || idx >= sizeOf()) {
        cout << "Remove Error: Index Out of Bounds" << endl;
    } else if(head == nullptr) {
        cout << "List is empty" << endl;
    } else if(idx == 0) {
        head = head->next;
    } else {
        Node* trav = head;
        Node* trail = trav;

        while (idx > 0) {
            trail = trav;
            trav = trav->next;
            idx--;

        }
        trail->next = trav->next;
        delete(trav);
    }
}

template<typename T>
void LinkedList<T>::display() {
    if(head == nullptr) {
        cout << "Empty List" << endl;
    } else {
        Node* trav = head;
        while(trav != nullptr) {
            cout << trav->data << endl;
            trav = trav->next;
        }
    }
}

template<typename T>
int LinkedList<T>::sizeOf() {
    Node* trav = head;
    int size = 0;
    while(trav != nullptr) {
        trav = trav->next;
        size++;
    }
    return size;
}


#endif //LINKEDLIST_LINKEDLIST_H