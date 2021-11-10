#ifndef PQ_H
#define PQ_H

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"

class PQueue {
    private:
        Node* front;
        Node* rear;
    public:
        PQueue();
        bool isEmpty();
        double priorityPeek();
        double priorityRear();
        void enqueue(string data, double p);
        void dequeue();
        void display();
        void sendOutput(ofstream &outfile);
};

PQueue::PQueue() {
    front = rear = nullptr;
}

bool PQueue::isEmpty() {
    return front == nullptr;
}

double PQueue::priorityPeek() {
    if(isEmpty()) {
        return -1;
    } else {
        return front->priority;
    }
}

double PQueue::priorityRear() {
    if(isEmpty()) {
        return -1;
    } else {
        return rear->priority;
    }
}

void PQueue::enqueue(string exp, double p) {
    Node* temp = new Node(exp, p);
    temp->next = nullptr;
    if(isEmpty()) {
        front = temp;
        rear = front;
    } else {
        Node* cur = front;
        Node* prev = nullptr;
        while(cur != nullptr) {
            if(cur->priority > temp->priority) {
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if(prev == nullptr) {
            temp->next = front;
            front = temp;
        } else {
            temp->next = prev->next;
            prev->next = temp;
        }

        if(temp->next == nullptr) {
            rear = temp;
        }
    }
}

void PQueue::dequeue(){
    if(isEmpty()) {
        std::cout << "Empty" << std::endl;
    } else {
        Node* temp = front;
        front = temp->next;
        delete temp;
    }
}

void PQueue::display() {
    if(isEmpty()) {
        std::cout << "Can't print empty list" << std::endl;
    } else {
        Node* cur = front;

        while(cur != nullptr) {
            std::cout << cur->data << endl;
            cur = cur->next;
        }
    }
}

void PQueue::sendOutput(ofstream &outfile) {
    if (isEmpty())
    {
        outfile << "No valid data in input" << endl;
    }
    else
    {
        Node *cur = front;
        while (cur != nullptr)
        {
            outfile << cur->data << endl;
            cur = cur->next;
        }
    }
}

#endif