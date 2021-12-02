#ifndef NODE_H
#define NODE_H

#include <iostream>

struct Node {
    Node* left;
    int val;
    Node* right;
    Node(int v) {
        val = v;
        left = right = nullptr;
    }
};

#endif