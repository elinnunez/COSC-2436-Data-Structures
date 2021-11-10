#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <class T>
class Stack {
private:
	Node<T>* top;
public:
	Stack() {
		this->top = nullptr;
	};

	void Push(T data) {
		Node<T>* temp = new Node<T>(data);

		this->Push(temp);
	};
	void Push(Node<T>* node) {
		if (this->top == nullptr) {
			this->top = node;
			return;
		}

		node->next = this->top;
		this->top = node;
	};

	Node<T>* Pop() {
		Node<T>* temp = this->top;
		this->top = temp->next;
		return temp;
	};
	Node<T>* Peek() {
		return this->top;
	};

	bool Empty() {
		return this->top == nullptr;
	};
};

#endif