#ifndef IDSTACK_H
#define IDSTACK_H

#include "Node.h"

class IDStack {
private:
    Node* top;
    int size;
public:
    IDStack();

    void Push(std::string data);
    Node* Pop();
    Node* Peek();
    bool isEmpty();

    std::string FormatString(std::string data);
};

#endif