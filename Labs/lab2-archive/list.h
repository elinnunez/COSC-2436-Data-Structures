#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Node
{
    string name;
    int score;
    Node *next;
};

class linked
{
private:
    Node *head;
    void swap(Node *cur, Node *next);

public:
    linked();
    bool isEmpty();
    void addNode(string n, int s);
    void sortList();
    void printList();
    void sendOutput(ofstream &outfile);
    ~linked();
};

linked::linked()
{
    head = nullptr;
}

bool linked::isEmpty()
{
    return head == nullptr;
}

void linked::addNode(string n, int s)
{
    Node *temp = new Node;
    temp->name = n;
    temp->score = s;
    temp->next = nullptr;
    if (isEmpty())
    {
        head = temp;
    }
    else
    {
        Node *cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = temp;
    }
}

// void linked::swap(Node* cur, Node* next) {
//     Node *temp = cur;

//     cur->name = next->name;
//     cur->score = next->score;

//     next->name = temp->name;
//     next->score = temp->score;

//     // delete temp;
// }

void linked::sortList()
{
    Node *cur = head;
    while (cur)
    {
        Node *max = cur;
        Node *r = cur->next;

        // Traverse the unsorted sublist
        while (r)
        {
            if (max->score < r->score)
                max = r;

            r = r->next;
        }

        // Swap Data
        int x = cur->score;
        string y = cur->name;
        cur->score = max->score;
        cur->name = max->name;
        max->score = x;
        max->name = y;
        cur = cur->next;
    }
}

void linked::printList()
{
    Node *cur = head;

    while (cur != nullptr)
    {
        cout << cur->name << "," << cur->score << endl;
        cur = cur->next;
    }
}

void linked::sendOutput(ofstream &outfile)
{

    if (isEmpty())
    {
        outfile << "No valid data in input" << endl;
    }
    else
    {
        Node *cur = head;
        while (cur != nullptr)
        {
            outfile << cur->name << "," << cur->score << endl;
            cur = cur->next;
        }
    }
}

linked::~linked()
{
    cout << "Destructor Called" << endl;

    Node *p = head; //this is head
    while (p)
    {
        Node *temp = p;
        p = p->next;
        cout << "Deleting Node: " << temp->name << endl;
        delete temp;
    }
}
#endif // !LIST_H
