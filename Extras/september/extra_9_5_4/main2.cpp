#include<iostream>

using namespace std;

class MinStack {
public:
    struct node {
        int val;
        int minVal;
        node* prev;
    };
    
    struct node *topp;
    
    MinStack() {
        topp = nullptr;
    }
    
    void push(int val) {
        node* temp = new node;
        temp->val = val;
        if(topp == nullptr) {
            temp->minVal = val;
        //Basically the minVal in the node keeps track of the smallest value in the nodes previous
        } else {
            if(topp->minVal > val) {
                temp->minVal = val;
            } else {
                temp->minVal = topp->minVal;
            }
        }
        temp->prev = topp;
        topp = temp;
        
    }
    
    void pop() {
        node* temp = topp;
        topp = temp->prev;
        delete temp;
    }
    
    int top() {
        return topp->val;   
    }
    
    int getMin() {
        return topp->minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

int main()
{
    //input
    //["MinStack","push","push","push","getMin","pop","top","getMin"]
    //[[],[-2],[0],[-3],[],[],[],[]]

    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    obj->getMin();
    obj->pop();
    obj->top();
    obj->getMin();
    int param_3 = obj->top(); // 0
    int param_4 = obj->getMin(); // -2

    cout << param_3 << endl;
    cout << param_4 << endl;


    return 0;
}