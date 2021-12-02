#include <iostream>
#include "avl.h"

using namespace std;

int main()
{

    AVL<int> avltree;

    // avltree.insert(avltree.getRoot(), 7);
    // avltree.insert(avltree.getRoot(), 9);
    // avltree.insert(avltree.getRoot(), 13);
    // avltree.insert(avltree.getRoot(), 16);
    // avltree.insert(avltree.getRoot(), 5);
    // avltree.insert(avltree.getRoot(), 2);
    // avltree.insert(avltree.getRoot(), 6);
    // avltree.insert(avltree.getRoot(), 4);
    // avltree.insert(avltree.getRoot(), 3);

    // avltree.insert(avltree.getRoot(), 33);
    // avltree.insert(avltree.getRoot(), 13);
    // avltree.insert(avltree.getRoot(), 53);
    // avltree.insert(avltree.getRoot(), 11);
    // avltree.insert(avltree.getRoot(), 21);
    // avltree.insert(avltree.getRoot(), 61);
    // avltree.insert(avltree.getRoot(), 8);
    // avltree.insert(avltree.getRoot(), 9);
    // avltree.insert(avltree.getRoot(), 3);

    avltree.insert(avltree.getRoot(), 5);
    avltree.insert(avltree.getRoot(), 1);
    avltree.insert(avltree.getRoot(), 2);
    avltree.insert(avltree.getRoot(), 3);
    avltree.insert(avltree.getRoot(), 4);
    avltree.insert(avltree.getRoot(), 5);

    avltree.printByLevel(avltree.getRoot());

    cout << "AVL Tree Root: " << avltree.getRoot()->val << endl;

    cout << "Largest Node: " << avltree.largestNode(avltree.getRoot())->val << endl;

    cout << "AVL Tree BF: " << avltree.getBF(avltree.getRoot()) << endl;

    avltree.remove(avltree.getRoot(), 13);
    avltree.remove(avltree.getRoot(), 33);

    avltree.printByLevel(avltree.getRoot());

    cout << "AVL Tree Root: " << avltree.getRoot()->val << endl;

    cout << "Largest Node: " << avltree.largestNode(avltree.getRoot())->val << endl;

    return 0;
}