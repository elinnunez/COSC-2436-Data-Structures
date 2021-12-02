#ifndef DASTACK_H
#define DASTACK_H

#include <iostream>

// class EmptyStackException{};

template <typename T>
class stack {
    private:
        T* bag;
        int top;
        int size;
    public:
        stack(int s);
        bool isEmpty();
        bool isFull();
        void push(T val);
        void pop();
        T const peek();
        void display();
        ~stack();
};

template <typename T>
stack<T>::stack(int s) {
    std::cout << "Overloaded Constructor Called" << std::endl;
    size = s;
    top = -1;
    bag = new T[size];

}

template <typename T>
bool stack<T>::isEmpty() {
    return top == -1;
}

template<typename T>
bool stack<T>::isFull() {
    return top == size-1;
}

template <typename T>
void stack<T>::push(T val) {
    if(isFull()) {
        std::cout << "Stack is full" << std::endl;
    } else {
        top++;
        bag[top] = val;
    } 
}

template <typename T>
void stack<T>::pop() {
    if(isEmpty()) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        T temp = bag[top];
        top--;
        std::cout << "Popped: " << temp << std::endl;
    }
}

template <typename T>
T const stack<T>::peek() {
    if(isEmpty()) {
        std::cout << "No top element" << std::endl;
        // throw EmptyStackException();
    } else {
        return bag[top];
    }
}

template <typename T>
void stack<T>::display() {
    if(isEmpty()) {
        std::cout << "Empty Stack" << std::endl;
    } else {
        for(int i = top; i >= 0; i--) {
            std::cout << bag[i] << std::endl;
        }
    }
}

template <typename T>
stack<T>::~stack() {
    std::cout << "Destructor Called" << std::endl;
    delete [] bag;
}

#endif // !DASTACK_H
