#include<iostream>

using namespace std;

struct node {
    int value;
    node *next;
};

class linked{
    private:
        node *head;
    public:
    linked();
    void addToBeg(int x);
    void print();
    void remove(int x);
};

linked::linked() {
    head = nullptr;
}

void linked::addToBeg(int x) {
    node *temp = new node;
    temp->value = x;
    temp->next = nullptr;

    if(head == nullptr) {
        head = temp;
    }  else { //if list isnt empty;
        temp->next = head;
        head = temp;
    }
};

void linked::print() {
    node *cur = head;
    while(cur != nullptr) {
        cout << cur->value << endl;
        cur = cur->next;
    }
}

void linked::remove(int x) {
    node *cur = head;
    node *temp;
    node *prev = nullptr;

    if(head->value == x) {
        temp = head;
        head = head->next;
        delete temp;
        return;
    }

    while(cur->next != nullptr) {
        if(cur->value == x) {
            prev->next = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}



int main()
{
    linked list;

    for(int i = 10; i >= 0; i--) {

        list.addToBeg(i);
    }

    list.print();

    // list.remove(0);
    // list.remove(10);
    // list.remove(5);

    

    return 0;
}