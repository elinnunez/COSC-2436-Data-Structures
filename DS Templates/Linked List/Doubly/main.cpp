#include <iostream>
#include <string>
#include "doubly.h"

using namespace std;

int main()
{
    Doubly<int> dlist;

    for(int i = 5; i >= 0; i--) {
        dlist.addatEnd(i);
    }

    dlist.display();

    dlist.addatIndex(32, 15);
    dlist.addatIndex(24, 6);
    dlist.addatIndex(12, 3);
    // dlist.addatIndex(11, 0);
    // dlist.addatIndex(33, -2);
    // dlist.addatIndex(55, 10);

    dlist.display();

    std::cout << dlist.getSize() << std::endl;

    dlist.displayReverse();

    return 0;
}