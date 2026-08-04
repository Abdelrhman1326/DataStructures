#include <cassert>
#include "minHeap.h"

template<typename T>
minHeap<T>::minHeap() {
    this->arr = new T[capacity];
    // we will not use the index 0, so now we initially have 3 levels: floor(log2(8)) = 3
}

template<typename T>
minHeap<T>::~minHeap() {
    delete[] this->arr;
    this-arr = nullptr;
}

template<typename T>
bool minHeap<T>::empty() {
    return count == 0;
}

template<typename T>
T &minHeap<T>::top() {
    assert((count > 0) && "The min heap is empty!");

    return this->arr[1]; // O(1)
}

template <typename T>
void minHeap<T>::getLefttSideChildIndex(int& rootIndex) {
    return (rootIndex * rootIndex);
}

template <typename T>
void minHeap<T>::getRightSideChildIndex(int& rootIndex) {
    return ((rootIndex * rootIndex) + 1);
}

template <typename T>
void minHeap<T>::heapify(int& rootIndex) {
    // make sure all children are less than the root:
    int& leftSideChildIndex = this->getLefttSideChildIndex(rootIndex);
    int& rightSideChildIndex = this->getRightSideChildIndex(rootIndex);

}