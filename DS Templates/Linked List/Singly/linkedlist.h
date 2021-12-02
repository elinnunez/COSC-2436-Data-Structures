#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "node.h"

template <typename T>
class linked {
    private:
        node<T>* head;
        node<T>* tail;
        int size;
    public:
        linked();
        linked(T val);
        bool isEmpty();
        void addatBeg(T val);
        void addatEnd(T val);
        bool removeBeg();

        bool removeEnd();
        int getSize();
        void display();
};

template <typename T>
linked<T>::linked() {
    head = tail = nullptr;
    size = 0;
}

template <typename T>
linked<T>::linked(T val) {
    head = new node<T>(val);
    head->next = nullptr;
    tail = head;
    size = 1;
}

template <typename T>
bool linked<T>::isEmpty() {
    return head == nullptr;
}

template <typename T>
void linked<T>::addatBeg(T val) {
    if(isEmpty()) {
        head = new node<T>(val);
        head->next = nullptr;
        tail = head;
    } else {
        node<T>* temp = new node<T>(val);
        temp->next = head;
        head = temp;
    }
    size++;
}

template <typename T>
void linked<T>::addatEnd(T val) {
    if(isEmpty()) {
        head = new node<T>(val);
        head->next = nullptr;
        tail = head;
    } else {
        node<T>* cur = head;
        while(cur->next != nullptr) {
            cur = cur->next;
        }

        cur->next = new node<T>(val);
        cur->next->next = nullptr;
        tail = cur->next;
    }
    size++;
}

template <typename T>
bool linked<T>::removeBeg() {
    if(isEmpty()) {
        std::cout << "Empty List, Nothing to Remove at Beginning" << std::endl;
        return false;
    } else {
        node<T>* temp = head;
        head = temp->next;

        delete temp;

        size--;

        if(size == 0) || size == 1) {
            tail = head;
        }

        return true;
    }
}

template<typename T>
bool linked<T>::removeEnd() {
    if(isEmpty()) {
        std::cout << "Empty List, Nothing to Remove at End" << std::endl;
        return false;
    } else {
        node<T>* cur = head;
        node<T>* prev = nullptr;

        while(cur != tail) {
            prev = cur;
            cur = cur->next;
        }

        if(prev = nullptr) {
            node<T>* temp = head;
            head = temp->next;
            tail = head;
            delete temp;
            size--;
        } else if () {
            
        }


    }
}

#endif