#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

template <typename T>
class PriorityQueue {
private:
    T* arr;
    int capacity;
    int count;
    int peakIndex;

public:
    PriorityQueue();
    ~PriorityQueue();

    // shallow copies:
    // What C++ does automatically (Shallow Copy)
    // PriorityQueue(const PriorityQueue& other) {
    //     this->capacity = other.capacity;
    //     this->count = other.count;
    //     this->peakIndex = other.peakIndex;
    //     this->arr = other.arr; // <-- THE PROBLEM!
    // }

    // prevent shallow copies:
    PriorityQueue(const PriorityQueue& other) = delete;            // No Copy Constructor
    PriorityQueue& operator=(const PriorityQueue& other) = delete; // No Copy Assignment

    void push(const T& element);
    void pop();
    const T& top();
    bool empty();
    int length();
};

#include "PriorityQueue.tpp"
#endif //PRIORITYQUEUE_H