#include<iostream>
#include "list.h"
#include <string>

using namespace std;

int main()
{

    // string sentence = "ILOVEDATASTRUCTURES";
                    //"IOEAATUTRS"
                    //IEAUR
                    //IAR
                    //IR
                    //I

    string sentence;

    cout << "Enter a string: ";
    cin >> sentence;
    
    link list;

    for(int i = 0; i < sentence.length(); i++) {
        list.addLast(sentence[i]);
    }

    int count = list.loopCount();

    cout << "It takes " << count << " loops until the linked list is only 1 node." << endl;

    return 0;
}