#ifndef DEQUE_H
#define DEQUE_H

#include "linklist.h"

class Deque {
private:
    DoubleLinkedList list;

public:
    Deque();
    ~Deque();

    void pushFront(const Data& data);
    void pushBack(const Data& data);
    bool popFront();
    bool popBack();
    const Data& front();
    const Data& back();
    bool isEmpty() const;
    void display();
};

#endif 

