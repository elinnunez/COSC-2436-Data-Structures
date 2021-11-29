#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    BST mytree;

    // cout << mytree.isEmpty() << endl;

    mytree.insert(mytree.getRoot(), 8);
    mytree.insert(mytree.getRoot(), 10);
    mytree.insert(mytree.getRoot(), 3);
    mytree.insert(mytree.getRoot(), 1);
    mytree.insert(mytree.getRoot(), 6);
    mytree.insert(mytree.getRoot(), 14);
    mytree.insert(mytree.getRoot(), 4);
    mytree.insert(mytree.getRoot(), 7);
    mytree.insert(mytree.getRoot(), 13);
    mytree.insert(mytree.getRoot(), 5);
    mytree.insert(mytree.getRoot(), 11);
    mytree.insert(mytree.getRoot(), 12);

    cout << "Tree Height: " << mytree.findTreeHeight(mytree.getRoot()) << endl;
    mytree.printByLevel(mytree.getRoot());
    cout << "Number of Leaves: " << mytree.numLeaves(mytree.getRoot()) << endl;
    cout << "Number of Nodes: " << mytree.numNodes(mytree.getRoot()) << endl;
    cout << "Node 11 Depth: " << mytree.findDepth(mytree.getRoot(), 11) << endl;
    cout << "Node 11 Height: " << mytree.findKeyHeight(mytree.getRoot(), 11) << endl;

    Node* temp = mytree.findParent(mytree.getRoot(), 8);
    cout << "Node 8 parent: Node " << temp->val << endl;

    Node* largest = mytree.largestNode(mytree.getRoot());
    cout << "Largest Node: " << largest->val << endl;

    Node* smallest = mytree.smallestNode(mytree.getRoot());
    cout << "Smallest Node: " << smallest->val << endl;

    cout << "Preorder Print: ";
    mytree.printPreOrder(mytree.getRoot());

    cout << "Inorder Print: ";
    mytree.printInOrder(mytree.getRoot());

    cout << "Postorder Print: ";
    mytree.printPostOrder(mytree.getRoot());

    Node* newRoot = mytree.remove(mytree.getRoot(), 6); // returns root node of modified bst after key removal

    cout << "newRoot Node: " << newRoot->val << endl;

    mytree.printByLevel(mytree.getRoot());

    cout << "Preorder Print: ";
    mytree.printPreOrder(mytree.getRoot());

    cout << "Inorder Print: ";
    mytree.printInOrder(mytree.getRoot());

    cout << "Postorder Print: ";
    mytree.printPostOrder(mytree.getRoot());

    BST newtree(newRoot);

    newtree.insert(newtree.getRoot(), 55);
    newtree.printByLevel(newtree.getRoot());

    cout << newtree.isValidBST(newtree.getRoot()) << endl;

    return 0;
}