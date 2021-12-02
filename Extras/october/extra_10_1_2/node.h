#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node(T v);
};

template <typename T>
Node<T>::Node(T v) {
    data = v;
    next = nullptr;
}

#endif // !NODE_H
