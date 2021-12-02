#include <iostream>
#include <string.h>
#include "dll.cpp"

using namespace std;

int main()
{
    dll<string> mylist;
    mylist.insertatbeg("one");
    mylist.insertatbeg("two");
    mylist.insertatbeg("three");
    mylist.print();
    cout << "\nprinting recursively........." << endl;
    mylist.printrec(mylist.gethead());
    cout << "printing recursively DONE" << endl;
    string retdel;
    mylist.deletefrombeg(retdel);
    cout << "you just deleted ------->" << retdel << endl;
    cout << "printing after deletion..............." << endl;
    mylist.print();
    dll<int> yourlist;
    yourlist.insertatbeg(1);
    yourlist.insertatbeg(2);
    yourlist.insertatbeg(3);
    yourlist.print();
    yourlist.printrec(yourlist.gethead());
    dll<char> herlist;
    herlist.insertatbeg('o');
    herlist.insertatbeg('t');
    herlist.insertatbeg('h');
    herlist.print();
    return 0;
}
