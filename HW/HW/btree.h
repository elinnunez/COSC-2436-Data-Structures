#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <fstream>
#include "btnode.h"

class btree
{
private:
    btnode *root;
    int T;
    int height;

public:
    btree(int degree)
    {
        root = nullptr;
        T = degree;
        height = 0;
    }

    void traversal(std::ofstream &outFile)
    {
        traversal(outFile, root);
        outFile << std::endl;
    }

    btnode *search(int k) { return search(root, k); }

    void printLevel(std::ofstream &outFile, int whichlvl)
    {
        printLevel(outFile, root, whichlvl);
        outFile << std::endl;
    }

    int getHeight() { return height; }

    void traversal(std::ofstream &outFile, btnode *node)
    {
        if (node == nullptr) {
            return;
        }
        
        int i;
        for (i = 0; i < node->size; i++)
        {
            traversal(outFile, node->children[i]);
            outFile << node->keys[i] << " ";
        }

        traversal(outFile, node->children[i]);
    }

    btnode *search(btnode *cur, int k)
    {
        int i = 0;
        while (i < cur->size && k < cur->keys[i])
            i++;

        if (cur->keys[i] == k) {
            return cur;
        }

        if (cur->leaf == true) {
            return nullptr;
        }

        return search(cur->children[i], k);
    }

    void insert(int k)
    {
        
        if (root == nullptr)
        {
            root = new btnode(T, true);
            root->keys[0] = k;
            root->size = 1;
            height = 1;
        }
        
        else
        {
            if (root->size == T - 1 && root->leaf == true)
            {
                // Create a the new root.
                btnode *newRoot = new btnode(T, false);
                newRoot->children[0] = root;

                // Insert value k into root.
                int i = root->size - 1;
                while (i >= 0 && k < root->keys[i])
                {
                    root->keys[i + 1] = root->keys[i];
                    i--;
                }
                root->keys[i + 1] = k;
                root->size += 1;

                root = newRoot;

                root->splitChild(0);

                height += 1;
            }
            else
            {
                root->insertNonFull(k);

                if (root->size == T)
                {
                    btnode *newRoot = new btnode(T, false);
                    newRoot->children[0] = root;
                    root = newRoot;

                    root->splitChild(0);

                    height += 1;
                }
            }
        }
    }

    void printLevel(std::ofstream &outFile, btnode *cur, int whichlvl, int level = 1)
    {
        if (cur == nullptr)
        {
            return;
        }

        int i;
        if (level == whichlvl)
        {
            for (i = 0; i < cur->size; i++) {
                outFile << cur->keys[i] << " ";
            }
        }

        else
        {
            level += 1;
            for (i = 0; i < T; i++) {
                printLevel(outFile, cur->children[i], whichlvl, level);
            }
        }
    }

    // void display(std::ofstream &outFile)
    // {
    //     for (int i = 1; i <= height; i++)
    //     {
    //         outFile << "Level " << i << ": ";
    //         printLevel(outFile, i);
    //     }
    // }
};

#endif