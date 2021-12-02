#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "node.h"
#include <string>

class EmptyStackException{};

template <typename T>
class Stack
{
private:
    Node<T> *top;
    int size;

public:
    Stack();
    bool isEmpty();
    void push(T v);
    void pop();
    T peek();
    int getSize();
    void display();
    ~Stack();
};

template <typename T>
Stack<T>::Stack()
{
    top = nullptr;
    size = 0;
}

template <typename T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}

template <typename T>
void Stack<T>::push(T val)
{
    Node<T> *temp = new Node<T>(val);
    temp->next = top;
    top = temp;
    size++;
    // std::cout << "Pushed: " << top->data << std::endl;
}

template <typename T>
void Stack<T>::pop()
{
    if (isEmpty())
    {
        std::cout << "Empty Stack" << std::endl;
        // throw EmptyStackException();
    }
    else
    {
        Node<T> *temp = top;
        top = temp->next;
        // std::cout << "Popped: " << temp->data << std::endl;
        delete temp;
    }
}

template <typename T>
T Stack<T>::peek() {
    // if(isEmpty()) {
    //     std::cout << "Empty Stack" << std::endl;
    //     // throw EmptyStackException();
    //     return;
    // } else {
    //     return top->data;
    // }
    // std::cout << "Peeking: " << top->data << std::endl;
    return top->data;
}

template <typename T>
int Stack<T>::getSize() {
    return size;
}

template <typename T>
void Stack<T>::display() {
    if(isEmpty()) {
        std::cout << "Empty Stack" << std::endl;
    } else {
        Node<T>* cur = top;
        while(cur->next != nullptr) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << cur->data << std::endl;
    }
}

template <typename T>
Stack<T>::~Stack() {
    // std::cout << "Destructor Called" << std::endl;

    while(top != nullptr) {
        Node<T>* temp = top;
        top = temp->next;
        delete temp;
    }
}

#endif // !STACK_H
