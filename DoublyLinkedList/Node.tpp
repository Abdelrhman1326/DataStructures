#include "Node.h"

template<typename T>
Node<T>::Node(const T& data) {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
}

template<typename T>
Node<T>::Node(const T& data, Node<T>* next, Node<T>* prev) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}