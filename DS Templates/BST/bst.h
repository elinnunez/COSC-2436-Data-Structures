#ifndef BST_H
#define BST_H

#include <iostream>
#include <algorithm>
#include "node.h"
#include <queue>


class BST
{
private:
    Node *root;
    void DESTROY(Node* parent); // done
public:
    BST();
    BST(Node* root); // creates BST out of node input when object created
    
    bool isEmpty();  // done
    Node *getRoot(); // done

    bool isValidBST(Node* cur); // done

    bool insert(Node *cur, int val); // done
    bool search(Node *cur, int val); // done
    Node* remove(Node* cur, int val, bool found = false); // done

    int findDepth(Node *cur, int val, bool found = false);     // done
    int findTreeHeight(Node *root);                            // done
    int findKeyHeight(Node *cur, int val, bool found = false); // done

    int numLeaves(Node *cur); // done
    int numNodes(Node *cur);  // done

    void printByLevel(Node *cur); // done

    Node* findParent(Node* cur, int val); // done
    Node* largestNode(Node* cur); // done
    Node* smallestNode(Node* cur); // done

    void printPreOrder(Node* cur); // done
    void printInOrder(Node* cur); // done
    void printPostOrder(Node* cur); // done

    ~BST(); // done
};

BST::BST()
{
    root = nullptr;
}

BST::BST(Node* cur) {
    root = cur;
}

bool BST::isEmpty()
{
    return root == nullptr;
}

bool BST::isValidBST(Node* cur) {
    if(cur == nullptr) {
        return true;
    }

    bool leftIsBST = false;
    bool rightIsBST = false;

    if(cur->left == nullptr) {
        leftIsBST = true;
    } else if (cur->left->val < cur->val) {
        leftIsBST = isValidBST(cur->left);
    }

    if(cur->right == nullptr) {
        rightIsBST = true;
    } else if (cur->right->val > cur->val) {
        rightIsBST = isValidBST(cur->right);
    }

    return leftIsBST && rightIsBST;
}

Node* BST::remove(Node* cur, int val, bool found) {
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

    Node* toDelete = cur;

    if(cur->val < val) {
        cur->right = remove(cur->right, val, found);
    } else if (cur->val > val) {
        cur->left = remove(cur->left, val, found);
    } else {
        if(cur->left != nullptr && cur->right != nullptr) {
            toDelete = largestNode(cur->left);
            cur->val = toDelete->val;
            cur->left = remove(cur->left, toDelete->val, found);
        } else if (cur->left != nullptr) {
            cur = cur->left;
            delete toDelete;
        } else if (cur->right != nullptr) {
            cur = cur->right;
            delete toDelete;
        } else {
            delete cur;
            cur = nullptr;
        }
    }

    return cur;
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

bool BST::search(Node *cur, int v)
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

int BST::findDepth(Node *cur, int v, bool found)
{
    // first checks to see if int v is in the tree
    if (!found)
    {
        // set to true to break out of condition if key found
        if (search(cur, v))
        {
            found = true;
        }
        else
        {
            // if key is not found, it doesn't exit therefore -1
            return -1;
        }
    }

    // after breaking out of first condition, it cur node val is v, its depth is 0
    if (cur->val == v)
    {
        return 0;
    }
    else if (cur->val < v)
    {
        return findDepth(cur->right, v, found) + 1;
    }
    else
    {
        return findDepth(cur->left, v, found) + 1;
    }
}

int BST::findTreeHeight(Node *cur)
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

int BST::findKeyHeight(Node *cur, int v, bool found)
{
    if (!found)
    {
        if (search(cur, v))
        {
            found = true;
        }
        else
        {
            return -1;
        }
    }

    if (cur->val < v)
    {
        return findKeyHeight(cur->right, v, found);
    }
    else if (cur->val > v)
    {
        return findKeyHeight(cur->left, v, found);
    }
    else
    {
        return findTreeHeight(cur);
    }
}

int BST::numLeaves(Node *cur)
{
    if (cur == nullptr)
    {
        return 0;
    }
    else if (cur->left == nullptr && cur->right == nullptr)
    {
        return 1;
    }
    else
    {
        return (numLeaves(cur->left) + numLeaves(cur->right));
    }
}

int BST::numNodes(Node *cur)
{
    if (cur == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + (numNodes(cur->left) + numNodes(cur->right));
    }
}

void BST::printByLevel(Node *cur)
{
    std::cout << "Level Order Print: ";
    if (cur == nullptr)
    {
        std::cout << "NULL";
        return;
    }
    else
    {
        std::queue<Node *> q;
        q.push(cur);

        std::cout << q.front()->val << " ";

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (q.empty() && temp->left == nullptr && temp->right == nullptr)
            {
                break;
            }

            if (temp->left)
            {
                q.push(temp->left);
                std::cout << temp->left->val << " ";
            }
            else
            {
                std::cout << "* ";
            }

            if (temp->right)
            {
                q.push(temp->right);
                std::cout << temp->right->val << " ";
            }
            else
            {
                std::cout << "* ";
            }
        }
        std::cout << std::endl;
        return;
    }
}

Node* BST::findParent(Node* cur, int key) {
    if(cur->val == key && cur == root) {
        std::cout << "No Parent/Root Node" << std::endl;
        return root;
    } else {
        if(cur->val < key) {
            if(cur->right->val == key) {
                return cur;
            } else {
                return findParent(cur->right, key);
            }
        } else if(cur->val > key) {
            if(cur->left->val == key) {
                return cur;
            } else {
                return findParent(cur->left, key);
            }
        }
    }
}

Node* BST::largestNode(Node* cur) {
    if(cur == nullptr || cur->right == nullptr) {
        return cur;
    } else {
        return largestNode(cur->right);
    }
}

Node* BST::smallestNode(Node* cur) {
    if(cur == nullptr || cur->left == nullptr) {
        return cur;
    } else {
        return smallestNode(cur->left);
    }
}

void BST::printPreOrder(Node* cur) {
    if(cur == nullptr) {
        return;
    } else {
        std::cout << cur->val << " ";
        printPreOrder(cur->left);
        printPreOrder(cur->right);
        if(cur == root) {
            std::cout<<std::endl;
        }
    }
}

void BST::printInOrder(Node* cur) {
    if(cur == nullptr) {
        return;
    } else {
        printInOrder(cur->left);
        std::cout << cur->val << " ";
        printInOrder(cur->right);
        if(cur == root) {
            std::cout<<std::endl;
        }
    }
}

void BST::printPostOrder(Node* cur) {
    if(cur == nullptr) {
        return;
    } else {
        printPostOrder(cur->left);
        printPostOrder(cur->right);
        std::cout << cur->val << " ";
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