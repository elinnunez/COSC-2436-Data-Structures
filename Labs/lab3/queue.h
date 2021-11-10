#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"

class Queue {
    private:
        Node* front;
        Node* back;
        int size;
    public:
        Queue();
        bool isEmpty();
        void enqueue(string val);
        void dequeue();
        void display();
        void length();
        void sendOutput(ofstream &outfile);
        string getFront();
        ~Queue();
};

Queue::Queue() {
    front = back = nullptr;
    size = 0;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::enqueue(string v) {
    Node* temp = new Node(v);
    temp->next = nullptr;
    size+=1;
    if(isEmpty()) {
        front = temp;
        back = front;
    } else {
        back->next = temp;
        back = temp;
    }
}

void Queue::dequeue() {
    if(isEmpty()) {
        std::cout << "Empty Queue" << std::endl;
    } else {
        Node* temp = front;
        front = temp->next;
        size-=1;
        delete temp;
    }
}

void Queue::display() {
    if(isEmpty()) {
        std::cout << "Empty Queue" << std::endl;
    }
    if(size == 1) {
        std::cout << front->book << std::endl;
    } else {
        Node* cur = front;
        while(cur->next != nullptr) {
            std::cout << cur->book << ",";
            cur = cur->next;
        }
        std::cout << cur->book << std::endl;
    }
}

void Queue::length() {
    std::cout << "Queue size: " << size << std::endl;
}

string Queue::getFront() {
    if(isEmpty()) {
        return "Empty Queue";
    }
    return front->book;
}

void Queue::sendOutput(ofstream &outfile)
{
    if(isEmpty()) {
        std::cout << "Empty Queue" << std::endl;
    }
    if(size == 1) {
        outfile << front->book;
    } else {
        Node* cur = front;
        while(cur->next != nullptr) {
            outfile << cur->book << ",";
            cur = cur->next;
        }
        outfile << cur->book;
    }
}

Queue::~Queue() {
    // std::cout << "Destructor Called" << std::endl;
    while(front != nullptr) {
        Node* temp = front;
        front = temp->next;
        // std::cout << "Deleting: " << temp->book << std::endl;
        delete temp;
    }
}

#endif // !QUEUE_H