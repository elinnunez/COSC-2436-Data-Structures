#ifndef PQUEUE_H
#define PQUEUE_H

#include <iostream>
#include <string>
#include "node.h"

class PQueue
{
private:
    Node *front;
    Node *rear;

public:
    PQueue();
    bool isEmpty();
    void enqueue(std::string d, int v);
    void dequeue();

    string getFront();
    void printPQueue();
    ~PQueue();
};

PQueue::PQueue()
{
    front = nullptr;
}

bool PQueue::isEmpty()
{
    return front == nullptr;
}

void PQueue::enqueue(std::string d, int v)
{
    Node *temp = new Node(d, v);
    if (isEmpty())
    {
        front = temp;
        rear = front;
    }
    else
    {
        Node *cur = front;
        Node *prev = nullptr;
        while (cur != nullptr)
        {
            if (cur->priority > temp->priority)
            {
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if (prev == nullptr)
        {
            temp->next = front;
            front = temp;
        }
        else
        {
            temp->next = prev->next;
            prev->next = temp;
        }

        if (temp->next == nullptr)
        {
            rear = temp;
        }
    }
}

void PQueue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Empty" << std::endl;
    }
    else
    {
        Node *temp = front;
        front = temp->next;
        delete temp;
    }
}

string PQueue::getFront() {
    if(isEmpty()) {
        return "Empty Front";
    } else {
        return front->data;
    }
}


void PQueue::printPQueue() {
    if(isEmpty()) {
        std::cout << "Empty Print of PQueue" << std::endl;
    } else {
        Node* cur = front;
        while(cur != nullptr) {
            std::cout << cur->data << " [" << cur->priority << "]" << endl;
            cur = cur->next;
        }
    }
}

PQueue::~PQueue() {
    while(front != nullptr) {
        Node* temp = front;
        front = temp->next;
        delete temp;
    }
}

#endif // !PQUEUE_H
