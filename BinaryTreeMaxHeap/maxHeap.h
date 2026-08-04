#ifndef MAXHEAP_H
#define MAXHEAP_H

template <typename T>
class maxHeap {
private:
    T* arr = nullptr;     // Dynamic array for storing the binary tree
    int capacity = 8;     // Initial capacity of the array
    int count = 0;        // Number of elements currently in the heap

    // Private helper methods for index navigation
    int getLefttSideChildIndex(int rootIndex);
    int getRightSideChildIndex(int rootIndex);
    void heapify(int rootIndex);
    void downTopHeapify(int childIndex);

public:
    maxHeap();
    ~maxHeap();

    void push(const T& element);
    void pop();
    T& top();
    bool empty();
};

#include "maxHeap.tpp"

#endif // MAXHEAP_H