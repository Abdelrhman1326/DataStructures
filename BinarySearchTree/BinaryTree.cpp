//
// Created by user on 3/17/2026.
//

#include "BinaryTree.h"
#include "Node.h"
#include "BinaryTree.h"

#include <iostream>

template<typename T>
bool BinaryTree<T>::contain(T value) {
    Node<T> *tempNode = this->root;
    while (tempNode != nullptr) {
        if (value == tempNode->value) {
            return true;
        } else if (value < tempNode->value) {
            tempNode = tempNode->left;
        } else {
            tempNode = tempNode->right;
        }
    }

    return false;
}

template<typename T>
void BinaryTree<T>::insert(T value) {
    if (this->root == nullptr) {
        this->root = new Node<T>(value);
        return;
    }

    Node<T> *tempNode = this->root;
    Node<T> *partent = nullptr;

    while (tempNode != nullptr) {
        if (value < tempNode->value) {
            partent = tempNode;
            tempNode = tempNode->left;
        } else if (value > tempNode->value) {
            partent = tempNode;
            tempNode = tempNode->right;
        } else {
            return;
        }
    }

    if (value < partent->value) {
        partent->left = new Node<T>(value);
    } else {
        partent->right = new Node<T>(value);
    }
}

template<typename T>
Node<T>* BinaryTree<T>::find_node(T value) {
    Node<T> *tempNode = this->root;
    while (tempNode != nullptr) {
        if (value == tempNode->value) {
            return tempNode;
        } else if (value < tempNode->value) {
            tempNode = tempNode->left;
        } else {
            tempNode = tempNode->right;
        }
    }
    return nullptr;
}

template<typename T>
Node<T>* BinaryTree<T>::find_parent(T value) {
    // The root has no parent, and we can't search an empty tree
    if (this->root == nullptr || this->root->value == value) {
        return nullptr;
    }

    Node<T> *tempNode = this->root;
    while (tempNode != nullptr) {
        if (value < tempNode->value) {
            if (tempNode->left == nullptr) return nullptr; // Not found
            if (tempNode->left->value == value) return tempNode;
            tempNode = tempNode->left;
        } else {
            if (tempNode->right == nullptr) return nullptr; // Not found
            if (tempNode->right->value == value) return tempNode;
            tempNode = tempNode->right;
        }
    }
    return nullptr;
}

template<typename T>
void BinaryTree<T>::remove(T value) {
    Node<T>* node_to_remove = this->find_node(value);
    if (node_to_remove == nullptr) return;

    Node<T>* node_to_remove_parent = this->find_parent(value);

    // CASE 1: Leaf node
    if (node_to_remove->left == nullptr && node_to_remove->right == nullptr) {
        if (node_to_remove == this->root) {
            this->root = nullptr;
        } else if (node_to_remove_parent->left == node_to_remove) {
            node_to_remove_parent->left = nullptr;
        } else {
            node_to_remove_parent->right = nullptr;
        }

        delete node_to_remove;
        return;
    }

    // CASE 2: One child
    if (!(node_to_remove->right != nullptr && node_to_remove->left != nullptr)) {
        Node<T>* child_of_removed_node = (node_to_remove->left != nullptr) ? node_to_remove->left : node_to_remove->right;

        if (node_to_remove == this->root) {
            this->root = child_of_removed_node;
            delete node_to_remove; // delete for old root
            return;
        }

        if (node_to_remove_parent->left == node_to_remove) {
            node_to_remove_parent->left = child_of_removed_node;
        } else {
            // Update the parent's pointer, not the node being removed
            node_to_remove_parent->right = child_of_removed_node;
        }

        delete node_to_remove;
        return;
    }

    // CASE 3: Two children
    Node<T>* tempNode = node_to_remove->right;
    while (tempNode->left != nullptr) {
        tempNode = tempNode->left;
    }

    T in_order_succesor_value = tempNode->value;

    // This call deletes the successor's old physical node
    this->remove(in_order_succesor_value);

    // Overwrite target node's value with successor's value
    node_to_remove->value = in_order_succesor_value;
}

template<typename T>
void BinaryTree<T>::pre_order_transverse(Node<T>* node) {
    if (this->root == nullptr) {
        return;
    }
    if (node == nullptr) {
        node = this->root;
    }

    std::cout << node->value << " ";

    if (node->left != nullptr)
        pre_order_transverse(node->left);

    if (node->right != nullptr)
        pre_order_transverse(node->right);
}

template<typename T>
void BinaryTree<T>::post_order_transverse(Node<T>* node) {
    if (this->root == nullptr) {
        return;
    }
    if (node == nullptr) {
        node = this->root;
    }

    if (node->left != nullptr)
        post_order_transverse(node->left);

    if (node->right != nullptr)
        post_order_transverse(node->right);

    std::cout << node->value << " ";
}

template<typename T>
void BinaryTree<T>::in_order_transverse(Node<T>* node) {
    if (this->root == nullptr) {
        return;
    }
    if (node == nullptr) {
        node = this->root;
    }

    if (node->left != nullptr)
        in_order_transverse(node->left);

    std::cout << node->value << " ";

    if (node->right != nullptr)
        in_order_transverse(node->right);
}