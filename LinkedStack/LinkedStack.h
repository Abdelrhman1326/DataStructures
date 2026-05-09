#ifndef DS_LINKEDSTACK_H
#define DS_LINKEDSTACK_H

#include "./SinglyLinkedList/LinkedList.h"

template <typename T>
class LinkedStack {
private:
    LinkedList<T> llist;

public:
    LinkedStack() = default;
    ~LinkedStack() = default;

    void push(const T& value);
    void pop();

    T top() const;

    bool empty() const;
    int size() const;
};

#include "LinkedStack.tpp"

#endif // DS_LINKEDSTACK_H