#include <iostream>
#include "list.h"

using namespace std;

int main()
{

    list collection;

    for(int i = 0; i < 10; i++) {
        collection.addAtEnd(i);
    }

    collection.getHead();
    collection.getTail();

  
    // collection.printEven();
    // collection.printOdd();
    collection.printList();

    // collection.recPrintEvenPub();
    // collection.recPrintOddPub();
    collection.addAtEnd(10);

    // collection.deleteOdd();
    // collection.deleteEven();
    // collection.deleteOdd();
    // collection.deleteEven();

    // collection.addAtEnd(10);

    // collection.printList();
    // collection.recPrintEvenPub();
    // collection.recPrintOddPub();

    // collection.printEven();
    // collection.printOdd();

    collection.printList();

    collection.getHead();
    collection.getTail();

    return 0;
}