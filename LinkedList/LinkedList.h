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

};

template<typename T>
LinkedList<T>::~LinkedList() {

}

template<typename T>
void LinkedList<T>::insert(T pData) {


    // If head is null (no data present in list), initialize head with parameter data
    if(head == nullptr) {
        head = new Node;
        head->data = pData;
        // If head isn't null (populated list), insert at end of current list
    } else {
        Node* trav = head;

        while(trav->next != nullptr) {
            trav = trav->next;
        }
        trav->next = new Node;
        trav->next->data = pData;
    }

}

template<typename T>
void LinkedList<T>::insertAt(int idx, T pData) {
    if(idx < 0) {
        cout << "Insertion Error: Index cannot be less than 0" << endl;
    } else {
        Node *trav = head;
        while (idx > 0 && trav->next != nullptr) {
            trav = trav->next;
            idx--;
        }

        if (trav->next == nullptr) {
            trav->next = new Node;
            trav->next->data = pData;
        } else {
            Node *temp = new Node;

            temp->data = trav->data;
            temp->next = trav->next;

            trav->data = pData;
            trav->next = temp;
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
            trav = nullptr;
        }
    }
}

template<typename T>
void LinkedList<T>::removeAt(int idx) {
    if(idx < 0) {
        cout << "Remove Error: Index cannot be less than 0" << endl;
    } else if(head == nullptr) {
        cout << "List is empty" << endl;
    } else if(idx == 0) {
        head = head->next;
    } else {
        Node* trav = head;
        Node* trail = trav;

        while (idx > 0 && trav != nullptr) {
            trail = trav;
            trav = trav->next;
            idx--;
            if(trav == nullptr) {
                break;
            }
        }

        if(trav == nullptr) {
            cout << "Remove Error: Idx out of range" << endl;
        } else {
            trail->next = trav->next;
            trav = nullptr;
        }
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




#endif //LINKEDLIST_LINKEDLIST_H