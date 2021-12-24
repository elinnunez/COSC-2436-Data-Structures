#include <iostream>
#include <string>
#include "doubly.h"

using namespace std;

int main()
{
    Doubly<int> dlist;

    for(int i = 5; i >= 0; i--) {
        dlist.addatBeg(i);
    }

    dlist.display();

    std::cout << dlist.getSize() << std::endl;

    return 0;
}