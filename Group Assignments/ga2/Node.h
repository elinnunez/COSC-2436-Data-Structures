#ifndef NODE_H
#define NODE_H

#include <string>

template <class T>
struct Node {
	Node(T data) {
		this->data = data;
		this->next = nullptr;
	};

	T data;

	Node<T>* next;
};

#endif