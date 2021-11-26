#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct Node {
    T val;
    Node<T>* left;
    Node<T>* right;
    Node<T>(T v) {
        val = v;
        left = right = nullptr;
    }
};

#endif