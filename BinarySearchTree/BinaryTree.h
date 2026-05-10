#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Node.h"

template<typename T>
class BinaryTree {
    Node<T> *root;

public:
    bool contain(T value);
    void insert(T value);
    void remove(T value);
    void pre_order_transverse(Node<T>* node = nullptr);
    void post_order_transverse(Node<T>* node = nullptr);
    void in_order_transverse(Node<T>* node = nullptr);

private:
    Node<T>* find_node(T value);
    Node<T>* find_parent(T value);
};

#endif //BINARYTREE_H
