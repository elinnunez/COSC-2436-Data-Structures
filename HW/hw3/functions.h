#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isOperator(char x)
{

    if (x == '+' || x == '-' || x == '/' || x == '*')
    {
        return true;
    }
    return false;
}

bool isOperand(char c) {
    if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return true;
    }
    return false;
}

string post2Pre(string equation)
{
    // std::cout << "In post2pre: " << equation << std::endl;
    stack<string> temp;
    string op1,op2, exp;
    for(int i = 0; i < equation.size(); i++) {
        string curelt(1,equation[i]);
        char cur = equation[i];

        if(isOperand(cur)) {
            // cout << "curelt: " << curelt << endl;
            temp.push(curelt);
            // cout << "topp: " << temp.getTop() << endl;
        } else if(isOperator(cur)) {
            op1 = temp.top();
            // cout << "op1: " << op1 << endl;
            temp.pop();
            op2 = temp.top();
            // cout << "op2: " << op2 << endl;
            temp.pop();
            exp = curelt + op2 + op1;
            // cout << "exp: " << exp << endl;
            temp.push(exp);
        }
    }
    // cout << "Post 2 Pre: " << temp.top() << endl;
    string final = temp.top();

    return final;
}

string pre2Post(string equation)
{
    // std::cout << "In pre2post: " << equation << std::endl;
    stack<string> temp;
    string op1,op2, exp;
    for(int i = equation.size()-1; i >= 0; i--) {
        string curelt(1,equation[i]);
        char cur = equation[i];

        if(isOperand(cur)) {
            // cout << "curelt: " << curelt << endl;
            temp.push(curelt);
            // cout << "topp: " << temp.getTop() << endl;
        } else if(isOperator(cur)) {
            op1 = temp.top();
            // cout << "op1: " << op1 << endl;
            temp.pop();
            op2 = temp.top();
            // cout << "op2: " << op2 << endl;
            temp.pop();
            exp = op1 + op2 + curelt;
            // cout << "exp: " << exp << endl;
            temp.push(exp);
        }
    }
    // cout << "Pre 2 Post: " << temp.top() << endl;
    string final = temp.top();

    return final;
}

#endif