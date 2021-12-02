#ifndef DLL_H
#define DLL_H

#include <iostream>

struct car
{
    car *prev;
    int year;
    car *next;
};

class dll
{
private:
    car *head;
    car *tail;

public:
    dll();
    bool isEmpty();

    void insertAtEnd(int y);
    void insertAtFront(int z);
    void insertAtIndex(int val, int index);

    void rmAtEnd();
    void rmAtFront();
    void rmAtIndex(int index);
    void rmByValue(int val);

    void printDLL();
    void reversePrintDll();

    void getHead();
    void getTail();
    ~dll();
};

dll::dll()
{
    std::cout << "Constructor Called" << std::endl;
    head = tail = nullptr;
}

bool dll::isEmpty()
{
    return head == nullptr;
}

void dll::insertAtEnd(int y)
{
    std::cout << "Adding to end: ";
    car *temp = new car;
    temp->year = y;
    temp->next = nullptr;
    std::cout << temp->year << std::endl;

    if (isEmpty())
    {
        head = temp;
        head->prev = nullptr;
        tail = head;
    }
    else
    {
        car *cur = head;

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        temp->prev = cur;
        cur->next = temp;

        tail = temp;
    }
}

void dll::insertAtFront(int z)
{
    std::cout << "Adding to front: ";
    car *temp = new car;
    temp->year = z;
    temp->prev = nullptr;
    std::cout << temp->year << std::endl;

    if (isEmpty())
    {
        head = temp;
        head->next = nullptr;
        tail = head;
    }
    else
    {

        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void dll::insertAtIndex(int val, int ind)
{
    car *temp = new car;
    temp->year = val;
    if (isEmpty())
    {
        temp->prev = nullptr;
        temp->next = nullptr;
        head = temp;
        tail = head;
    }
    else
    {
        car *cur = head;

        for (int i = 0; i < ind; i++)
        {
            cur = cur->next;
        }

        std::cout << "Adding value: " << temp->year << " to index: " << ind << std::endl;

        temp->prev = cur->prev;
        temp->next = cur;
        cur->prev->next = temp;
        cur->prev = temp;
        cur->next->prev = cur;
    }
}

void dll::rmAtFront()
{
    if (isEmpty())
    {
        std::cout << "List is empty, no front node to remove" << std::endl;
    }
    else
    {
        std::cout << "Removing front/head node: " << head->year << std::endl;
        car *temp = head;
        head = temp->next;
        head->prev = nullptr;
        delete temp;
    }
}

void dll::rmAtEnd()
{
    if (isEmpty())
    {
        std::cout << "List is empty, no end node to remove" << std::endl;
    }
    else
    {
        std::cout << "Removing end/tail node: " << tail->year << std::endl;
        car *temp = tail;
        tail = temp->prev;
        tail->next = nullptr;
        delete temp;
    }
}

void dll::rmAtIndex(int index)
{
    if (isEmpty())
    {
        std::cout << "Empty List, can't remove at index: " << index << std::endl;
    }
    else
    {
        car *cur = head;

        int i = 0;

        while (cur != nullptr && i != index)
        {
            // std::cout << "Cur Val: " << cur->year << " && Index: " << i+1 << std::endl;
            cur = cur->next;
            i += 1;
        }

        if (cur == nullptr && i != index)
        {
            std::cout << "Index is out of bounds" << std::endl;
        }
        else if (cur == nullptr && i == index)
        {
            std::cout << "Index is out of bounds by 1 " << std::endl;
        }
        else
        {
            if (cur == tail)
            {
                std::cout << "Index value: " << cur->year << " at index: " << i << " is the last/tail node" << std::endl;
                std::cout << "Deleting last node" << std::endl;
                car *temp = cur;
                tail = temp->prev;
                tail->next = nullptr;
                delete temp;
            }
            else
            {
                std::cout << "Need to delete value: " << cur->year << " at index: " << i << std::endl;
                car *temp = cur;
                cur->prev->next = temp->next;
                cur->next->prev = temp->prev;
                delete temp;
            }
        }
    }
}

void dll::rmByValue(int year)
{
    if (isEmpty())
    {
        std::cout << "DLL is empty, nothing to remove" << std::endl;
    }
    else
    {
        car *cur = head;

        while (cur != nullptr)
        {
            if (cur->year == year)
            {
                break;
            }
            cur = cur->next;
        }

        if (cur == head && cur->year == head->year)
        {
            std::cout << "Removing front/head node by value: " << cur->year << std::endl;
            car *temp = cur;
            head = temp->next;
            head->prev = nullptr;
            delete temp;
        }
        else if (cur == nullptr)
        {
            std::cout << "Value " << year << " is not in the list" << std::endl;
        }
        else if (cur == tail && cur->year == tail->year)
        {
            std::cout << "Removing end/tail node by value: " << cur->year << std::endl;
            car *temp = cur;
            tail = cur->prev;
            tail->next = nullptr;
            delete temp;
        }
        else
        {
            std::cout << "Deleting node value: " << cur->year << " == " << year << std::endl;

            car *temp = cur;
            cur->prev->next = temp->next;
            // cur->next = temp->next;
            cur->next->prev = temp->prev;

            delete temp;
        }
    }
}

void dll::printDLL()
{
    std::cout << "Print DLL frontwards from Head" << std::endl;
    car *cur = head;

    while (cur != nullptr)
    {
        std::cout << cur->year << " ";
        cur = cur->next;
    }

    std::cout << std::endl;
}

void dll::reversePrintDll()
{
    std::cout << "Printing DLL backwards from Tail" << std::endl;
    car *cur = tail;

    while (cur != nullptr)
    {
        std::cout << cur->year << " ";
        cur = cur->prev;
    }

    std::cout << std::endl;
}

void dll::getHead()
{
    std::cout << "Head is: " << head->year << std::endl;
}

void dll::getTail()
{
    std::cout << "Tail is: " << tail->year << std::endl;
}

dll::~dll()
{
    std::cout << "Destructor Called" << std::endl;

    car *temp = new car;

    while (head != nullptr)
    {
        temp = head;
        std::cout << "Deleting " << head->year << std::endl;
        head = temp->next;
        delete temp;
    }
}

#endif // !DLL_H