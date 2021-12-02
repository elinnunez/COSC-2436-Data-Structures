#include<iostream>
#include "lht.h"

using namespace std;

int main()
{
    lht list;

    char arr[5] = {'a','b','c','d','e'};
    char key;

    for(int i = 0; i < 5; i++) {
        list.insertAtEnd(arr[i]);
    }

    // list.insertAtBeg('h');
    // list.insertAtEnd('k');
    // list.insertAtChar('b', 'j');
    // list.insertAtIndex(3,'y');
    // list.printList();
    // list.deleteAtBeg(key);
    // list.deleteAtEnd();
    // list.deleteAtChar('d');
    // list.printList();
    // list.deleteAtIndex(4);
    // list.printList();
    return 0;
}