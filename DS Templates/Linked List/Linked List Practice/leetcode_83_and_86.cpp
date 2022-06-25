// https://leetcode.com/problems/remove-duplicates-from-sorted-list/ (Easy)
// https://leetcode.com/problems/partition-list/ (Medium)

#include <iostream>
#include <ctime>
#include <cstdlib>

struct node
{
    int val;
    node *next;
    node()
    {
        this->val = -1;
        this->next = nullptr;
    }
    node(int value)
    {
        this->val = value;
        this->next = nullptr;
    }
};

class linkedlist
{
private:
    node *head;

public:
    linkedlist()
    {
        // std::cout << "Constructor Called\n";
        head = nullptr;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void addAtEnd(int val)
    {
        node *temp = new node(val);
        if (isEmpty())
        {
            head = temp;
        }
        else
        {
            node *cur = head;
            while (cur->next != nullptr)
            {
                cur = cur->next;
            }
            cur->next = temp;
        }
    }

    void printList()
    {
        if (isEmpty())
        {
            std::cout << "Empty List" << std::endl;
        }
        else
        {
            node *cur = head;

            while (cur != nullptr)
            {
                if (cur->next == nullptr)
                {
                    std::cout << cur->val << std::endl;
                }
                else
                {
                    std::cout << cur->val << "->";
                }
                cur = cur->next;
            }
        }
    }

    // Only works on sorted linked lists - O(n^2)
    void deleteDuplicatesSorted()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        node *cur = head;

        while (cur != nullptr)
        {
            node *temp = cur->next;
            while (temp != nullptr && temp->val == cur->val)
            {
                temp = temp->next;
            }
            cur->next = temp;
            cur = cur->next;
        }
        delete cur;
    }

    // Works on sorted and unsorted linked lists - O(n^2)
    void deleteDuplicatesUnsorted()
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        node *cur = head;

        while (cur != nullptr)
        {
            node *temp = cur->next; // to loop through list
            node *prev = cur;       // hold reference for next non dup of cur->val
            node *prevHead = prev;  // hold reference for head of prev list
            while (temp != nullptr)
            {
                if (temp->val == cur->val)
                {
                    prev->next = temp->next;
                    temp = prev;
                }
                else
                {
                    prev = prev->next;
                }
                temp = temp->next;
            }
            delete temp;
            cur->next = prevHead->next;
            cur = cur->next;
        }
        delete cur;
    }

    // Moves all nodes less then x to front and order is kept - O(n)
    void partitionList(int x)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }

        node *greaterHeadRef = new node(); // head reference for greater than x nodes list
        node *greater = greaterHeadRef;    // node runner for greaterHeadRef

        node *lesserHeadRef = new node(); // head reference for less than x nodes list
        node *less = lesserHeadRef;       // node runner for lesserHeadRef

        while (head != nullptr)
        {
            if (head->val < x)
            {
                less->next = head;
                less = less->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        delete head;

        greater->next = nullptr;
        less->next = nullptr;

        less->next = greaterHeadRef->next;

        head = lesserHeadRef->next;
    }

    ~linkedlist()
    {
        // std::cout << "Destructor Called\n";
        while (head != nullptr)
        {
            node *temp = head;
            head = temp->next;
            delete temp;
        }
    }
};

int main()
{

    std::cout << "Sorted linked list\n";
    linkedlist mySortedList;

    for (int i = 0; i < 10; i++)
    {
        mySortedList.addAtEnd(i);

        if (i % 7 == 0 || i % 3 == 0)
        {
            mySortedList.addAtEnd(i);
        }
    }
    mySortedList.addAtEnd(9);

    mySortedList.printList();
    mySortedList.deleteDuplicatesSorted();
    // mySortedList.deleteDuplicatesUnsorted();
    mySortedList.printList();

    std::cout << "\n";

    std::cout << "Unsorted linked list\n";
    linkedlist myUnsortedList;

    myUnsortedList.addAtEnd(2);
    myUnsortedList.addAtEnd(2);

    for (int i = 0; i < 10; i++)
    {
        int ran = (rand() % 9) + 1;
        myUnsortedList.addAtEnd(ran);

        if (i % 7 == 0 || i % 3 == 0)
        {
            myUnsortedList.addAtEnd(i);
        }
    }
    myUnsortedList.addAtEnd(9);

    myUnsortedList.printList();
    myUnsortedList.deleteDuplicatesUnsorted();
    myUnsortedList.printList();

    std::cout << "\n";

    std::cout << "Partition List\n";

    linkedlist myList;
    int x = 5;

    int myArr[] = {3, 5, 8, 5, 10, 2, 1};
    int arrSize = sizeof(myArr) / sizeof(int);

    for (int i = 0; i < arrSize; i++)
    {
        myList.addAtEnd(myArr[i]);
    }

    myList.printList();
    myList.partitionList(x);
    myList.printList();

    return 1;
}
