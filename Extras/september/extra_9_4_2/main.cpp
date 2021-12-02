#include<iostream>
#include "dll.h"

using namespace std;

int main()
{

    dll dllist;

    int randVal;

    // dllist.rmAtFront();
    // dllist.rmAtEnd();
    dllist.rmAtIndex(8);
    dllist.rmByValue(23);

    for(int i = 0; i < 5; i++) {
        // randVal = rand() % 10;
        dllist.insertAtFront(i);
        // dllist.insertAtEnd(i);
    }

    dllist.insertAtIndex(100, 3);
    dllist.rmByValue(233);

    dllist.printDLL();
    dllist.reversePrintDll();
    dllist.getHead();
    dllist.getTail();

    // dllist.rmAtIndex(3);
    dllist.rmByValue(4);
    dllist.rmByValue(0);

    dllist.rmAtFront();
    dllist.rmAtEnd();
    dllist.printDLL();
    dllist.reversePrintDll();

    dllist.getHead();
    dllist.getTail();


    return 0;
}