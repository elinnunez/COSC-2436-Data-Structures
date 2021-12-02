#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

int main()
{
    linked<int> list;

    for(int i = 0; i < 5; i++) {
        list.addatEnd(i);
    }

    cout <<  "Head: " << list.getHead() << endl;
    cout << "Tail: " << list.getTail() << endl;
    cout << "Size: " << list.getSize() << endl;
    list.removeBeg();
    list.removeEnd();
    cout << "New Head: " << list.getHead() << endl;
    cout << "New Tail: " << list.getTail() << endl;
    cout << "New Size: " << list.getSize() << endl;
    list.display();

    return 0;
}