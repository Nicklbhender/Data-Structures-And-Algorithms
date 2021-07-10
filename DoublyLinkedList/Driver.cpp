#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList<int> numList;

    for(int i = 0; i < 5; i++) {
        numList.insert(i + 1);
    }

    numList.display();
    return 0;
}
