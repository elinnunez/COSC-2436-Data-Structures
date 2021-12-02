#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>

class mystack {
    private:
        char* bag;
        int topp;
        int size;
    public:
        mystack(int s) {
            std::cout << "Overloaded Constructor Called" << std::endl;
            size = s;
            bag = new char[s];
            topp = -1;
        }
        bool isEmpty() {
            return topp == -1;
        }
        bool isFull() {
            return topp == size-1;
        }
        void push(char e) {
            if(isFull()) {
                std::cout << "Stack is Full" << std::endl;
            } else {
                topp++;
                bag[topp] = e;
                std::cout << "Pushed: " << bag[topp] << std::endl;
            }
        }
        void pop() {
            if(isEmpty()) {
                std::cout << "Empty Stack" << std::endl;
            } else {
                char temp = bag[topp];
                --topp;
                std::cout << "Popped: " << temp << std::endl;
            }
        }
        char top() {
            return bag[topp];
        }
        void print() {
            if(isEmpty()){
                std::cout<<"Empty Stack"<<std::endl;
            } else {
                for(int i=topp; i>=0; i--){
                    std::cout<<bag[i]<<" ";
                }
                std::cout<<std::endl;
            }
        }
        ~mystack() {
            std::cout << "Destructor Called" << std::endl;
            delete [] bag;
        }
};


#endif // !MYSTACK_H