// BinaryTree.h
#ifndef BINARY_TREE_ARRAY_H
#define BINARY_TREE_ARRAY_H

#include <iostream>
#include <vector>

using namespace std;

class BinaryTreeArray {
private:
    int tree[300];
    int capacity = 0;

public:
    BinaryTreeArray();
    void insert(int value);
    void remove(int value);
    int search(int value);
    void print();
    int size();
};

#endif // BINARY_TREE_H