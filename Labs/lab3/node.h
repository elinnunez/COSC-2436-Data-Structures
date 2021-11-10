#ifndef  NODE_H
#define NODE_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    string book;
    Node* next;
    Node(string val);
};

Node::Node(string v) {
    book = v;
}

#endif // ! NODE_H
