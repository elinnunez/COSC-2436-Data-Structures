#ifndef DOUBLY_H
#define DOUBLY_H

#include <iostream>
#include "node.h"

template <typename T>
class Doubly
{
    private:
        node<T> *head;
        node<T> *tail;
        int size;

    public:
        Doubly();
        Doubly(T value);
        bool isEmpty();
        void addatBeg(T val);

        void addatIndex(T val, int index);
        void addatEnd(T val);
        bool deleteatBeg();
        bool deleteatIndex(int index);
        bool deleteatEnd();
        bool modifyatIndex(T val, int index);
        int getSize(); // done
        node<T> *getHead();
        node<T> *getTail();

        void display(); // done
        void displayReverse();
};

template <typename T>
Doubly<T>::Doubly()
{
    head = tail = nullptr;
    size = 0;
}

template <typename T>
Doubly<T>::Doubly(T value)
{
    head = new node<T>(value);
    tail = head;
    size = 1;
}

template <typename T>
bool Doubly<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
void Doubly<T>::addatBeg(T val)
{
    if (isEmpty())
    {
        head = new node<T>(val);
        head->prev = nullptr;
        head->next = nullptr;
        tail = head;
        size = 1;
    }
    else
    {
        node<T> *temp = new node<T>(val);
        temp->next = head;
        temp->prev = nullptr;
        head->prev = temp;
        head = temp;
        size++;
    }
}

template <typename T>
int Doubly<T>::getSize()
{
    return size;
}

template <typename T>
void Doubly<T>::display()
{
    if (isEmpty())
    {
        std::cout << "Empty List" << std::endl;
        return;
    }
    node<T> *cur = head;

    while (cur->next != nullptr)
    {
        std::cout << cur->data << "->";
        cur = cur->next;
    }
    std::cout << cur->data << std::endl;
}

#endif