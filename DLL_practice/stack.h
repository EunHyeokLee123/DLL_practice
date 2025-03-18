#ifndef STACK_H
#define STACK_H

#include "linklist.h"

class Stack {
public:
    Stack();

    bool isEmpty() const;
    void push(const Data& in);
    bool pop();
    const Data& top() ;
    void display() ;

private:
    DoubleLinkedList list;
};
























#endif
