#ifndef DS_NODE_H
#define DS_NODE_H

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& data);
    Node(const T& data, Node<T>* next);
};

#include "Node.tpp"

#endif //DS_NODE_H
