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

        void addatBeg(T val);
        void addatIndex(T val, int index);
        void addatEnd(T val);
        bool deleteatBeg();
        bool deleteatIndex(int index);
        bool deleteatEnd();
        bool modifyatIndex(T val, int index);
        int getSize();
        node<T>* getHead();
        node<T>* getTail();
        void display();
        void displayReverse();

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