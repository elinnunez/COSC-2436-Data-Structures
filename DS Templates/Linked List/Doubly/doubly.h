#ifndef DOUBLY_H
#define DOUBLY_H

#include <iostream>
#include "node.h"

template <typename T>
class Doubly {
    private:
        node<T>* head;
        node<T>* tail;
        int size;
    public:
        Doubly();
        Doubly(T value);
        bool isEmpty():
};

template <typename T>
Doubly<T>::Doubly() {
    head = tail = nullptr;
    size = 0;
}

template <typename T>
Doubly<T>::Doubly(T value) {
    head = new node<T>(value);
    tail = head;
    size = 1;
}

template <typename T>
bool Doubly<T>::isEmpty() {
    return head == nullptr;
}

#endif