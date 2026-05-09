#ifndef DS_QUEUE_H
#define DS_QUEUE_H

template <typename T>
class Queue {
private:
T* arr;
int capacity;
int frontIndex;
int backIndex;
int count;

public:
    Queue (int capacity = 1000) {
        this->capacity = capacity;
        this->frontIndex = -1;
        this->backIndex = -1;
        this->count = 0;

        this->arr = new T[capacity];
    }
    ~Queue () {
        delete[] this->arr;
        this->arr = nullptr;
    }

    void enqueue (const T& value);
    void dequeue ();

    T front () const;
    T back () const;

    bool empty () const;
    bool full () const;
    int size () const;
};


#endif //DS_QUEUE_H
