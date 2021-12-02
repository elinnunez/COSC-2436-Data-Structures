#include <iostream>

using namespace std;

struct letter
{
    char l;
    letter *next;
};

class lht
{
private:
    letter *head;
    letter *tail;

public:
    lht();
    bool isEmpty();
    void insertAtBeg(char b);
    void insertAtEnd(char e);
    void insertAtIndex(int pos, char c);
    void insertAtChar(char c, char p);
    bool deleteAtBeg(char &key);
    bool deleteAtEnd();
    void deleteAtIndex(int i);
    void deleteAtChar(char c);
    void printList();
};

lht::lht()
{
    head = tail = nullptr;
}

bool lht::isEmpty()
{
    return head == nullptr;
}

void lht::insertAtBeg(char b)
{
    letter *temp = new letter;
    temp->l = b;
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

void lht::insertAtEnd(char e)
{
    letter *temp = new letter;
    temp->l = e;
    temp->next = nullptr;

    if (isEmpty())
    {
        head = tail = temp;
    }
    else
    {
        // letter *cur = tail;
        // while(cur != nullptr) {
        //     cur = cur->next;
        // }
        // cur->next = temp;
        tail->next = temp;
        tail = temp;
    }
}

void lht::insertAtIndex(int position, char c)
{
    letter *temp = new letter;
    temp->l = c;
    temp->next = nullptr;

    letter *cur = head;
    for (int i = 1; i < position - 1; i++)
    {
        cur = cur->next;
    }
    temp->next = cur->next;
    cur->next = temp;
}

void lht::insertAtChar(char c, char p)
{
    letter *temp = new letter;
    temp->l = p;
    temp->next = nullptr;

    letter *cur = head;

    while (cur->l != c)
    {
        cur = cur->next;
    }

    // if(cur->next == tail) {
    //     insertAtEnd(c);
    // } else {
    temp->next = cur->next;
    cur->next = temp;
    // }
}

bool lht::deleteAtBeg(char &key)
{

    if (isEmpty())
    {
        cout << "Cannot delete at beginning because list is empty" << endl;
        return false;
    }
    else
    {
        letter *temp = head;
        key = temp->l;
        head = head->next;

        delete temp;

        cout << "Deleting beginning node" << endl;

        return true;
    }
}

bool lht::deleteAtEnd()
{
    //fix infinite loop when delete head node
    if (isEmpty())
    {
        cout << "Cannot delete at end because list is empty" << endl;
        return false;
    }
    else
    {
        letter *cur = head;
        letter *prev = head;
        // prev->next = nullptr;

        while (cur->next != nullptr)
        {
            prev = cur;
            cur = cur->next;
        }

        if (cur == head)
        {
            head = nullptr;
        }
        else
        {
            prev->next = nullptr;
            tail = prev;
        }

        delete cur;

        cout << "Deleting last node" << endl;
        return true;
    }
}

void lht::deleteAtIndex(int index)
{
    cout << "Deleting at 0 based index: " << index << endl;

    if (isEmpty())
    {
        cout << "Can't delete at index because list is empty" << endl;
        return;
    }
    else
    {

        letter *cur = head;
        letter *prev = head;

        if (index == 0)
        {
            head = cur->next;
            delete cur;
        }
        else
        {
            // cout << "Cur head->l value in deleteAtIndex: " << cur->l << endl;
            for (int i = 0; i < index; i++)
            {
                prev = cur;
                cur = cur->next;
                if(cur == nullptr && i != index-1) {
                    break;
                }
            }
            if (cur == nullptr)
            {
                cout << "Chosen index is out of bounds" << endl;
            }
            else
            {
                letter *temp = cur->next;
                prev->next = cur->next;
                // cur->next = temp->next;
                cur = prev;
                // delete temp;
            }
        }
    }
}

void lht::deleteAtChar(char c) {

    if (isEmpty())
    {
        cout << "Can't delete at character because list is empty" << endl;
        return;
    }
    else
    {

        letter *cur = head;
        letter *prev = head;

        if (cur->l == c)
        {
            head = cur->next;
            delete cur;
        }
        else
        {
            // cout << "Cur head->l value in deleteAtIndex: " << cur->l << endl;
            while(cur->l != c && cur->next != nullptr) {
                // cout << "cur->next->l: " << cur->l << endl;
                prev = cur;
                cur = cur->next;
            }
            // cout << "tail->l: " << tail->l  << endl;
            // cout << "prev->l out of loop: " << prev->l << endl;
            // cout << "cur->l out of loop: " << cur->l << endl;
            
            if (cur->l == c && cur->next == nullptr)
            {
                deleteAtEnd();
            } else if (cur->l != c) {
                cout << "Character " << c << " wasn't found in the list" << endl;
            }
            else {
                cout << "Deleting character " << c << " from the list" << endl;
                letter *temp = cur->next;
                // cout << "temp->l: " << temp->l << endl;
                prev->next = cur->next;
                // cout << "prev->next->l: " << prev->next->l << endl;
                cur = prev;
                // cout << "cur->next->l: " << cur->next->l << endl;
            }
        }
    }

}

void lht::printList()
{
    letter *cur = head;
    if (isEmpty())
    {
        cout << "Cannot print an empty list" << endl;
    }
    else
    {
        cout << "Printing List" << endl;
        while (cur != nullptr)
        {
            cout << cur->l << " " << endl;
            cur = cur->next;
        }
    }
}