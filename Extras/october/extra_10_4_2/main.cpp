#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

bool isPalindromeRec(stack<char> stack1, queue<char> queue1)
{
    stack<char> s1 = stack1;
    queue<char> q1 = queue1;

    if(s1.empty() && q1.empty()) {
        cout << "Palindrome" << endl;
        return true;
    } else if(s1.top() != q1.front()) {
        cout << "Not A Palindrome" << endl;
        return false;
    } else {
        s1.pop();
        q1.pop();
        return isPalindromeRec(s1,q1);
    }
}

bool isPalindromeIt(stack<char> stack1, queue<char> queue1) {
    stack<char> s1 = stack1;
    queue<char> q1 = queue1;

    while(s1.top() == q1.front()) {
        s1.pop();
        q1.pop();
        if(s1.empty() && q1.empty()) {
            break;
        }
    }

    if(s1.empty() && q1.empty()) {
        cout << "Palindrome" << endl;
        return true;
    } else {
        cout << "Not Palindrome" << endl;
        return false;
    }
}


int main()
{

    string input = "racetsdtecar";

    stack<char> s1;
    queue<char> q1;

    for (int i = 0; i < input.length(); i++)
    {
        s1.push(input[i]);
        q1.push(input[i]);
    }


    isPalindromeRec(s1, q1);
    isPalindromeIt(s1,q1);

    return 0;
}