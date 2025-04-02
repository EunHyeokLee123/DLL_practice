#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <list>

using namespace std;

struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;

    Node(int value);
};

class BinaryTree {
private:
    Node* root;
    list<int> arr;

    // ���������� ���Ǵ� ��� �޼ҵ��
    Node* insert(Node* node, int value);
    Node* search(Node* node, int value);
    Node* remove(Node* node, int value);
    Node* findMin(Node* node);
    void clear(Node* node);
   // void swap(Node* n1, Node* n2);
    //void sizeup();
   // void sizedown();
    bool isEmpty();
    void printSorted(Node* node);

public:
    BinaryTree();
    ~BinaryTree();

    void insert(int value);
    bool search(int value);
    void remove(int value);
  //  int size();
    bool isLeaf(Node* node);
    Node* searchNode(int value);

  //  void inorder();    // ���� ��ȸ
   // void preorder();   // ���� ��ȸ
   // void postorder();  // ���� ��ȸ

    void clear();      // Ʈ�� ��ü ����
    void printSorted();
};


#endif // BINARY_TREE_H
