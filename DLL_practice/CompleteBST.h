// BinaryTree.h
#ifndef COMPLETE_BST_H
#define COMPLETE_BST_H

#include <iostream>
#include <vector>

using namespace std;

class CompleteBST {
private:
    vector<int> tree;
    void heapsort(int n, int i);
    void sort();
    vector<int> partSort(vector<int> sub);

public:
    //CompleteBST();
    void insert(int value);
    void remove(int value);
    int search(int value);
    void print();
    int size();
    void realSort();
};

#endif // BINARY_TREE_H