#include "Queue.h"
#include <cassert>

template<typename T>
bool Queue<T>::full() const {
   return (count == capacity);
}

template<typename T>
bool Queue<T>::empty() const {
   return (count == 0);
}

template<typename T>
void Queue<T>::enqueue(const T &value) {
   assert(!full() && "The queue is full!");

   if (empty()) {
      frontIndex = 0;
      backIndex = 0;
      arr[backIndex] = value;
      count++;
      return;
   }

   backIndex = (backIndex + 1) % capacity;
   arr[backIndex] = value;
   count++;
}

template<typename T>
void Queue<T>::dequeue() {
   assert(!empty() && "The queue is empty!");

   frontIndex = (frontIndex + 1) % capacity;
   count--;

   if (count == 0) {
      frontIndex = -1;
      backIndex = -1;
   }
}

template<typename T>
T Queue<T>::front() const {
   assert(!empty() && "The queue is empty!");
   return arr[frontIndex];
}

template<typename T>
T Queue<T>::back() const {
   assert(!empty() && "The queue is empty!");
   return arr[backIndex];
}

template<typename T>
int Queue<T>::size() const {
   return count;
}
