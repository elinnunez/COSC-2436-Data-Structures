#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <fstream>
#include "functions.h"
#include "node.h"
#include "dll.h"

class Stack
{
private:
    Node *top;
    int size;

public:
    Stack();
    bool isEmpty(); //done
    void push(std::string type, std::string eq); //done
    void pop(); //done
    Node *peek(); //done
    void display(); //done

    //functions that interact with list
    void getPost(Node *head); //done
    void getPre(Node *head);  //done
    void getAll(Node *head);  //done
    void getPos(Node *head, std::string com, int listsize); //done
    void pushComReserve(Node* head, std::string com, int size); //done

    //converting functions
    void convertReserve();

    //outfile functions
    void printReserveTop(ostream* outfile); //done

    //other functions
    int getSize(); //done

    //destructor
    // ~Stack(); //done
};

Stack::Stack()
{
    top = nullptr;
    size = 0;
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::push(std::string t, std::string eq)
{
    Node *temp = new Node;
    temp->type = t;
    temp->equation = eq;
    temp->next = top;
    top = temp;
    size++;
}

void Stack::pop()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node *temp = top;
        top = temp->next;
        delete temp;
        size--;
    }
}

Node *Stack::peek()
{
    return top;
}

void Stack::display()
{
    if (isEmpty())
    {
        std::cout << "Empty Stack" << std::endl;
    }
    else
    {
        Node *cur = top;
        while (cur != nullptr)
        {
            std::cout << cur->type << " | " << cur->equation << endl;
            cur = cur->next;
        }
    }
}

void Stack::getPost(Node *head)
{
    Node *cur = head;

    while (cur != nullptr)
    {
        if (cur->type == "postfix")
        {
            push(cur->type, cur->equation);
        }
        cur = cur->next;
    }
}

void Stack::getPre(Node *head)
{
    Node *cur = head;

    while (cur != nullptr)
    {
        if (cur->type == "prefix")
        {
            push(cur->type, cur->equation);
        }
        cur = cur->next;
    }
}

void Stack::getAll(Node *head)
{
    Node *cur = head;

    while (cur != nullptr)
    {
        push(cur->type, cur->equation);
        cur = cur->next;
    }
}

void Stack::getPos(Node *head, std::string pos, int listsize)
{
    Node *cur = head;

    if (stoi(pos) <= 0)
    {
        push(cur->type, cur->equation);
    }
    else if (stoi(pos) >= listsize)
    {
        //do nothing
    }
    else
    {
        int i = 0;

        while (i != stoi(pos))
        {
            cur = cur->next;
            i++;
        }

        push(cur->type, cur->equation);
    }
}

void Stack::pushComReserve(Node* head, std::string com, int size){
    if(com == "all") {
        getAll(head);
    } else if (com == "postfix") {
        getPost(head);
    } else if (com == "prefix") {
        getPre(head);
    } else {
        getPos(head, com, size);
    }
}

void Stack::convertReserve() {
    if(isEmpty()) {
        return;
    } else {
        std::string eq;
        if(top->type == "prefix") {
            top->type = "postfix";
            eq = pre2Post(top->equation);
            top->equation = eq;
        } else {
            top->type = "prefix";
            eq = post2Pre(top->equation);
            top->equation = eq;
        }
    }
}

void Stack::printReserveTop(ostream* outfile) {
    if(isEmpty()) {
        *outfile << "Top of Reserve: EMPTY" << std::endl;
    } else {
        *outfile << "Top of Reserve: " << top->type << ":" << top->equation << std::endl;
    }
    *outfile << std::endl;
}

int Stack::getSize() {
    return size;
}

// Stack::~Stack() {
//     std::cout << "Destructor Called" << std::endl;

//     while(top != nullptr) {
//         Node* temp = top;
        
//         top = temp->next;
//         delete temp;
//     }
// }

#endif