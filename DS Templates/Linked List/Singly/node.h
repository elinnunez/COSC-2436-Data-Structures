#ifndef NODE_H
#define NODE_H

template <typename T>
struct node {
    T data;
    node<T>* next;
    node() {
        next = nullptr;
    }
    node(T _data) {
        data = _data;
        next = nullptr;
    }

};

#endif //NODE_H