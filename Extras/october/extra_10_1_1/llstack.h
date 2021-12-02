#ifndef LLSTACK_H
#define LLSTACK_H

#include "node.h"

class EmptyStackException
{
};

template <typename T>
class Stack
{
private:
    node<T> *top;

public:
    Stack();
    bool isEmpty();
    void push(T val);
    void pop();
    T const peek();
    void display();
    ~Stack();
};

template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}

template <typename T>
void Stack<T>::push(T val)
{
    node<T> *temp = new node<T>;
    temp->val = val;
    temp->next = top;
    top = temp;
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Empty Stack" << std::endl;
        throw EmptyStackException();
    }
    else
    {
        node<T> *temp = top;
        top = temp->next;
        delete temp;
    }
}

template <typename T>
T const Stack<T>::peek()
{
    if (isEmpty())
    {
        std::cout << "Empty list" << std::endl;
        throw EmptyStackException();
    }
    else
    {
        return top->val;
    }
}

template<typename T>
void Stack<T>::display() {
    if(isEmpty()) {
        std::cout << "Empty Stack" << std::endl;
    } else {
        node<T>* cur = top;
        while(cur != nullptr) {
            std::cout << cur->val << std::endl;
            cur = cur->next;
        }
    }
}

template <typename T>
Stack<T>::~Stack() {
    std::cout << "Destructor Called" << std::endl;

    while(top != nullptr) {
        node<T>* temp = top;
        // std::cout << "Destroying: " << temp->val << std::endl;
        top = temp->next;
        delete temp;
    }
}

#endif // !LLSTACK_H