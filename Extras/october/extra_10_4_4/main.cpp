#include <iostream>
#include "node.h"
#include "hash.h"
#include <random>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int hashFun(int x)
{
    return x % 10;
}

void nodeHash(Node *table[], int x)
{
    int index = hashFun(x);
    Node *temp = new Node(x);
    if (table[index] == nullptr)
    {
        table[index] = temp;
    }
    else
    {
        Node *cur = table[index];

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = temp;
    }
}

bool searchNodeArr(Node *arr[], int x)
{
    int index = hashFun(x);

    if (arr[index] == nullptr)
    {
        cout << "False" << endl;
    }
    else
    {
        Node *cur = arr[index];
        while (cur != nullptr)
        {
            if (cur->data == x)
            {
                break;
            }
            cur = cur->next;
        }

        if (cur == nullptr)
        {
            cout << "False" << endl;
            return false;
        }
        else
        {
            cout << "True" << endl;
            return true;
        }
    }
}

void delNodeArr(Node *arr[], int val)
{
    int index = hashFun(val);
    if (arr[index] == nullptr)
    {
        std::cout << "Not Found, Can't Delete Node" << std::endl;
        return;
    }
    else
    {
        Node *cur = arr[index];
        Node *prev = nullptr;

        while (cur != nullptr)
        {
            if (cur->data == val)
            {
                break;
            }
            prev = cur;
            cur = cur->next;
        }

        if (cur != nullptr)
        {
            int curVal = cur->data;
            if (cur == arr[index])
            {
                Node *temp = cur;
                arr[index] = temp->next;
                delete temp;
            }
            else if (cur->next == nullptr)
            {
                prev->next = nullptr;
            }
            else if (cur == arr[index])
            {
                Node *temp = cur;
                arr[index] = temp->next;
                delete temp;
            }
            else
            {
                prev->next = cur->next;
            }
            std::cout << "Deleted: " << curVal << std::endl;
            return;
        }
        else
        {
            std::cout << "Val Not Found" << std::endl;
            return;
        }
    }
}

void hashList(Hash *table[], int x)
{
    int index = hashFun(x);

    table[index]->addAtEnd(x);

    // if(table[index]->isEmpty()) {
    //     table[index]->addAtEnd(x);
    // } else {
    //     table[index]->addAtEnd(x);
    // }
}

int main()
{
    // int numArr[20] = {5, 35, 7, 13, 88, 23, 9, 20, 19, 44, 52, 18, 63, 74, 52, 99, 15, 27, 43, 11};

    Node *nodeArr[10];
    Hash *hashArr[10];

    for (int i = 0; i < 10; i++)
    {
        nodeArr[i] = nullptr;
        hashArr[i] = new Hash;
    }

    // cout << "Test Array: ";
    // for (int i = 0; i < 20; i++)
    // {
    //     cout << numArr[i] << " ";
    //     hashList(hashArr, numArr[i]);
    //     nodeHash(nodeArr, numArr[i]);
    // }

    ifstream file("nums.txt");

    if(!file.is_open()) {
        cout << "Can't Open File" << endl;
        return -1;
    }

    while(!file.eof()) {
        string line;

        getline(file, line);
        if(line.length() == 0) {
            continue;
        }
        cout << line << " ";
        hashList(hashArr, stoi(line));
        nodeHash(nodeArr, stoi(line));

    }

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "Hash Array Index " << i << ": ";
        hashArr[i]->display();
    }

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "Node Array Index " << i << ": ";
        if (nodeArr[i] == nullptr)
        {
            cout << "NULL";
        }
        else
        {
            Node *cur = nodeArr[i];

            while (cur != nullptr)
            {
                cout << cur->data << " ";
                cur = cur->next;
            }
        }
        cout << endl;
    }

    // Search for a number in hashArr using search function in class Hash
    int input;

    cout << "Enter number to search: ";
    cin >> input;

    int indexToCheck = hashFun(input);

    hashArr[indexToCheck]->search(input);
    cout << "hashArr[i] Size: " << hashArr[indexToCheck]->getLength() << endl;

    hashArr[indexToCheck]->delNode(input);
    hashArr[indexToCheck]->display();

    // Search through nodeArr
    searchNodeArr(nodeArr, input);
    delNodeArr(nodeArr, input);

    int i = indexToCheck;

    if (nodeArr[i] == nullptr)
    {
        cout << "NULL";
    }
    else
    {
        Node *cur = nodeArr[i];

        while (cur != nullptr)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }
    cout << endl;

    return 0;
}