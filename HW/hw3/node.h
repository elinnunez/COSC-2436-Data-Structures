#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

struct Node {
    std::string type;
    std::string equation;
    Node* next;
    Node* prev;
};

#endif