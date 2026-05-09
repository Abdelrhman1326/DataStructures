#include "LinkedList.h"
#include "Node.h"
#include <cassert>

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
    head = newNode;

    if (count == 0)
        tail = newNode;

    count++;
}


template<typename T>
void LinkedList<T>::push_back(const T &value) {
    Node<T>* newNode = new Node<T>(value);
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
    delete tmp;

    count--;

    if (count == 0)
        tail = nullptr;
}


template <typename T>
void LinkedList<T>::pop_back() {
    assert(head != nullptr && "List is empty!");

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        count = 0;
        return;
    }

    Node<T>* beforeTail = head;

    while (beforeTail->next != tail)
        beforeTail = beforeTail->next;

    delete tail;
    tail = beforeTail;
    tail->next = nullptr;

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

    Node<T>* insertedNode = new Node<T>(value);

    if (index == 0) {
        insertedNode->next = head;
        head = insertedNode;

        if (count == 0)
            tail = insertedNode;

        count++;
        return;
    }

    Node<T>* curr = head;

    for (int i = 0; i < index - 1; i++)
        curr = curr->next;

    insertedNode->next = curr->next;
    curr->next = insertedNode;

    if (index == count)
        tail = insertedNode;

    count++;
}


template<typename T>
void LinkedList<T>::erase(int index) {
    assert(index >= 0 && index < count && "index out of range!");

    if (index == 0) {
        pop_front();
        return;
    }

    Node<T>* curr = head;

    for (int i = 0; i < index - 1; i++)
        curr = curr->next;

    Node<T>* toDelete = curr->next;
    curr->next = toDelete->next;

    if (toDelete == tail)
        tail = curr;

    delete toDelete;
    count--;
}


template<typename T>
void LinkedList<T>::remove(const T &value) {
    assert(head != nullptr);

    if (head->data == value) {
        pop_front();
        return;
    }

    Node<T>* curr = head;

    while (curr->next != nullptr && curr->next->data != value)
        curr = curr->next;

    if (curr->next == nullptr)
        return;

    Node<T>* toDelete = curr->next;
    curr->next = toDelete->next;

    if (toDelete == tail)
        tail = curr;

    delete toDelete;
    count--;
}

template <typename T>
T LinkedList<T>::getFront() const {
    assert(head != nullptr && "List is empty!");
    return head->data;
}

template <typename T>
T LinkedList<T>::getTail() const {
    assert(tail != nullptr && "List is empty!");
    return tail->data;
}