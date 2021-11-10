#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <fstream>

struct node
{
    string line;
    node *next;
    int slen;
};

class link
{
private:
    node *head;
    node *tail;
    int size;

public:
    link();

    bool isEmpty();

    bool isDup(string s);

    //list appending
    void byEnd(string s);
    void byBeginning(string s);

    //list ordering
    void byAlphabet();
    void LengthSwap();

    //might not need
    void byLength(string s);

    //command functions;
    void addAtLocation(int l, string s, int *c);

    void removeAtStr(string str, int *size);

    void printList();

    void outfile(ostream *outfile);

    //size of the strings
    void printSList();
};

link::link()
{
    head = tail = nullptr;
}

bool link::isEmpty()
{
    return head == nullptr;
}

bool link::isDup(string s)
{
    node *cur = head;

    if (isEmpty())
    {
        return false;
    }
    else
    {
        while (cur != nullptr)
        {
            if (cur->line == s)
            {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
}

void link::byBeginning(string s)
{
    node *temp = new node;
    temp->line = s;
    temp->slen = s.length();
    temp->next = nullptr;

    if (isEmpty())
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}

void link::byEnd(string s)
{
    node *temp = new node;
    temp->line = s;
    temp->slen = s.length();
    temp->next = nullptr;

    if (isEmpty())
    {
        head = tail = temp;
    }
    else
    {
        // isDup(temp->line)
        tail->next = temp;
        tail = temp;
    }
}

void link::LengthSwap()
{
    node *cur = head;
    while (cur)
    {
        node *min = cur;
        node *r = cur->next;

        // Traverse the unsorted sublist
        while (r)
        {
            if (min->slen > r->slen)
                min = r;

            r = r->next;
        }

        // Swap Data
        int x = cur->slen;
        string y = cur->line;
        cur->slen = min->slen;
        cur->line = min->line;
        min->slen = x;
        min->line = y;
        cur = cur->next;
    }
}

void link::byAlphabet()
{
    node *cur = head;
    while (cur)
    {
        node *min = cur;
        node *r = cur->next;

        // Traverse the unsorted sublist
        while (r)
        {
            if (min->line > r->line)
                min = r;

            r = r->next;
        }

        // Swap Data
        int x = cur->slen;
        string y = cur->line;
        cur->slen = min->slen;
        cur->line = min->line;
        min->slen = x;
        min->line = y;
        cur = cur->next;
    }
}

void link::byLength(string s)
{
    node *temp = new node;
    temp->line = s;
    temp->slen = s.length();
    temp->next = nullptr;
    node *cur = head;
    node *prev = cur;

    if (isEmpty())
    {
        head = tail = temp;
    }
    else
    {

        temp->next = head;
        head = temp;
    }
}

void link::addAtLocation(int p, string s, int *size)
{
    *size = 0;

    node *cur = head;

    while(cur != nullptr) {
        *size+=1;
        cur = cur->next;
    }

    if (p > *size)
    {
        cout << "Can't add because index chosen is larger than the list" << endl;
    }
    else
    {
        node *temp = new node;
        temp->line = s;
        temp->slen = s.length();
        temp->next = nullptr;

        node *cur = head;
        for (int i = 1; i < p; i++)
        {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;

        *size += 1;
    }
}

void link::removeAtStr(string str, int *size)
{

    node *cur = head;

    if (isEmpty())
    {
        cout << "Empty" << endl;
        return;
    }
    else
    {

        if (cur->line.find(str) != string::npos && cur == head)
        {
            head = cur->next;
            // *size -= 1;
            delete cur;
        }

        /* Delete All occurrences of the given key from the beginning, and adjust head accordingly */
        while (cur != nullptr && cur->line.find(str) != string::npos)
            cur = cur->next;
            *size -= 1;

        // /* Now, delete remaining occurrences of the key from the linked list by storing the previous
        // node and pointing it to desired location accordingly */
        node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->next->line.find(str) != string::npos)
            {
                cout << "REMOVED: " << temp->next->line << endl;
                node *p = temp->next;
                temp->next = temp->next->next;
                *size -= 1;
                delete p;
            }
            else
            {
                temp = temp->next;
            }
        }
        if (temp->next == nullptr && temp->line.find(str) != string::npos && temp == head)
        {
            head = nullptr;
            size-=1;
        }
        else
        {
            temp->next = nullptr;
            tail = temp;
            // cout << "TAIL LINE: " << tail->line << endl;
        }

        //trying different things
        // while(cur != nullptr) {
        //     if(cur->line.find(str) != string::npos) {
        //         cout << "Needs Removal: " << cur->line << endl;
        //     }
        //     cur = cur->next;
        // }
    }
}

void link::printList()
{
    node *cur = head;
    int i = 0;
    if (isEmpty())
    {
        cout << "Cannot print an empty list" << endl;
    }
    else
    {
        cout << "Printing List" << endl;
        while (cur != nullptr)
        {

            cout << " Index: " << i << "- Size: " << cur->slen << "- " << cur->line << " " << endl;
            cur = cur->next;
            i += 1;
        }
    }
}

//extra

void link::printSList()
{
    node *cur = head;
    int i = 0;
    if (isEmpty())
    {
        cout << "Cannot print an empty list" << endl;
    }
    else
    {
        cout << "Printing List" << endl;
        while (cur != nullptr)
        {

            cout << i << ": " << cur->slen << " " << endl;
            cur = cur->next;
            i += 1;
        }
    }
}

void link::outfile(ostream *outfile) {
    node *cur = head;
    while(cur != nullptr) {
        *outfile << cur->line << endl;
        cur = cur->next;
    }
}

#endif // !LIST_H