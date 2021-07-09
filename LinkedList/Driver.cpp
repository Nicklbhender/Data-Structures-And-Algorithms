/*
 * Name: Nick Bhend
 * Version: 1.1
 * Date Last Modified: 7/9/2021
 * Description: Driver for LinkedList class. Contains main method, which contains some basic examples of the functions
 * of the LinkedList class.
 */

#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> numList;
    LinkedList<char> charList;
    LinkedList<string> strList;

    for(int i = 0; i < 5; i++) {
        numList.insert(i + 1);
    }

    charList.insert('a');
    charList.insert('b');
    charList.insert('c');
    charList.insert('d');
    charList.insert('e');

    strList.insert("Hello");
    strList.insert("World!");

    cout << "Number List: " << endl;
    numList.display();
    cout << endl;

    cout << "Char List: " << endl;
    charList.display();
    cout << endl;

    cout << "String List: " << endl;
    strList.display();
    cout << endl;

    cout << "Reversed Number List: " << endl;
    numList.reverse();
    numList.display();

    return 0;
}
