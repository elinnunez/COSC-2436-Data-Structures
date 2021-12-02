#ifndef PFTOIF_H
#define PFTOIF_H

#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

string genInfix(string input) {
    Stack<string> bag;

    int size = input.length();
    string a, b, temp;

    for(int i = 0; i < size; i++) {
        string curelt(1,input[i]);
        // cout << "Curelt: " << curelt << endl;
        if(curelt == "*" || curelt == "/" || curelt == "+" || curelt == "-" || curelt == "^") {
            a = bag.peek();
            bag.pop();
            b = bag.peek();
            bag.pop();
            temp = "("+b+curelt+a+")";
            bag.push(temp);
        } else {
            bag.push(curelt);
        }
    }
    
    return bag.peek();
}

#endif // !PFTOIF_H
