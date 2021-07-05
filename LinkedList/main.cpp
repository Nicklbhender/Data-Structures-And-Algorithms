#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> numList;

    numList.insertAt(0, 1);
    numList.insertAt(1, 2);
    numList.insertAt(2, 3);
    numList.insertAt(3, 4);
    numList.insert(5);

    numList.display();

    return 0;
}
