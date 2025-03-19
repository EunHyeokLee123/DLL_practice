#include "deque.h"
#include <iostream>
using namespace std;

Deque::Deque() : list() {}

Deque::~Deque() {}

void Deque::pushFront(const Data& data) {
    list.insertHead(data);
}

void Deque::pushBack(const Data& data) {
    list.insertTail(data);
}

bool Deque::popFront() {
    return list.removeHead();
}

bool Deque::popBack() {
    return list.removeTail();
}

const Data& Deque::front()  {
    if (isEmpty()) {
        throw runtime_error("Deque is empty");
    }
    return list.content(list.returnHead()->next);
}

const Data& Deque::back()  {
    if (isEmpty()) {
        throw runtime_error("Deque is empty");
    }
    return list.content(list.returnTail()->prev);
}

bool Deque::isEmpty() const {
    return list.isEmpty();
}

void Deque::display()  {
    cout << "µðÅ¥ÀÓ" << endl;
    list.display();
}
