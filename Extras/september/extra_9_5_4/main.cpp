#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> bag;
        
        int total;
        int right;
        int left;
        
        for(int i = 0; i < tokens.size(); i++) {
            try {
                if(tokens.at(i) == "0") {
                    bag.push("0");
                } else {
                    if(stoi(tokens.at(i))) {
                        bag.push(tokens.at(i));
                    }
                }
                
            } catch(invalid_argument &e) {
                if(tokens.at(i) == "+") {
                    right = stoi(bag.top());
                    bag.pop();
                    left = stoi(bag.top());
                    bag.pop();
                    total = right + left;
                    bag.push(to_string(total));
                    cout <<"After adding: " << total << endl;
                } else if(tokens.at(i) == "-") {
                    right = stoi(bag.top());
                    bag.pop();
                    left = stoi(bag.top());
                    bag.pop();
                    total = left - right;
                    bag.push(to_string(total));
                    cout <<"After subtracting: " << total << endl;
                } else if(tokens.at(i) == "/") {
                    right = stoi(bag.top());
                    bag.pop();
                    left = stoi(bag.top());
                    bag.pop();
                    total = left / right;
                    bag.push(to_string(total));
                    cout << "After dividing: " << total << endl;
                } else if(tokens.at(i) == "*") {
                    right = stoi(bag.top());
                    bag.pop();
                    left = stoi(bag.top());
                    bag.pop();
                    total = right * left;
                    bag.push(to_string(total));
                    cout << "After multiplying: " << total << endl;
                } else if(tokens.at(i) == "^") {
                    right = stoi(bag.top());
                    bag.pop();
                    left = stoi(bag.top());
                    bag.pop();
                    total = pow(left,right);
                    bag.push(to_string(total));
                    cout << "After power: " << total << endl;
                }
            }
        }
        
        return stoi(bag.top());
    }
};

int main()
{

    Solution test1, test2, test3;

    vector<string> tokens1 = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    vector<string> tokens2 = {"4","13","5","/","+"};
    vector<string> tokens3 = {"2", "3", "^", "5", "4", "*", "/", "10", "+"};

    cout << test1.evalRPN(tokens1) << endl; // 22
    cout << test2.evalRPN(tokens2) << endl; // 6
    cout << test3.evalRPN(tokens3) << endl; // 10


    return 0;
}