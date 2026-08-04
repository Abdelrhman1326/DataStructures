#ifndef MINHEAP_H
#define MINHEAP_H

template <typename T>
class minHeap {
private:
    T* arr = nullptr;
    int capacity = 8;
    int count = 0;

public:
    minHeap();
    ~minHeap();
    void push(T& element);
    void pop();
    T& top();
    bool empty();

private: // helper functions
    void heapify(int& rootIndex);
    int getLefttSideChildIndex(int& rootIndex);
    int getRightSideChildIndex(int& rootIndex);
};

#include "minHeap.tpp"
#endif //MINHEAP_H