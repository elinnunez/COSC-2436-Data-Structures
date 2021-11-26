#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

struct Node {
    std::string data;
    int priority;
    Node* next;
    Node(std::string d, int p);
    Node(std::string d);
};

Node::Node(std::string d, int p) {
    data = d;
    priority = p;
    next = nullptr;
}

Node::Node(std::string d) {
    data = d;
    next = nullptr;
}

#endif // !NODE_H
