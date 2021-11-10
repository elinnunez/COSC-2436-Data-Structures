#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
    Node(std::string data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    std::string data;
    Node* next;
    Node* prev;
};

#endif