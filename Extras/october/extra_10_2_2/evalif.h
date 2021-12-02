#ifndef EVALIF_H
#define EVALIF_H

#include <iostream>
#include <string>
#include "stack.h"
#include "iftopf.h"
#include <cmath>

using namespace std;

int evalInfix(string oginput)
{
    Stack<int> bag;
    string input = genPostFix(oginput);
    int size = input.length();

    // cout << "Post Fix Version: " << input << endl;

    int temp = 0;
    int a;
    int b;

    for (int i = 0; i < size; i++)
    {
        char curelt = input[i];

        if (isdigit(curelt)) {
            bag.push((int)(curelt)-48);
            // cout << bag.peek() << endl;
        }
        else
        {
            a = bag.peek();
            bag.pop();
            b = bag.peek();
            bag.pop();
            switch (curelt)
            {
            case '+':
                temp = b + a;
                break;
            case '-':
                temp = b - a;
                break;
            case '*':
                temp = b * a;
                break;
            case '/':
                temp = b / a;
                break;
            case '%':
                temp = b % a;
                break;
            case '^':
                temp = pow(b, a);
            }
            bag.push(temp);
        }
    }

    return bag.peek();
}

#endif // !EVALIF_H
