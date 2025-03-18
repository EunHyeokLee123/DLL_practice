#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include <string>

using namespace std;

typedef string Data;

struct Node {
    Data pdata;
    Node* prev;
    Node* next;

    Node(const Data& data = "");  // 선언만
};


class DoubleLinkedList {
public:
    DoubleLinkedList();  // 선언만
    ~DoubleLinkedList();

    bool isEmpty() const;
    Node* returnHead();
    Node* returnTail();
    const Data& content(const Node* now) const;
    void insertTail(const Data& in);
    void insertHead(const Data& in);
    void insert(const Data& in, Node* prev);
    bool removeHead();
    bool removeTail();
    bool remove(const Data& in);
    Node* find(const Data& tar);
    void display();
    const Node* front(const Node* now) const;
    const Node* back(const Node* now) const;

private:
    Node* header;
    Node* tail;
};

#endif // LINKLIST_H

