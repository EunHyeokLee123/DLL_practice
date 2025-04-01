#include "BinaryTree.h"
#include <iostream>

// TreeNode ������ ����
Node::Node(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}

// BinaryTree ������
BinaryTree::BinaryTree() : root(nullptr) {}

// BinaryTree �Ҹ���
BinaryTree::~BinaryTree() {
    clear();
}

// insert �޼ҵ��
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

// contains �Լ�
bool BinaryTree::search(int value) {
    return search(root, value) != nullptr;
}

// getIndex �Լ�, ������ nullptr ����
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

// remove �޼ҵ��
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
        }   // left�� leaf node�� ���
        else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node->right;
            return temp;
        }  // right�� leaf node�� ���
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node->left;
            return temp;
        }  // left, right �Ѵ� leaf node�� �ƴ� ���
        else {
            // value���� ū ���� ���� ���� ���� ��带 ã��
            Node* temp = findMin(node->right);
            // ������ ��ġ�� ��忡 �� ���� ����
            node->data = temp->data;
            // �׸��� �ش� ���� �����ϱ� ���� ��ͷ� �ٽ� remove ȣ��
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}

// �ּҰ��� ������ ��带 ����
Node* BinaryTree::findMin(Node* node) {
    if (node == nullptr) {
        return node;
    }
    else {
        return findMin(node->left);
    }
}

// ��ȸ �޼ҵ��
void BinaryTree::inorder() {
    inorder(root);
}

void BinaryTree::inorder(Node* node) {
    // ���� ����
}

void BinaryTree::preorder() {
    preorder(root);
}

void BinaryTree::preorder(Node* node) {
    // ���� ����
}

void BinaryTree::postorder() {
    postorder(root);
}

void BinaryTree::postorder(Node* node) {
    // ���� ����
}

// clear �޼ҵ�
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
