#ifndef DS_STACK_H
#define DS_STACK_H

#include <cassert>

template<typename T>
class Stack {
private:
    T* arr;
    int topIndex;
    int capacity;

public:
    Stack(int capacity = 1000) {
        this->capacity = capacity;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(const T& value);
    void pop();
    T top() const;
    bool empty() const;
    bool full() const;
    int size() const;
};

#include "Stack.cpp"

#endif
