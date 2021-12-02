#include <iostream>
#include "daqueue.h"
#include "llqueue.h"

using namespace std;
//make a way to add an extra space for every dequeue so queue can keep adding
int main()
{
    // queue<int> line(5);

    Queue<int> linkedline;

    // line.getFront();
    for(int i = 5; i > 0; i--) {
        // line.enqueue(i);
        linkedline.enqueue(i);
    }
    // line.display();
    // linkedline.display();

    // for(int i = 5; i > 0; i--) {
        // line.dequeue();
        // linkedline.dequeue();
    // }
    // line.display();
    // linkedline.display();
    // line.getFront();
    // line.enqueue(8);
    // linkedline.enqueue(8);
    // linkedline.enqueue(12);
    // linkedline.display();
    // linkedline.getFront();
    // cout << linkedline.getSize() << endl;

    // line.dequeue();
    // line.displayR(0, line.getSize());
    // line.display();
    // line.dequeue();

    // line.displayR(0);
    // line.display();
    // line.enqueue(45);
    // line.display();
    // line.displayRec();

    linkedline.displayRec(linkedline.getFrontNode());
    linkedline.display();
    linkedline.dequeue();
    linkedline.displayRec(linkedline.getFrontNode());
    linkedline.display();
    linkedline.enqueue(27);
    linkedline.displayRec(linkedline.getFrontNode());
    linkedline.display();



    return 0;
}