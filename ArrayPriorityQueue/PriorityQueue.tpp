#include "PriorityQueue.h"
#include <cassert>

template<typename T>
PriorityQueue<T>::PriorityQueue() {
    this->capacity = 5;
    this->count = 0;
    this->peakIndex = -1;
    this->arr = new T[this->capacity];
}

template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    delete[] this->arr;
    this->arr = nullptr;
}

template<typename T>
void PriorityQueue<T>::push(const T &element) {
    if (count == capacity) {
        int newCapacity = capacity * 2;
        T* tempArr = new T[newCapacity];

        for (int i = 0; i < count; i++) {
            tempArr[i] = this->arr[i];
        }

        delete[] this->arr;
        this->arr = tempArr;
        this->capacity = newCapacity;
    }

    this->arr[count] = element;
    count++;

    if (count == 1) {
        this->peakIndex = 0;
    } else {
        if (this->arr[count - 1] > this->arr[this->peakIndex]) {
            this->peakIndex = count - 1;
        }
    }
}

template<typename T>
const T &PriorityQueue<T>::top() {
    assert(peakIndex != -1 && "The Priority Queue is currently empty");
    return this->arr[this->peakIndex];
}

template<typename T>
void PriorityQueue<T>::pop() {
    assert(peakIndex != -1 && "The Priority Queue is currently empty");

    // Replace the peak element with the last element in the array
    this->arr[this->peakIndex] = this->arr[count - 1];
    count--;

    // If the queue is now empty, reset peakIndex and exit
    if (count == 0) {
        this->peakIndex = -1;
        return;
    }

    // O(n) scan to find the new maximum element's index
    this->peakIndex = 0;
    for (int i = 1; i < count; i++) {
        if (this->arr[i] > this->arr[this->peakIndex]) {
            this->peakIndex = i;
        }
    }
}

template<typename T>
bool PriorityQueue<T>::empty() {
    return (count == 0);
}

template<typename T>
int PriorityQueue<T>::length() {
    return this->count;
}