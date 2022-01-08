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
        Doubly();                          // done
        Doubly(T value);                   // done
        bool isEmpty();                    // done
        void addatBeg(T val);              // done
        void addatIndex(T val, int index); // done
        void addatEnd(T val); // done
        
        bool deleteatBeg();
        bool deleteatIndex(int index);
        bool deleteatEnd();
        void modifyatIndex(T val, int index); // done
        int getSize(); // done
        node<T> *getHead();
        node<T> *getTail();

        void display();        // done
        void displayReverse(); // done
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
void Doubly<T>::addatIndex(T val, int ind)
{
    if (isEmpty())
    {
        head = new node<T>(val);
        head->prev = nullptr;
        head->next = nullptr;
        tail = head;
        size++;
    }
    else
    {
        int i = 0;
        node<T> *cur = head;
        while (i != ind && cur != nullptr)
        {
            cur = cur->next;
            i++;
        }

        if (ind <= 0)
        {
            node<T> *temp = new node<T>(val);
            temp->prev = nullptr;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        else if (cur == nullptr || ind >= size)
        {
            tail->next = new node<T>(val);
            tail->next->next = nullptr;
            tail->next->prev = tail;
            tail = tail->next;
        }
        else
        {
            node<T> *temp = new node<T>(val);
            cur->prev->next = temp;
            temp->prev = cur->prev;
            cur->prev = temp;
            temp->next = cur;
        }

        size++;
    }
}

template <typename T>
void Doubly<T>::addatEnd(T val)
{
    if (isEmpty())
    {
        head = new node<T>(val);
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        size++;
    }
    else
    {
        node<T> *temp = new node<T>(val);
        temp->prev = tail;
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
        size++;
    }
}

template <typename T>
void Doubly<T>::modifyatIndex(T val, int index) {
    if(isEmpty()) {
        head = new node<T>(val);
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        size++;
    } else {
        if(index <= 0 || index >= size-1) {
            if(index <= 0) {
                head->data = val;
            } else {
                tail->data = val;
            }
        } else {
            node<T>* cur = head;

            int i = 0;

            while(i != index) {
                cur = cur->next;
                i++;
            }

            cur->data = val;
        }
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

template <typename T>
void Doubly<T>::displayReverse()
{
    if (isEmpty())
    {
        std::cout << "Empty List" << std::endl;
        return;
    }
    node<T> *cur = tail;

    while (cur->prev != nullptr)
    {
        std::cout << cur->data << "->";
        cur = cur->prev;
    }
    std::cout << cur->data << std::endl;
}

#endif