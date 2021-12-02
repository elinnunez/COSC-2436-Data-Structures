#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> s1;
        
        for(int i = 0; i < s.size(); i++) {
            if(s1.empty()) {
                s1.push(s[i]);
            } else {
                if(s1.top() == '(' && s[i] == ')' || s1.top() == '{' && s[i] == '}' || s1.top() == '[' && s[i] == ']') {
                s1.pop();
            } else {
                s1.push(s[i]);
            }
            }
        }
        
        if(s1.empty()) {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s1;

    cout << s1.isValid("()[]{}") << endl;
    cout << s1.isValid("()}") << endl;

    return 0;
}