#ifndef DS_LINKEDLIST_H
#define DS_LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;

public:
    LinkedList();
    ~LinkedList();

    void push_front(const T& value);
    void push_back(const T& value);

    void pop_front();
    void pop_back();

    bool empty() const;
    int size() const;

    void insert(int index, const T& value);
    void erase(int index);

    void remove(const T& value);

    T getFront() const;
    T getTail() const;
};

#include "LinkedList.tpp"

#endif