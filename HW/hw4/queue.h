#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include "node.h"

class Queue {
    private:
        Node* front;
        Node* rear;
    public:
        Queue();
        bool isEmpty();
        void enqueue(std::string d);
        void dequeue();

        void replaceChar(char a, char b);
        void removeChar(char v);
        void swapChar(char a, char b);
        void addChar(char a, char b);
        string getFront();
        ~Queue();
};

Queue::Queue() {
    front = rear = nullptr;
}

bool Queue::isEmpty() {
    return front == nullptr;
}

void Queue::enqueue(std::string exp) {
    Node* temp = new Node(exp);
    if(isEmpty()) {
        front = temp;
        rear = front;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

void Queue::dequeue() {
    if(isEmpty()) {
        return;
    } else {
        Node* temp = front;
        front = temp->next;
        delete temp;
    }
}

void Queue::replaceChar(char a, char b) {
    if(isEmpty()) {
        return;
    } else {
        string data = front->data;
        for(int i = 0; i < data.length(); i++) {
            if(data[i] == a) {
                data[i] = b;
            }
        }
        front->data = data;
    }
}

void Queue::removeChar(char v) {
    if(isEmpty()) {
        return;
    } else {
        string data = front->data;
        string temp = "";

        for(int i = 0; i < data.length(); i++) {
            if(data[i] == v) {
                continue;
            } else {
                temp+=data[i];
            }
        }

        front->data = temp;
    }
}

void Queue::swapChar(char a, char b) {
    if(isEmpty()) {
        return;
    } else {
        string data = front->data;
        for(int i = 0; i < data.length(); i++) {
            if(data[i] == a) {
                data[i] = b;
            } else if (data[i] == b) {
                data[i] = a;
            } else {
                continue;
            }
        }

        front->data = data;
    }
}

void Queue::addChar(char a, char b) {
    if(isEmpty()) {
        return;
    } else {
        string data = front->data;
        string temp = "";
        for(int i = 0; i < data.length(); i++) {
            if(data[i] == a) {
                temp+= data[i];
                temp+= b;
            } else {
                temp+=data[i];
            }
        }

        front->data = temp;
    }
}

string Queue::getFront() {
    return front->data;
}

Queue::~Queue() {
    while(front != nullptr) {
        Node* temp = front;
        front = temp->next;
        delete temp;
    }
}

#endif // !QUEUE_H
