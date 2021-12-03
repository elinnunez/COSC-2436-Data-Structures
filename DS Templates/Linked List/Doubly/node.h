#ifndef NODE_H
#define NODE_H

template <typename T>
struct node {
    T data;
    node<T>* prev;
    node<T>* next;
    node() {
        prev = next = nullptr;
    };
    node(T _data) {
        data = _data;
        prev = next = nullptr;
    };
};

#endif //NODE_H