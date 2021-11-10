#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include "functions.h"

class DoublyLL
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    //Default Constructor
    DoublyLL(); //done

    //getter functions
    bool isEmpty(); //done
    int getSize();  //done

    //insert node functions
    void addFront(std::string type, std::string eq);                  //done
    void addEnd(std::string type, std::string eq);                    //done
    void addAtPos(std::string com, std::string type, std::string eq); //done

    //*************************************
    // default remove node functions
    void deleteFront();                //done
    void deleteEnd();                  //done //might not need for removeatpos com
    void deleteAtPos(std::string pos); //done
    void deleteAll();                  //done
    //other remove node functions
    void deletePostFix();                //done althought need edgecase when both deletePostFix and deletePrefix called after each other
    void deletePreFix();                 //done
    void removeComList(std::string com); //done
    //**************************

    //convert list functions
    void convert2Post(); //done
    void convert2Pre(); //done
    void convertPos(std::string pos); //done
    void convertAll(); //done
    void convertComList(string com); //done

    //outfile list functions;
    void printList(std::ostream *file); //done
    void printRevList(std::ostream *file); //done

    //display functions
    void display();    //done
    void displayRev(); //done

    //random functions
    void showHT(); //done
    Node* returnHead(); //done

    //destructor
    ~DoublyLL(); //done
};

DoublyLL::DoublyLL()
{
    head = tail = nullptr;
    size = 0;
}

bool DoublyLL::isEmpty()
{
    return head == nullptr;
}

int DoublyLL::getSize()
{
    return size;
}

void DoublyLL::addFront(std::string type, std::string eq)
{
    Node *temp = new Node;
    temp->type = type;
    temp->equation = eq;
    temp->prev = nullptr;
    size++;
    if (isEmpty())
    {
        temp->next = nullptr;
        head = temp;
        tail = head;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void DoublyLL::addEnd(std::string type, std::string eq)
{
    Node *temp = new Node;
    temp->type = type;
    temp->equation = eq;
    temp->next = nullptr;
    size++;
    if (isEmpty())
    {
        temp->prev = nullptr;
        head = temp;
        tail = head;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void DoublyLL::addAtPos(std::string com, std::string type, std::string eq)
{
    if (stoi(com) <= 0)
    {
        addFront(type, eq);
    }
    else if (stoi(com) >= size)
    {
        addEnd(type, eq);
    }
    else
    {
        Node *cur = head;

        Node *temp = new Node;
        temp->type = type;
        temp->equation = eq;
        int i = 0;

        while (i != stoi(com))
        {
            cur = cur->next;
            i++;
        }

        temp->next = cur;
        temp->prev = cur->prev;
        temp->prev->next = temp;
        temp->next->prev = temp;

        size++;
    }
}

void DoublyLL::deleteFront()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node *temp = head;
        head = temp->next;
        head->prev = nullptr;

        delete temp;
        size--;
    }
}

void DoublyLL::deleteEnd()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node *temp = tail;
        tail = temp->prev;
        tail->next = nullptr;

        delete temp;
        size--;
    }
}

void DoublyLL::deleteAtPos(string pos)
{
    if (isEmpty() || stoi(pos) >= size)
    {
        return;
    }
    else if (stoi(pos) <= 0)
    {
        deleteFront();
    }
    else
    {
        Node *cur = head;
        int i = 0;
        while (i != stoi(pos))
        {
            cur = cur->next;
            i++;
        }

        if (cur == tail)
        {
            deleteEnd();
        }
        else
        {
            Node *temp = cur;
            cur->prev->next = temp->next;
            cur->next->prev = temp->prev;

            size--;
            delete temp;
        }
    }
}

void DoublyLL::deleteAll()
{
    while (head != nullptr)
    {
        Node *temp = head;
        // std::cout << "Deleting: " << temp->type << " | " << temp->equation << std::endl;
        head = temp->next;
        size--;
        delete temp;
    }
}

void DoublyLL::deletePostFix()
{
    if (!isEmpty())
    {

        Node *cur1 = head;
        bool isAllSame = true;

        while (cur1 != nullptr)
        {
            if (cur1->type != "postfix")
            {
                isAllSame = false;
                break;
            }
            cur1 = cur1->next;
        }

        if (isAllSame == true)
        {
            deleteAll();
        }
        else
        {

            Node *cur = head;

            while (cur != nullptr)
            {
                if (cur->type == "postfix")
                {
                    Node *temp = cur;

                    if (cur == head)
                    {
                        head = cur->next;
                        head->prev = nullptr;
                    }
                    else if (cur == tail)
                    {
                        tail = cur->prev;
                        tail->next = nullptr;
                    }
                    else
                    {
                        cur->prev->next = temp->next;
                        cur->next->prev = temp->prev;
                        
                    }
                    size--;
                    delete temp;
                }
                cur = cur->next;
            }
        }
    }
}

void DoublyLL::deletePreFix()
{

    if (isEmpty())
    {
    }
    else
    {
        Node *cur = head;
        bool isAllSame = true;

        while (cur != nullptr)
        {
            if (cur->type != "prefix")
            {
                isAllSame = false;
                break;
            }
            cur = cur->next;
        }

        if (isAllSame == true)
        {
            deleteAll();
        }
        else
        {
            Node *cur = head;

            while (cur != nullptr)
            {
                if (cur->type == "prefix")
                {
                    Node *temp = cur;

                    if (cur == head)
                    {
                        head = cur->next;
                        head->prev = nullptr;
                    }
                    else if (cur == tail)
                    {
                        tail = cur->prev;
                        tail->next = nullptr;
                    }
                    else
                    {
                        cur->prev->next = temp->next;
                        cur->next->prev = temp->prev;
                        
                    }
                    size--;

                    delete temp;
                }
                cur = cur->next;
            }
        }
    }
}

