#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

struct Node
{
    char c;
    Node *next;
};

class link
{
private:
    Node *head;
    Node *tail;

public:
    link();
    link(char c);
    bool isEmpty();
    void addFront(char c);
    // void addAt();
    void addLast(char c);
    void rmFront();
    // void rmAt(char c);
    void rmLast();
    void rmEveryOther();
    int loopCount();
    void printList();
    ~link();
};

link::link()
{
    cout << "Default Constructor Called" << endl;
    head = tail = nullptr;
}

link::link(char c)
{
    head = new Node;
    head->c = c;
    head->next = head;
    tail = head;
    // tail->next = head;
}

bool link::isEmpty()
{
    if (head == nullptr && tail == nullptr)
    {
        // cout << "True" << endl;
        return true;
    }
    else
    {
        // cout << "False" << endl;
        return false;
    }
}

void link::addFront(char c)
{
    Node *temp = new Node;
    temp->c = c;
    temp->next = head;

    if (isEmpty())
    {
        // cout << "List was empty so node is now head" << endl;
        head = temp;
        // head->next = head;
        tail = head;
        // delete temp;
    }
    else
    {
        cout << "List is not empty, now node is at the front" << endl;
        head = temp;
        tail->next = head;
        // delete temp;
    }
}

void link::rmFront()
{
    if (isEmpty())
    {
        cout << "Empty list, can't remove front" << endl;
    }
    else
    {
        Node *old = head;

        cout << "Removing head value: " << old->c << endl;

        head = old->next;
        tail->next = head;
        delete old;
    }
}

void link::addLast(char c)
{
    Node *temp = new Node;
    temp->c = c;

    if (isEmpty())
    {
        // cout << "List is empty, so end node is head" << endl;
        head = temp;
        head->next = head;
        tail = head;
    }
    else
    {
        Node *cur = head;

        while (cur->next != head)
        {
            cur = cur->next;
        }

        temp->next = head;
        tail = temp;
        cur->next = temp;
    }
}

void link::rmLast()
{
    if (isEmpty())
    {
        cout << "List is empty, can't remove a last node" << endl;
    }
    else
    {
        Node *cur = head;
        Node *prev = cur;

        while (cur->next != head)
        {
            prev = cur;
            cur = cur->next;
        }

        prev->next = head;
        delete cur;
        cur = prev;
        tail = cur;
    }
}

void link::rmEveryOther()
{
    if (isEmpty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        Node *prev = head;
        Node *cur = head->next;
        int count = 0;

        do
        {
            prev->next = cur->next;
            delete cur;

            prev = prev->next;
            if (prev != head)
            {
                cur = prev->next;
            }

        } while (prev != head && cur != head);

        Node *loop = head;

        while (loop->next != head)
        {
            loop = loop->next;
        }

        tail = loop;

        // cout << "Head: " << head->c << endl;
        // cout << "Tail: " << tail->c << endl;
    }
}

int link::loopCount()
{
    int count = 0;
    if (isEmpty())
    {
        cout << "Can't count loops of an empty list" << endl;
        cout << "Count: " << count << endl;
    }
    else
    {
        while (head != tail)
        {
            rmEveryOther();
            count += 1;
        }
        // cout << "Count: " << count << endl;
        return count;
    }
}

void link::printList()
{
    Node *cur = head;
    if (isEmpty())
    {
        cout << "Can't print empty list" << endl;
    }
    else
    {
        do
        {
            cout << cur->c << endl;
            cur = cur->next;
        } while (cur != head);
    }

    // cout << "Tail: " << tail->c << endl;
}

link::~link()
{
    cout << "Destructor Called" << endl;

    Node *p = tail->next; //this is head
    tail->next = nullptr;
    while (p)
    {
        Node *temp = p;
        p = p->next;
        cout << "Deleting Node: " << temp->c << endl;
        delete temp;
    }
}

#endif // !LIST_H