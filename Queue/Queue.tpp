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

   // If the queue was completely empty, we need to initialize frontIndex to 0
   if (empty()) {
      frontIndex = 0;
   }

   // Advance backIndex circularly and insert
   backIndex = (backIndex + 1) % capacity;
   arr[backIndex] = value;
   count++;
}

template<typename T>
void Queue<T>::dequeue() {
   assert(!empty() && "The queue is empty!");

   // If we are removing the very last item, reset the queue to initial empty state
   if (count == 1) {
      frontIndex = -1;
      backIndex = -1;
   } else {
      // Otherwise, just advance the frontIndex circularly
      frontIndex = (frontIndex + 1) % capacity;
   }
   
   count--;
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
