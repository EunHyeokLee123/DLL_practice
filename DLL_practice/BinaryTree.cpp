#include "BinaryTree.h"
#include <iostream>

// TreeNode 생성자 정의
Node::Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}

// BinaryTree 생성자
BinaryTree::BinaryTree() : root(nullptr) {}

// BinaryTree 소멸자
BinaryTree::~BinaryTree() {
    clear();
}

// insert 메소드들
void BinaryTree::insert(int value) {
    root = insert(root, value);
}

Node* BinaryTree::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    }
    else {
        node->right = insert(node->right, value);
    }
}

// contains 함수
bool BinaryTree::search(int value) {
    return search(root, value) != nullptr;
}

// getIndex 함수, 없으면 nullptr 리턴
Node* BinaryTree::searchNode(int value) {
    if (!search(value))
        return nullptr;
    else {
        return search(root, value);
    }
}

Node* BinaryTree::search(Node* node, int value) {
    if (node == nullptr || node->data == value) {
        return node;
    }

    if (value < node->data) {
        return search(node->left, value);
    }
    else {
        return search(node->right, value);
    }
}

// remove 메소드들
void BinaryTree::remove(int value) {
    root = remove(root, value);
}

Node* BinaryTree::remove(Node* node, int value) {
    if (isLeaf(node)) return nullptr;

    if (value < node->data) {
        node->left = remove(node->left, value);
    }
    else if (value > node->data) {
        node->right = remove(node->right, value);
    }

    if (node->data == value) {
        if (isLeaf(node)) {
            delete node;
            return nullptr;
        }   // left가 leaf node인 경우
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node->right;
            return temp;
        }  // right가 leaf node인 경우
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node->left;
            return temp;
        }  // left, right 둘다 leaf node가 아닌 경우
        else {
            // value보다 큰 값중 가장 작은 값의 노드를 찾음
            Node* temp = findMin(node->right);
            // 삭제할 위치의 노드에 그 값을 대입
            node->data = temp->data;
            // 그리고 해당 값을 삭제하기 위해 재귀로 다시 remove 호출
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}

// 최소값을 가지는 노드를 리턴
Node* BinaryTree::findMin(Node* node) {
    if (node == nullptr) {
        return node;
    }
    else {
        return findMin(node->left);
    }
}

// 순회 메소드들
void BinaryTree::inorder() {
    inorder(root);
}

void BinaryTree::inorder(Node* node) {
    // 구현 생략
}

void BinaryTree::preorder() {
    preorder(root);
}

void BinaryTree::preorder(Node* node) {
    // 구현 생략
}

void BinaryTree::postorder() {
    postorder(root);
}

void BinaryTree::postorder(Node* node) {
    // 구현 생략
}

// clear 메소드
void BinaryTree::clear() {
    clear(root);
    root = nullptr;
}

void BinaryTree::clear(Node* node) {
    while (!isEmpty()) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

bool BinaryTree::isLeaf(Node* node) {
    if (node->right == nullptr && node->left == nullptr) {
        return true;
    }
    return false;
}
