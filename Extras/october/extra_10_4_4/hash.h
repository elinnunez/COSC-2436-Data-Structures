#ifndef HASH_H
#define HASH_H

#include <iostream>
#include "node.h"

class Hash {
    private:
        Node* head;
        Node* tail;
        int size; 
        bool privSearch(Node* node, int x);       
    public:
        Hash();
        bool isEmpty();
        void addAtEnd(int x);
        void delNode(int val);
        bool search(int num);
        int getLength();
        void display();
};

Hash::Hash() {
    head = tail = nullptr;
    size = 0;
}

bool Hash::isEmpty() {
    return head == nullptr;
}

void Hash::addAtEnd(int x) {
    Node* temp = new Node(x);
    if(isEmpty()) {
        head = temp;
        tail = head;
    } else {
        tail->next = temp;
        tail = temp;
    }
    size++;
}

bool Hash::privSearch(Node* node, int x) {
    if(node == nullptr) {
        std::cout << "False" << std::endl;
        return false;
    } else if(node->data == x) {
        std::cout << "True" << std::endl;
        return true;
    } else {
        privSearch(node->next, x);
    }
}

void Hash::delNode(int val) {
    if(isEmpty()) {
        std::cout << "Not Found, Can't Delete Node" << std::endl;
        return;
    } else {
        Node* cur = head;
        Node* prev = nullptr;

        while(cur != nullptr) {
            if(cur->data == val) {
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if(cur != nullptr) {
            int curVal = cur->data;
            if(cur == head && cur == tail) {
                Node* temp = cur;
                head = temp->next;
                tail = head;
                delete temp;
            } else if(cur == tail) {
                prev->next = nullptr;
                tail = prev;
            } else if(cur == head) {
                Node* temp = cur;
                head = temp->next;
                delete temp;
            } else {
                prev->next = cur->next;
            }
            size--;
            std::cout << "Deleted: " << curVal << std::endl;
            return;
        } else {
            std::cout << "Val Not Found" << std::endl;
            return;
        }
    }
}

bool Hash::search(int x) {
    return privSearch(head, x);
}

int Hash::getLength() {
    return size;
}

void Hash::display() {
    Node* cur = head;
    if(isEmpty()) {
        std::cout << "Empty" << std::endl;
    } else {
        while(cur != nullptr) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
}



#endif