#ifndef NODE_H
#define NODE_H

template <typename T>
struct node {
    T data;
    node<T>* next;
    node(T data) {
        data = _data;
        next = nullptr;
    }

};

#endif //NODE_H