void DoublyLL::removeComList(std::string com)
{
    if (com == "all")
    {
        deleteAll();
    }
    else if (com == "postfix")
    {
        deletePostFix();
    }
    else if (com == "prefix")
    {
        deletePreFix();
    }
    else
    {
        deleteAtPos(com);
    }
}

void DoublyLL::convert2Post() {
    if(isEmpty()) {
        std::cout << "Empty" << std::endl;
        return;
    } else {
        Node* cur = head;

        while(cur != nullptr) {
            if(cur->type == "prefix") {
                cur->type = "postfix";
                string eq = pre2Post(cur->equation);
                cur->equation = eq;
            }
            cur = cur->next;
        }
    }
}

void DoublyLL::convert2Pre() {
    if(isEmpty()) {
        std::cout << "Empty" << std::endl;
        return;
    } else {
        Node* cur = head;

        while(cur != nullptr) {
            if(cur->type == "postfix") {
                cur->type = "prefix";
                string eq = post2Pre(cur->equation);
                cur->equation = eq;
            }
            cur = cur->next;
        }
    }
}

void DoublyLL::convertAll() {
    if(isEmpty()) {
        std::cout << "Empty" << std::endl;
        return;
    } else {
        Node* cur = head;

        while(cur != nullptr) {
            if(cur->type == "prefix") {
                cur->type = "postfix";
                string eq = pre2Post(cur->equation);
                cur->equation = eq;
            } else {
                cur->type = "prefix";
                string eq = post2Pre(cur->equation);
                cur->equation = eq;
            }
            cur = cur->next;
        }
    }
}

void DoublyLL::convertPos(std::string pos) {
    if(isEmpty() || stoi(pos) >= size) {
        return;
    } else {
        if(stoi(pos) <= 0) {
            string eq;
            if(head->type == "prefix") {
                head->type = "postfix";
                eq = pre2Post(head->equation);
                head->equation = eq;
            } else {
                head->type = "prefix";
                eq = post2Pre(head->equation);
                head->equation = eq;
            }
        } else {
            Node* cur = head;
            int i = 0;
            string eq;

            while(i != stoi(pos)) {
                cur = cur->next;
                i++;
            }

            if(cur->type == "prefix") {
                cur->type = "postfix";
                eq = pre2Post(cur->equation);
                cur->equation = eq;
            } else {
                cur->type = "prefix";
                eq = post2Pre(cur->equation);
                cur->equation = eq;
            }
        }
    }
}

void DoublyLL::convertComList(std::string com) {
    if(com == "all") {
        convertAll();
    } else if (com == "prefix") {
        convert2Post();
    } else if (com == "postfix") {
        convert2Pre();
    } else {
        convertPos(com);
    }
}

void DoublyLL::printList(ostream* outfile) {
    *outfile << "List:" << std::endl;
    if(isEmpty()) {
        *outfile << "EMPTY" << std::endl;
    } else {
        Node* cur = head;

        while(cur != nullptr) {
            *outfile << cur->type << ":" << cur->equation << std::endl;
            cur = cur->next;
        }
    }
    *outfile << std::endl;
}

void DoublyLL::printRevList(ostream* outfile) {
    *outfile << "Reversed List:" << std::endl;
    if(isEmpty()) {
        *outfile << "EMPTY" << std::endl;
    } else {
        Node* cur = tail;

        while(cur != nullptr) {
            *outfile << cur->type << ":" << cur->equation << std::endl;
            cur = cur->prev;
        }
    }
    *outfile << std::endl;
}

void DoublyLL::display()
{
    if (isEmpty())
    {
        std::cout << "Empty List" << std::endl;
        std::cout << "Size: " << size << std::endl;
    }
    else
    {
        Node *cur = head;
        std::cout << "List" << endl;
        while (cur != nullptr)
        {
            std::cout << cur->type << " | " << cur->equation << std::endl;
            cur = cur->next;
        }
        std::cout << "Size: " << size << std::endl;
        cout << endl;
    }
}

void DoublyLL::displayRev()
{
    if (isEmpty())
    {
        std::cout << "Empty Rev List" << std::endl;
        std::cout << "Size: " << size << std::endl;
    }
    else
    {
        Node *cur = tail;
        std::cout << "Reversed List" << std::endl;
        while (cur != nullptr)
        {
            std::cout << cur->type << ":" << cur->equation << std::endl;
            cur = cur->prev;
        }
        std::cout << "Size: " << size << std::endl;
        cout << endl;
    }
}

void DoublyLL::showHT()
{
    if (isEmpty())
    {
        std::cout << "No HT" << std::endl;
    }
    else
    {
        std::cout << "Head: " << head->type << " | " << head->equation << std::endl;
        std::cout << "Tail: " << tail->type << " | " << tail->equation << std::endl;
    }
}

Node* DoublyLL::returnHead() {
    return head;
}

DoublyLL::~DoublyLL() {
    std::cout << "Destructor Called" << std::endl;

    while(head != nullptr) {
        Node* temp = head;
        
        head = temp->next;
        delete temp;
    }
}

#endif