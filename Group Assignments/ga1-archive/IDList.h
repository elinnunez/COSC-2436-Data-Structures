#ifndef IDLIST_H
#define IDLIST_H

#include <string>
#include "Node.h"

class IDList {
private:
    Node* head;
    Node* tail;
    int size;

    Node* GetNode(int index, int pos, Node* node);
    int Contains(std::string data, int pos, Node* node);
    std::string ToString(Node* node);
    std::string* toArray(Node* node, std::string *anarr, int pos);
public:
    IDList();

    Node* GetHead();
    Node* GetTail();
    Node* GetNode(int index);
    int GetLength();
    bool IsEmpty();

    void Add(std::string data);
    int Contains(std::string data);
    
    void Remove(int index);

    std::string ToString(); 
    void makeArray(std::string* arr);
};

#endif