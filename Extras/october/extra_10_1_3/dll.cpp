#include <iostream>
#include <string>
#include "dll.h"

using namespace std;

template <typename T>
dll<T>::dll()
{
    head = nullptr;
    tail = nullptr;
}

template <typename T>
bool dll<T>::isempty()
{
    if (head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename T>
void dll<T>::insertatbeg(T val)
{
    if (isempty())
    {
        dnode<T> *temp = new dnode<T>;
        head = temp;
        head->prev = head->next = nullptr;
    }
    dnode<T> *temp = new dnode<T>;
    temp->payload = val;
    head->prev = temp;
    temp->next = head;
    temp->prev = nullptr;;
    head = temp;
}

template <typename T>
void dll<T>::print()
{
    dnode<T> *cu = head;
    while (cu != nullptr)
    {
        cout << cu->payload << endl;
        cu = cu->next;
    }
}

template <typename T>
dnode<T>* dll<T>::gethead() {
    return head;
}

template <typename T>
void dll<T>::printrec(dnode<T>* cu) {
    if (cu == nullptr) {
        return;
    } else {
        cout << cu->payload << endl;
        printrec(cu->next);
    }
}

template <typename T>
bool dll<T>::deletefrombeg(T &retval) {
    if(isempty()) {
        return false;
    } else {
        dnode<T>* temp = head;
        retval = temp->payload;
        temp->next->prev = nullptr;
        head = temp->next;
        delete temp;

        return true;
    }
}


