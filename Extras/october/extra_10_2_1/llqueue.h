#ifndef LLQUEUE_H
#define LLQUEUE_H

#include <iostream>
#include "node.h"

template <typename T>
class Queue {
    private:
        Node<T>* front;
        Node<T>* back;
        int size;
    public:
        Queue();
        bool isEmpty();
        void enqueue(T val);
        void dequeue();
        void getFront();
        void display();
        int getSize();
        void displayRec(Node<T>* head);
        Node<T>* getFrontNode();
        ~Queue();
};

template <typename T>
Queue<T>::Queue() {
    front = back = nullptr;
    size = 0;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return front == nullptr;
}

template <typename T>
void Queue<T>::enqueue(T val) {
    Node<T>* temp = new Node<T>(val);
    // temp->next = nullptr;
    size++;
    if(isEmpty()) {
        front = temp;
        back = front;
    } else {
        back->next = temp;
        back = temp;
    }
}

template <typename T>
void Queue<T>::dequeue() {
    if(isEmpty()) {
        std::cout << "Empty List" << std::endl;
    } else {
        Node<T>* temp = front;
        front = temp->next;
        delete temp;
        size--;
    }
}

template <typename T>
void Queue<T>::getFront() {
    if(isEmpty()) {
        std::cout << "Empty List" << std::endl;
    } else {
        std::cout << front->val << std::endl;
    }
}

template <typename T>
void Queue<T>::display() {
    if(isEmpty()) {
        std::cout << "Empty List" << std::endl;
    } else {
        Node<T>* cur = front;
        while(cur->next != nullptr) {
            std::cout << cur->val << " ";
            cur = cur->next;
        }
        std::cout << cur->val << std::endl;
    }
}

template <typename T>
int Queue<T>::getSize() {
    return size;
}

template <typename T>
void Queue<T>::displayRec(Node<T>* head) {
    if(head->next == nullptr) {
        std::cout << head->val << std::endl;
        return;
    }
    std::cout << head->val << " ";
    displayRec(head->next);

}

template <typename T>
Node<T>* Queue<T>::getFrontNode() {
    return front;
}

template <typename T>
Queue<T>::~Queue() {
    std::cout << "Destructor Called" << std::endl;
    if(isEmpty()) {
        std::cout << "Empty List" << std::endl;
    } else {
        while(front != nullptr) {
            Node<T>* temp = front;
            front = temp->next;
            delete temp;
        }
    }
}

#endif // !LLQUEUE_H
