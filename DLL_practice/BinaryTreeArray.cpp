// BinaryTree.cpp
#include "BinaryTreeArray.h"


// left = 2 * i + 1, right = 2 * i + 2

BinaryTreeArray::BinaryTreeArray()  {
    for (int i = 0; i < 300; i++) {
        tree[i] = -1;
    }
}

void BinaryTreeArray::insert(int value) {
    int i = 0;
    while (i < 300) {
        if (tree[i] == -1) {
            tree[i] = value;
            capacity++;
            return;
        }
        else if (value < tree[i]) {
            i = i * 2 + 1;
        }
        else {
            i = i * 2 + 2;
        }
    }
}

void BinaryTreeArray::remove(int value) {
    int i = 0;
    while (i < 300 && tree[i] != -1) {
        if (tree[i] == value) {
            // leaf node인 경우
            if ((2 * i + 1 >= 300 || tree[2 * i + 1] == -1) &&
                (2 * i + 2 >= 300 || tree[2 * i + 2] == -1)) {
                tree[i] = -1;
                capacity--;
                return;
            }
            // left만 있는 경우
            else if (2 * i + 2 >= 300 || tree[2 * i + 2] == -1) {
                tree[i] = tree[2 * i + 1];
                tree[2 * i + 1] = -1;
                capacity--;
                return;
            }
            // right만 있는 경우
            else if (2 * i + 1 >= 300 && tree[2 * i + 1] == -1) {
                tree[i] = tree[2 * i + 2];
                tree[2 * i + 2] = -1;
                capacity--;
                return;
            }
            else {
                int mid = 2 * i + 2;
                while (2 * mid + 1 < 300 && tree[2 * mid + 1] != -1) {
                    mid = 2 * mid + 1;
                }
                tree[i] = tree[mid];
                tree[mid] = -1;
                capacity--;
                return;
            }
        }
        else if (value < tree[i]) {
            i = 2 * i + 1;
        }
        else {
            i = 2 * i + 2;
        }
    }
}

int BinaryTreeArray::search(int value) {
    int i = 0;
    while (i < 300 && tree[i] != -1) {
        if (tree[i] == value) {
            return i;
        }
        else if (value < tree[i]) {
            i = 2 * i + 1;
        }
        else {
            i = 2 * i + 2;
        }
    }
    return -1;
}


int BinaryTreeArray::size() {
    return capacity;
}

