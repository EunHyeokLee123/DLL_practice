#include "Stack.h"
#include <stdexcept>
#include <iostream>

Stack::Stack() : list() {}

bool Stack::isEmpty() const {
    return list.isEmpty();
}

void Stack::push(const Data& in) {
    list.insertHead(in);
}

bool Stack::pop() {
    return list.removeHead();
}

const Data& Stack::top()  {
    if (!isEmpty()) {
        return list.content(list.returnHead()->next);
    }
    throw std::runtime_error("Stack is empty");
}

void Stack::display()  {
    list.display();
}