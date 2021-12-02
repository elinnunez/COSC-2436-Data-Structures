#ifndef IFTOPF_H
#define IFTOPF_H

#include <iostream>
#include "stack.h"
#include <cstring>
#include <string>
#include <typeinfo>

using namespace std;

// bool isOperator(char c) {
//     if(c == '^' || c == '/' || c == '*' || c == '+' || c == '-') {
//         return true;
//     } else {
//         return false;
//     }
// }

int priority(char x)
{
    if (x == '^')
    {
        return 3;
    }
    if (x == '/' || x == '*')
    {
        return 2;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    return -1;
}

string genPostFix(string input)
{
    Stack<char> bag;
    int size = input.length();
    string res;
    // cout << input << endl;
    for (int i = 0; i < size; i++)
    {
        char curelt = input[i];
        
        if (isdigit(curelt))
        {
            res += curelt;
        }
        else if (curelt == '(')
        {
            bag.push(curelt);
        }
        else if (curelt == ')')
        {
            while (!bag.isEmpty() && bag.peek() != '(')
            {
                res += bag.peek();
                bag.pop();
            }
            bag.pop();
        }
        else
        {
            if (bag.isEmpty())
            {
                bag.push(curelt);
            }
            else if (!bag.isEmpty())
            {
                if (priority(curelt) > priority(bag.peek()))
                {
                    bag.push(curelt);
                }
                // else if (priority(curelt) == priority(bag.peek()) && curelt = '^')
                // {
                //     bag.push(curelt);
                // }
                else
                {
                    while (!bag.isEmpty() && priority(curelt) <= priority(bag.peek()))
                    {
                        res += bag.peek();
                        bag.pop();
                    }
                    bag.push(curelt);
                }
            }
        }
    }

    while (!bag.isEmpty())
    {
        res += bag.peek();
        bag.pop();
    }
    // cout << "Res:" << res << endl;
    return res;
}

#endif // !IFTOPF_H
