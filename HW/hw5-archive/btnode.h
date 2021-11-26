//functions sourced from geeksforgeeks b-tree template

#ifndef BTNODE_H
#define BTNODE_H

#include <iostream>
#include <algorithm>

struct btnode
{
    int *keys;
    int degree;
    btnode **children;
    int size;
    bool leaf;

    btnode(int deg, bool l)
    {
        degree = deg;
        leaf = l;
        size = 0;

        keys = new int[degree];
        children = new btnode *[degree + 1];

        for (int i = 0; i < degree + 1; i++) {
            children[i] = nullptr;
        }
    }

    void insertNonFull(int k)
    {
        int i = size - 1;

        if (leaf == true)
        {
        
            for (int j = 0; j < size; j++) {
                if (keys[j] == k) {
                    return;
                }
            }

            while (i >= 0 && keys[i] >= k)
            {
                keys[i + 1] = keys[i];
                i--;
            }

            keys[i + 1] = k;
            size = size + 1;
        }
        else
        {
            while (i >= 0 && keys[i] >= k)
            {
                if (keys[i] == k)
                {
                    return;
                }
                i--;
            }

            children[i + 1]->insertNonFull(k);

            if (children[i + 1]->size == degree) {
                splitChild(i + 1);
            }
        }
    }

    void splitChild(int y)
    {
        btnode *toSplit = children[y];
        btnode *left = new btnode(degree, toSplit->leaf);
        btnode *right = new btnode(degree, toSplit->leaf);

        int mid;
        int midkey;

        if(degree % 2 == 0) {
            mid = (degree/2) - 1;
        } else {
            mid = degree / 2;
        }
        
        midkey = toSplit->keys[mid];

        for (int i = 0; i < mid; i++)
            left->keys[i] = toSplit->keys[i];

        for (int i = mid + 1; i < degree; i++)
            right->keys[i - (mid + 1)] = toSplit->keys[i];

        for (int i = 0; i < mid + 1; i++)
            left->children[i] = toSplit->children[i];

        for (int i = mid + 1; i < degree + 1; i++)
            right->children[i - (mid + 1)] = toSplit->children[i];

        int i = size - 1;
        while (i >= 0 && midkey < keys[i])
        {
            keys[i + 1] = keys[i];
            children[i + 2] = children[i + 1];
            i--;
        }

        keys[i + 1] = midkey;
        children[i + 1] = left;
        children[i + 2] = right;

        left->size = mid;
        right->size = degree / 2;
        size += 1;
    }

    // void print()
    // {
    //     for (int i = 0; i < size; i++)
    //         std::cout << keys[i] << " ";
    //     std::cout << std::endl;
    // }
};

#endif
