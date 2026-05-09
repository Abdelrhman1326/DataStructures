#include "Stack.h"
#include <cassert>

template <typename T>
void Stack<T>::push(const T &value) {
    if ((topIndex + 1) < capacity) {
        // if first time to push set the index to 0:
        arr[++topIndex] = value;
    } else {
        // increase the size first:
        capacity *= 2;
        // create new array:
        T *tmpArr = new T[capacity];
        // copy the old items:
        for (int i = 0; i <= topIndex; i++) {
            tmpArr[i] = arr[i];
        }
        delete[] arr;
        // replace the old array:
        arr = tmpArr;
        arr[++topIndex] = value;
    }
}


template <typename T>
void Stack<T>::pop() {
    // make sure the size is > 0
    assert(topIndex >= 0 && "Stack is empty!");
    topIndex--;
}


template <typename T>
T Stack<T>::top() const {
    assert(topIndex != -1 && "Stack is empty!");
    return arr[topIndex];
}


template <typename T>
bool Stack<T>::empty() const {
    return (topIndex == -1);
}


template <typename T>
bool Stack<T>::full() const {
    return (topIndex == capacity - 1);
}


template <typename T>
int Stack<T>::size() const {
    return (topIndex + 1); // items count (+1, the array is zero indexed)
}
