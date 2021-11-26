#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "node.h"
#include <fstream>
#include <queue>

template <typename T>
class AVL
{
private:
    Node<T> *root;

    // private variables for rotation functions
    Node<T> *rotateRight(Node<T> *); // Single Rotation for LL Imbalance (clockwise)
    Node<T> *rotateLeft(Node<T> *);  // Single Rotation for RR Imbalance (counter clockwise)

    Node<T> *rotateRightLeft(Node<T> *); // Double Rotation for RL Imbalance (clockwise then counter clockwise)
    Node<T> *rotateLeftRight(Node<T> *); // Double Rotation for LR Imbalance (counter clockwise then clockwise)

    void DESTROY(Node<T> *parent); // helper function for destructor to recursively delete nodes in tree

public:
    AVL(); // constructor

    Node<T> *getRoot(); // returns root
    bool isEmpty();     // checks if tree is empty

    Node<T> *insert(Node<T> *cur, T v); // returns updated root Node of tree after new val has been inserted and rotations have been done
    Node<T> *remove(Node<T> *cur, T val, bool found = false); // returns updated root Node of tree after val has been deleted and rotations have been done

    bool search(Node<T> *cur, T v); // searches for Node in tree
    int findTreeHeight(Node<T> *cur); // returns height of Node
    int getBF(Node<T> *cur);          // return balance factor of Node

    Node<T> *largestNode(Node<T> *cur); // finds largest node in tree of node being input;

    void outputByLevel(Node<T> *cur, ofstream &outfile); // prints out tree starting from node (level by level) *uses queue implementation*

    ~AVL(); // destructor
};

template <typename T>
Node<T> *AVL<T>::rotateRight(Node<T> *cur)
{
    Node<T> *pivot = cur->left;
    cur->left = pivot->right;
    pivot->right = cur;
    return pivot;
}

template <typename T>
Node<T> *AVL<T>::rotateLeft(Node<T> *cur)
{
    Node<T> *pivot = cur->right;
    cur->right = pivot->left;
    pivot->left = cur;
    return pivot;
}

template <typename T>
Node<T> *AVL<T>::rotateLeftRight(Node<T> *cur)
{
    cur->left = rotateLeft(cur->left);
    return rotateRight(cur);
}

template <typename T>
Node<T> *AVL<T>::rotateRightLeft(Node<T> *cur)
{
    cur->right = rotateRight(cur->right);
    return rotateLeft(cur);
}

template <typename T>
AVL<T>::AVL()
{
    root = nullptr;
}

template <typename T>
bool AVL<T>::isEmpty()
{
    return root == nullptr;
}

template <typename T>
Node<T> *AVL<T>::getRoot()
{
    return root;
}

template <typename T>
Node<T> *AVL<T>::insert(Node<T> *cur, T v)
{
    // if(isEmpty()) {
    // root = new Node<T>(v);
    // cur = root;
    // } else
    if (cur == nullptr)
    {
        cur = new Node<T>(v);
    }
    else if (cur->val < v)
    {
        cur->right = insert(cur->right, v);
        // std::cout << cur->right->val << " BF: " << getBF(cur->right) << std::endl;
        if (getBF(cur) <= -2)
        {
            // std::cout << "Cur " << cur->val << " BF: " << getBF(cur) << " = ";
            // std::cout << "Right Heavy" << std::endl;
            if (v > cur->right->val)
            {
                // std::cout << "RR Imbalance" << std::endl;
                cur = rotateLeft(cur);
            }
            else
            {
                // std::cout << "RL Imbalance" << std::endl;
                cur = rotateRightLeft(cur);
            }
        }
    }
    else if (v < cur->val)
    {
        cur->left = insert(cur->left, v);
        // std::cout << cur->left->val << " BF: " << getBF(cur->left) << std::endl;
        if (getBF(cur) >= 2)
        {
            // std::cout << "Cur " << cur->val << " BF: " << getBF(cur) << " = ";
            // std::cout << "Left Heavy" << std::endl;
            if (v < cur->left->val)
            {
                // std::cout << "LL Imbalance" << std::endl;
                cur = rotateRight(cur);
            }
            else
            {
                // std::cout << "LR Imbalance" << std::endl;
                cur = rotateLeftRight(cur);
            }
        }
    }
    else
    {
        std::cout << "Value already in avl tree" << std::endl;
    }
    root = cur;
    return root;
}

