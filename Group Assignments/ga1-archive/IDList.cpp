#include "IDList.h"

IDList::IDList() {
    this->head = nullptr;
    this->size = 0;
}

Node* IDList::GetHead() {
    return this->head;
}

Node* IDList::GetTail() { 
    return this->tail;
}

Node* IDList::GetNode(int index) {
    if (this->size < index) {
        return nullptr;
    }
    return this->GetNode(index, 0, this->head);
}

Node* IDList::GetNode(int index, int pos, Node *node) {
    if (pos == index) {
        return node;
    }
    else {
        return GetNode(index, pos + 1, node->next);
    }
}

int IDList::GetLength() {
    return this->size;
}

bool IDList::IsEmpty() {
    return (this->head == nullptr);
}

void IDList::Add(std::string data) {
    Node* temp = new Node(data);

    if (this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
        this->size++;
        return;
    }

    this->tail->next = temp;
    temp->prev = this->tail;
    this->tail = temp;
    this->size++;
}

int IDList::Contains(std::string data) {
    return this->Contains(data, 0, this->head);
}

int IDList::Contains(std::string data, int pos, Node *node) {
    if (node == nullptr) {
        return -1;
    }
    if (node->data == data) {
        return pos;
    }
    else {
        return Contains(data, pos + 1, node->next);
    }
}

void IDList::Remove(int index) {
    if (index > this->size) {
        return;
    }

    Node* toRemove = this->GetNode(index);

    if (this->head == toRemove) {
        this->head = toRemove->next;
        
        if (this->head != nullptr) {
            this->head->prev = nullptr;
        }

        delete toRemove;
		this->size--;
        return;
    }
    else if (this->tail == toRemove) {
        this->tail = toRemove->prev;
        this->tail->next = nullptr;

        delete toRemove;
	    this->size--;
        return;
    }

    toRemove->prev->next = toRemove->next;
    toRemove->next->prev = toRemove->prev;

    this->size--;
    delete toRemove;
}

std::string IDList::ToString() {
    return this->ToString(this->head);
}

std::string IDList::ToString(Node* node) {
    if (node == nullptr) {
        return "";
    }
    else {
        return node->data  + "\n" + this->ToString(node->next);
    }
}

std::string* IDList::toArray(Node* node, std::string *arr, int pos) {
    if(node == nullptr) {
        return arr;
    } else {
        arr[pos] = node->data;
        return this->toArray(node->next, arr, ++pos);
    }
}

void IDList::makeArray(std::string *arr) {
    this->toArray(this->head, arr, 0);
}