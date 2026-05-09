#include "LinkedList.h"
#include "Node.h"
#include <cassert>
#include <iostream>

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node<T>* curr = head;
    while (curr != nullptr) {
        Node<T>* next = curr->next;
        delete curr;
        curr = next;
    }
}


template<typename T>
void LinkedList<T>::push_front(const T &value) {
    Node<T>* newNode = new Node<T>(value);

    newNode->next = head;
    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;

    if (count == 0)
        tail = newNode;

    count++;
}


template<typename T>
void LinkedList<T>::push_back(const T &value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->prev = tail;
    newNode->next = nullptr;

    if (count == 0) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    count++;
}


template <typename T>
void LinkedList<T>::pop_front() {
    assert(head != nullptr && "List is empty!");

    Node<T>* tmp = head;
    head = head->next;
    
    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    
    delete tmp;
    count--;
}


template <typename T>
void LinkedList<T>::pop_back() {
    assert(head != nullptr && "List is empty!");

    Node<T>* tmp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }

    delete tmp;
    count--;
}


template <typename T>
bool LinkedList<T>::empty () const {
    return count == 0;
}


template <typename T>
int LinkedList<T>::size () const {
    return count;
}


template<typename T>
void LinkedList<T>::insert(int index, const T &value) {
    assert(index >= 0 && index <= count && "index out of range!");

    if (index == 0) {
        push_front(value);
        return;
    }

    if (index == count) {
        push_back(value);
        return;
    }

    Node<T>* curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    Node<T>* newNode = new Node<T>(value);
    newNode->next = curr;
    newNode->prev = curr->prev;
    
    curr->prev->next = newNode;
    curr->prev = newNode;

    count++;
}


template<typename T>
void LinkedList<T>::erase(int index) {
    assert(index >= 0 && index < count && "index out of range!");

    if (index == 0) {
        pop_front();
        return;
    }

    if (index == count - 1) {
        pop_back();
        return;
    }

    Node<T>* toDelete = head;
    for (int i = 0; i < index; i++)
        toDelete = toDelete->next;

    toDelete->prev->next = toDelete->next;
    toDelete->next->prev = toDelete->prev;

    delete toDelete;
    count--;
}


template<typename T>
void LinkedList<T>::remove(const T &value) {
    assert(head != nullptr);

    Node<T>* curr = head;
    while (curr != nullptr && curr->data != value)
        curr = curr->next;

    if (curr == nullptr)
        return;

    if (curr == head) {
        pop_front();
    } else if (curr == tail) {
        pop_back();
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        count--;
    }
}

template<typename T>
void LinkedList<T>::printForward() const {
    Node<T>* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

template<typename T>
void LinkedList<T>::printBackward() const {
    Node<T>* curr = tail;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->prev;
    }
    std::cout << std::endl;
}