#include <cassert>
#include <algorithm>

template<typename T>
maxHeap<T>::maxHeap() {
    this->arr = new T[capacity];
}

template<typename T>
maxHeap<T>::~maxHeap() {
    delete[] this->arr;
    this->arr = nullptr;
}

template<typename T>
bool maxHeap<T>::empty() {
    return this->count == 0;
}

template<typename T>
T& maxHeap<T>::top() {
    assert((this->count > 0) && "The heap is empty!");
    return this->arr[1];
}

template <typename T>
int maxHeap<T>::getLefttSideChildIndex(int rootIndex) {
    return (rootIndex * 2);
}

template <typename T>
int maxHeap<T>::getRightSideChildIndex(int rootIndex) {
    return ((rootIndex * 2) + 1);
}

template <typename T>
void maxHeap<T>::heapify(int rootIndex) {
    int largest = rootIndex;

    int leftSideChildIndex = this->getLefttSideChildIndex(rootIndex);
    int rightSideChildIndex = this->getRightSideChildIndex(rootIndex);

    if (leftSideChildIndex <= this->count && this->arr[leftSideChildIndex] > this->arr[largest]) {
        largest = leftSideChildIndex;
    }

    if (rightSideChildIndex <= this->count && this->arr[rightSideChildIndex] > this->arr[largest]) {
        largest = rightSideChildIndex;
    }

    if (largest != rootIndex) {
        std::swap(this->arr[rootIndex], this->arr[largest]);
        this->heapify(largest);
    }
}

template <typename T>
void maxHeap<T>::downTopHeapify(int childIndex) {
    if (childIndex <= 1) {
        return;
    }

    int parentIndex = childIndex / 2;

    if (this->arr[childIndex] > this->arr[parentIndex]) {
        std::swap(this->arr[childIndex], this->arr[parentIndex]);
        this->downTopHeapify(parentIndex); // Recursively move up
    }
}

template<typename T>
void maxHeap<T>::push(const T& element) {
    if (this->count >= this->capacity - 1) {
        this->capacity *= 2;
        T* newArr = new T[this->capacity];
        for (int i = 1; i <= this->count; ++i) {
            newArr[i] = this->arr[i];
        }
        delete[] this->arr;
        this->arr = newArr;
    }

    // Insert element at the very end of the array
    this->count++;
    this->arr[this->count] = element;

    // Pass the final index to bubble it up to its proper home
    this->downTopHeapify(this->count);
}

template<typename T>
void maxHeap<T>::pop() {
    assert((this->count > 0) && "Cannot pop from an empty heap!");

    if (this->count == 1) {
        this->count--;
        return;
    }

    std::swap(this->arr[1], this->arr[this->count]);
    this->count--;
    this->heapify(1);
}