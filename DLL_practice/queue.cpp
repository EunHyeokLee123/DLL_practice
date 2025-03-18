#include "Queue.h"
#include <stdexcept>
#include <iostream>

Queue::Queue() : list() {}

bool Queue::isEmpty() const {
    return list.isEmpty();
}

void Queue::enqueue(const Data& in) {
    list.insertTail(in);
}

bool Queue::dequeue() {
    return list.removeHead();
}

const Data& Queue::front()  {
    if (!isEmpty()) {
        return list.content(list.returnHead()->next);
    }
    throw std::runtime_error("Queue is empty");
}

void Queue::display()  {
    list.display();
}
