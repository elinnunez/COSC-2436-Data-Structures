#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

struct Node
{
    std::string data;
    double priority;
    Node *next;
    Node(std::string val, double x);
};

Node::Node(std::string val, double x)
{
    data = val;
    priority = x;
    next = nullptr;
}

#endif