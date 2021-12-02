#ifndef NODE_H
#define NODE_H

#include <iostream>

template <typename T>
struct node {
    T val;
    node<T>* next;
};


#endif