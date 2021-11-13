#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <class T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;

	std::string ToString(Node<T>* node) {
		if (node == nullptr) {
			return "";
		}
		return node->data + "\n" + this->ToString(node->next);
	};
public:
	LinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	};

	void Add(T data) {
		Node<T>* temp = new Node<T>(data);

		if (this->head == nullptr) {
			this->head = temp;
			this->tail = temp;
			return;
		}

		this->tail->next = temp;
		this->tail = temp;
	};
	void Add(Node<T>* node) {
		this->Add(node->data);
	};

	Node<T>* GetHead()  {
		return this->head;
	};

	std::string ToString() {
		return this->ToString(this->head);
	};
};

#endif