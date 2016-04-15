/*
File: Queue.h
Auth: Jordan Dodson
Date: 4/4/2016
Info: A standard queue satisfying the FIFO discipline.
*/

#include <cstdlib>
#include <cstdio>

template <typename T>
class Queue {

  private:
    unsigned long next_add, next_remove, length, capacity;
    T* arr;

  public:

    /**
      * Default constructor
      */
    Queue() : next_add(0), next_remove(0), length(0), capacity(32) {
      arr = new T[32];
    }


    /**
      * Insert an item at the tail of the queue.
      *
      * Parameters:
      *   item -> The datum to insert at the tail.
      *
      * Return: void
      */
    void enqueue(T item) {

      // Check if the queue is full. Double the capacity if so.
      if (length == capacity) {

        // Allocate memory for the new backing array
        arr = (T*) realloc(arr, 2 * capacity * sizeof(T));

        if (arr == nullptr) {
          return;
        }

        // Copy the items to the new array
        if (next_remove == 0) {
          next_add = capacity;
        } else {
          // Shift the data to reestablish the queue
          for (unsigned long i = 1; i >= capacity - next_remove; i++) {
            arr[2 * capacity - i] = arr[capacity - i];
          }

          next_remove = capacity + next_remove;
        }

        // Update state to reflect the new capacity
        capacity *= 2;
      }


      arr[next_add] = item;
      length++;

      if (next_add == capacity - 1) {
        next_add = 0;
      } else {
        next_add++;
      }
    }


    /**
      * Remove and return the item at the head of the queue.
      *
      * Return: item at head of queue
      */
    T dequeue() {

      T res;

      if (length > 0) {

        res = arr[next_remove];

        if (next_remove == capacity - 1) {
          next_remove = 0;
        } else {
          next_remove++;
        }

        length--;
      }

      return res;
    }


    /**
      * Return the item at the head of the queue.
      *
      * Return: item at head of queue
      */
    T peek() const {
      return arr[next_remove];
    }


    /**
      * Check if the queue is empty.
      *
      * Return: true if the queue is empty, false otherwise
      */
    bool isEmpty() const {
      return (length == 0);
    }
};
