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

    // 내부적으로 사용되는 재귀 메소드들
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

  //  void inorder();    // 중위 순회
   // void preorder();   // 전위 순회
   // void postorder();  // 후위 순회

    void clear();      // 트리 전체 삭제
    void printSorted();
};


#endif // BINARY_TREE_H
