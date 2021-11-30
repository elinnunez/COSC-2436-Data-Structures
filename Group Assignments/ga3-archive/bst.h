#ifndef BST_H
#define BST_H

#include <iostream>
#include <algorithm>
#include <string>
#include "node.h"
#include <queue>

class BST
{
private:
    Node *root;
    void DESTROY(Node* parent); // done
public:
    BST();
    bool isEmpty();  // done
    Node *getRoot(); // done

    bool insert(Node *cur, int val); // done

    void printPreOrder(Node* cur, string line, ofstream &file); // done
    ~BST(); // done
};

BST::BST()
{
    root = nullptr;
}

bool BST::isEmpty()
{
    return root == nullptr;
}

Node *BST::getRoot()
{
    return root;
}

bool BST::insert(Node *cur, int v)
{
    if (isEmpty())
    {
        root = new Node(v);
        return true;
    }
    else if (cur->val < v)
    {
        if (cur->right == nullptr)
        {
            cur->right = new Node(v);
            return true;
        }
        else
        {
            return insert(cur->right, v);
        }
    }
    else if (cur->val > v)
    {
        if (cur->left == nullptr)
        {
            cur->left = new Node(v);
            return true;
        }
        else
        {
            return insert(cur->left, v);
        }
    }
    else
    {
        std::cout << "Value already in BST" << std::endl;
        return false;
    }
}

void BST::printPreOrder(Node* cur, string line, ofstream &outfile) {
    if(cur == nullptr) {
        return;
    } else {
        outfile << "["<< line << "] ";
        outfile << cur->val << " " << std::endl;
        printPreOrder(cur->left, line+'l', outfile);
        printPreOrder(cur->right, line+'r', outfile);
        if(cur == root) {
            std::cout<<std::endl;
        }
    }
}

void BST::DESTROY(Node* parent) {
    if(parent) {
        // std::cout << "RM: " << parent->val << std::endl;
        DESTROY(parent->left);
        DESTROY(parent->right);
        delete parent;
    }
}

BST::~BST() {
    DESTROY(root);
}

#endif