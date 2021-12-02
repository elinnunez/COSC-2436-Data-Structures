#include <iostream>
#include "dastack.h"
#include "llstack.h"

using namespace std;

int main()
{
    stack<char> chbag(10);
    stack<int> intbag(10);

    Stack<char> chbag1;
    Stack<int> intbag1;


    char charr[] = {'e', 'l', 'i'};
    int size = sizeof(charr)/sizeof(charr[0]);

    for(int i = 0; i < size; i++) {
        chbag.push(charr[i]);
        chbag1.push(charr[i]);
    }

    for(int i = 0; i < 10; i++) {
        intbag.push(i);
        intbag1.push(i);
    }

    return 0;
}