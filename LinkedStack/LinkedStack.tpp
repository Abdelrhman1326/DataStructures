#include "LinkedStack.h"
#include "./SinglyLinkedList/LinkedList.h"

template <typename T>
void LinkedStack<T>::push(const T& value) {
    llist.push_front(value);
}

template <typename T>
void LinkedStack<T>::pop() {
    llist.pop_front();
}

template <typename T>
T LinkedStack<T>::top() const {
    return llist.getFront();
}

template <typename T>
bool LinkedStack<T>::empty() const {
    return llist.empty();
}

template <typename T>
int LinkedStack<T>::size() const {
    return llist.size();
}