template <typename T>
bool AVL<T>::search(Node<T> *cur, T v)
{
    if (cur == nullptr)
    {
        return false;
    }
    else if (cur->val == v)
    {
        return true;
    }
    else if (cur->val < v)
    {
        return search(cur->right, v);
    }
    return search(cur->left, v);
}

template <typename T>
Node<T>* AVL<T>::remove(Node<T>* cur, T val, bool found) {
    // first checks to see if int v is in the tree
    if (!found)
    {
        // set to true to break out of condition if key found
        if (search(cur, val))
        {
            found = true;
        }
        else
        {
            // if key is not found, it doesn't exit therefore -1
            return nullptr;
        }
    }

    Node<T>* toDelete = cur;

    if(val > cur->val) {
        cur->right = remove(cur->right, val, found);
        if(getBF(cur) == 2) {
            if(getBF(cur->left) >= 0) {
                cur = rotateRight(cur);
            } else {
                cur = rotateLeftRight(cur);
            }
        }
    } else if (val < cur->val) {
        cur->left = remove(cur->left, val, found);
        if(getBF(cur) == -2) {
            if(getBF(cur->right) <= 0) {
                cur = rotateLeft(cur);
            } else {
                cur = rotateRightLeft(cur);
            }
        }
    } else {
        // node with two children case
        if(cur->left != nullptr && cur->right != nullptr) {
            toDelete = largestNode(cur->left);
            cur->val = toDelete->val;
            cur->left = remove(cur->left, toDelete->val, found);
        // node with a left child but no right child
        } else if (cur->left) {
            cur = cur->left;
            delete toDelete;
        // node with a right child but no left child
        } else if (cur->right) {
            cur = cur->right;
            delete toDelete;
        // node with no children
        } else {
            delete cur;
            cur = nullptr;
        }
    }

    if(cur == nullptr) {
      return cur;  
    }

    root = cur;
    return root ;
}

template <typename T>
int AVL<T>::findTreeHeight(Node<T> *cur)
{
    if (cur == nullptr)
    {
        return -1;
    }
    else
    {
        return std::max(findTreeHeight(cur->left), findTreeHeight(cur->right)) + 1;
    }
}

template <typename T>
int AVL<T>::getBF(Node<T> *cur)
{
    if (cur == nullptr)
    {
        return -1;
    }
    return (findTreeHeight(cur->left) - findTreeHeight(cur->right));
}

template <typename T>
void AVL<T>::outputByLevel(Node<T> *cur, ofstream &outfile)
{
    std::cout << "Level Order Print: ";
    if (cur == nullptr)
    {
        // std::cout << "NULL";
        return;
    }
    else
    {
        std::queue<Node<T> *> q;
        q.push(cur);

        outfile << q.front()->val << " ";
        std::cout << q.front()->val << " ";

        while (!q.empty())
        {
            Node<T> *temp = q.front();
            q.pop();

            if (q.empty() && temp->left == nullptr && temp->right == nullptr)
            {
                break;
            }

            if (temp->left)
            {
                q.push(temp->left);
                outfile << temp->left->val << " ";
                std::cout << temp->left->val << " ";
            }
            else
            {
                // std::cout << "* ";
            }

            if (temp->right)
            {
                q.push(temp->right);
                outfile << temp->right->val << " ";
                std::cout << temp->right->val << " ";
            }
            else
            {
                // std::cout << "* ";
            }
        }
        // outfile << std::endl;
        return;
    }
}

template <typename T>
void AVL<T>::DESTROY(Node<T> *parent)
{
    if (parent)
    {
        // std::cout << "RM: " << parent->val << std::endl;
        DESTROY(parent->left);
        DESTROY(parent->right);
        delete parent;
    }
}

template <typename T>
AVL<T>::~AVL()
{
    // std::cout << "Destructor Called" << std::endl;
    DESTROY(root);
}

template <typename T>
Node<T>* AVL<T>::largestNode(Node<T>* cur) {
    if(cur == nullptr || cur->right == nullptr) {
        return cur;
    } else {
        return largestNode(cur->right);
    }
}

#endif