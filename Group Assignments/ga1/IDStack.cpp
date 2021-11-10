#include "IDStack.h"

IDStack::IDStack() {
    this->top = nullptr;
    this->size = 0;
}

void IDStack::Push(std::string data) {
    Node* temp = new Node(data);
  
    if (this->top == nullptr) {
        this->top = temp;
        this->size++;
        return;
    }

    temp->next = this->top;
    this->top = temp;
    this->size++;
}

Node* IDStack::Pop() {
    Node* oldTop = this->top;
    this->top = oldTop->next;
    return oldTop;
}

Node* IDStack::Peek() {
    return this->top;
}

bool IDStack::isEmpty() {
    return (this->top == nullptr);
}