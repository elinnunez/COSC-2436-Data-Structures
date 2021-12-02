#ifndef DLL_H
#define DLL_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
struct dnode
{
    dnode<T> *prev;
    T payload;
    dnode<T> *next;
};

template <typename T>
class dll
{
private:
    dnode<T> *head;
    dnode<T> *tail;

public:
    dll();
    bool isempty();
    dnode<T>* gethead();
    void insertatbeg(T val);
    bool deletefrombeg(T &retval);
    void print();
    void printrec(dnode<T>*);
};

#endif
