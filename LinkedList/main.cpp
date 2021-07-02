#include <iostream>
#include "LinkedList.h"
using namespace std;

int main() {
    LinkedList<int> numList;

    numList.insert(1);
    numList.insert(2);
    numList.insert(3);
    numList.insert(4);
    numList.insert(5);

    numList.remove(4);


    numList.display();

    return 0;
}
