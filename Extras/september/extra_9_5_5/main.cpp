#include <iostream>
#include "mystack.h"
#include <cstring>
#include <string>
#include <typeinfo>

using namespace std;

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
}

string genPostFix(mystack bag, string input, int size)
{
    string res;
    cout << input << endl;
    for (int i = 0; i < size; i++)
    {
        char curelt = input[i];
        // cout << "Cur Elt: " << curelt << endl;
        if (isdigit(curelt))
        {
            res += curelt;
            cout << "Digit: " << curelt << endl;
        }
        else if (curelt == '(')
        {
            bag.push(curelt);
        }
        else if (curelt == ')')
        {
            while (!bag.isEmpty() && bag.top() != '(')
            {
                res += bag.top();
                bag.pop();
            }
            bag.pop();
        }
        else
        {
            while ((priority(curelt) <= priority(bag.top())) && !bag.isEmpty() && bag.top() != '(')
            {
                res += bag.top();
                bag.pop();
            }
            bag.push(curelt);
        }
    }

    while (!bag.isEmpty())
    {
        res += bag.top();
        bag.pop();
    }

    return res;
}

int main()
{

    // char *sent;
    string sent;
    cout << "Enter infix expression: ";
    cin >> sent;

    int size = sent.length();

    mystack biggiebag(size);

    // int size = strlen(sent);

    string output = genPostFix(biggiebag, sent, size);

    cout << "Postfix: " << output << endl;

    // delete[] sent;

    return 0;
}