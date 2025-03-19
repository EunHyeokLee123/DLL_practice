#ifndef QUEUE_H
#define QUEUE_H

#include "linklist.h"

class Queue {
public:
    Queue();
    ~Queue();

    bool isEmpty() const;
    void enqueue(const Data& in);
    bool dequeue();
    const Data& front();
    void display();

private:
    DoubleLinkedList list;
};

#endif 
