#include "Node.h"

template<typename T>
Node<T>::Node(const T& data) {
    this->data = data;
    this->next = nullptr;
}

template<typename T>
Node<T>::Node(const T& data, Node<T>* next) {
    this->data = data;
    this->next = next;
}