#ifndef LIST_H
#define LIST_H

#include <iostream>

struct Node
{
    int val;
    Node *next;
};

class list
{
private:
    Node *head;
    Node *tail;
    void recPrintEven(Node *cur);
    void recPrintOdd(Node *cur);

public:
    list();
    bool isEmpty();
    void addAtEnd(int num);
    // void addAtFront();
    void printList();

    void printEven();
    void printOdd();

    void deleteOdd();
    void deleteEven();

    void recPrintEvenPub();
    void recPrintOddPub();

    void getHead();
    void getTail();
    ~list();
};

list::list()
{
    head = tail = nullptr;
}

bool list::isEmpty()
{
    return head == nullptr && tail == nullptr;
}

void list::addAtEnd(int num)
{
    Node *temp = new Node;
    temp->val = num;
    temp->next = nullptr;

    if (isEmpty())
    {
        // std::cout << "Empty List" << std::endl;
        head = temp;
        tail = head;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void list::printEven()
{
    if (isEmpty())
    {
        std::cout << "Empty List" << std::endl;
    }
    else
    {
        Node *cur = head;
        int index = 0;
        while (cur != nullptr)
        {
            if (cur->val % 2 == 0)
            {
                std::cout << cur->val << " at Index: " << index << std::endl;
            }
            cur = cur->next;
            index += 1;
        }
    }
}

void list::deleteEven()
{
    if (isEmpty())
    {
        std::cout << "Empty List" << std::endl;
    }
    else
    {
        // Node *cur = head;
        // Node *prev = head;
        // int i = 0;
        // while (cur != nullptr)
        // {
        //     if (cur->val % 2 == 1 && i == 0)
        //     {
        //         head = cur;
        //         prev = head;
        //         i += 1;
        //     } else if(cur->val % 2 == 1) {
        //         prev = cur;
        //     }
        //     if (cur->val % 2 == 0 && cur == head)
        //     {
        //         Node* temp = cur;
        //         head = temp->next;
        //         // delete temp;
        //     } else if(cur->val %2 == 0) {
        //         prev->next = cur->next;
        //     }
        //     cur = prev->next;
        // }

        // if(head == prev) {
        //     std::cout << "Empty" << std::endl;
        // }
        // tail = prev;
        // tail->next = nullptr;

        Node* cur = head;
        Node* last_odd;

        while(cur != nullptr && cur->val % 2 != 1) {
            cur = cur->next;
        }

        head = cur;

        if(cur == nullptr) {
            std::cout << "Only even numbers in list that will all be deleted" << std::endl;
            tail = nullptr;
            return;
        }

        last_odd = cur;

        Node* temp = cur;

        cur = temp->next;

        while(cur != nullptr) {
            if(cur->val %2 == 1) {
                last_odd->next = cur;
                last_odd = cur;
            }
            cur = cur->next;
        }

        last_odd->next = nullptr;
        tail = last_odd;
    }
}

    void list::printOdd()
    {
        if (isEmpty())
        {
            std::cout << "Empty List" << std::endl;
        }
        else
        {
            Node *cur = head;
            int index = 0;
            while (cur != nullptr)
            {
                if (cur->val % 2 == 1)
                {
                    std::cout << cur->val << " at Index: " << index << std::endl;
                }
                cur = cur->next;
                index += 1;
            }
        }
    }

    void list::deleteOdd()
{
    if (isEmpty())
    {
        std::cout << "Empty List" << std::endl;
    }
    else
    {
        // Node *cur = head;
        // Node *prev;
        // int i = 0;
        // while (cur != nullptr)
        // {
        //     if (cur->val % 2 == 0 && i == 0)
        //     {
        //         head = cur;
        //         prev = head;
        //         i += 1;
        //     } else if(cur->val % 2 == 0) {
        //         prev = cur;
        //     }
        //     if (cur->val % 2 == 1 && cur == head)
        //     {
        //         Node* temp = cur;
        //         head = temp->next;
        //         // delete temp;
        //     } else if(cur->val %2 == 1) {
        //         prev->next = cur->next;
        //     }
        //     cur = prev->next;
        // }

        // if(head == prev) {
        //     std::cout << "Empty" << std::endl;
        // }
        // tail = prev;
        // tail->next = nullptr;

        Node* cur = head;
        Node* last_even;

        while(cur != nullptr && cur->val % 2 != 0) {
            cur = cur->next;
        }

        head = cur;

        if(cur == nullptr) {
            std::cout << "Only odd numbers in list that will all be deleted" << std::endl;
            tail = nullptr;
            return;
        }

        last_even = cur;

        Node* temp = cur;

        cur = temp->next;

        while(cur != nullptr) {
            if(cur->val %2 == 0) {
                last_even->next = cur;
                last_even = cur;
            }
            cur = cur->next;
        }

        last_even->next = nullptr;
        tail = last_even;
    }
}

    void list::recPrintEven(Node* cur)
    {
        if (isEmpty())
        {
            std::cout << "Empty List" << std::endl;
        }
        else
        {
            // cur = head;
            if (cur->next == nullptr)
            {
                if (cur->val % 2 == 0)
                {
                    std::cout << cur->val << std::endl;
                } else {
                    std::cout << "List with no evens" << std::endl;
                }
            }
            else
            {
                if (cur->val % 2 == 0)
                {
                    std::cout << cur->val << std::endl;
                }
                recPrintEven(cur->next);
            }
        }
    }

    void list::recPrintOdd(Node* cur)
    {
        if (isEmpty())
        {
            std::cout << "Empty LIst" << std::endl;
        }
        else
        {
            // cur = head;
            if (cur->next == nullptr)
            {
                if (cur->val % 2 == 1)
                {
                    std::cout << cur->val << std::endl;
                } else {
                    std::cout << "List with no odds" << std::endl;
                }
            }
            else
            {
                if (cur->val % 2 == 1)
                {
                    std::cout << cur->val << std::endl;
                }
                recPrintOdd(cur->next);
            }
        }
    }

    void list::recPrintEvenPub()
    {
        recPrintEven(head);
    }

    void list::recPrintOddPub()
    {
        recPrintOdd(head);
    }

    void list::getHead()
    {
        if(isEmpty()) {
            std::cout << "No Head" << std:: endl;
        } else {
            std::cout << "Head: " << head->val << std::endl;
        }
    }

    void list::getTail()
    {
        if(isEmpty()) {
            std::cout << "No Tail" << std:: endl;
        } else {
            std::cout << "Tail: " << tail->val << std::endl;
        }
        
    }

    void list::printList()
    {
        Node *cur = head;
        if (isEmpty())
        {
            std::cout << "Empty List" << std::endl;
        }
        else
        {
            while (cur != nullptr)
            {
                std::cout << cur->val << " " << std::endl;
                cur = cur->next;
            }

            std::cout << std::endl;
        }
    }
    list::~list()
    {
        std::cout << "Destructor Called" << std::endl;

        while(head != nullptr) {
            Node* temp = head;
            std::cout << "Deleting: " << temp->val << std::endl;
            head = temp->next;
            delete temp;
        }
    }

#endif