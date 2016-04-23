/*
File: Deque.h
Auth: Jordan Dodson
Date:
Info:
*/

template <typename T>
class Deque {

  private:
    unsigned long left, right, length, capacity;
    T* arr;

    /**
      * Expands the capacity of the Deque.
      */
    void resize() {
      // Bring in the resize code from the Queue implementation
    }

  public:

    /**
      * Default constructor.
      */
    Deque() : left(0), right(0), length(0), capacity(32) {
      arr = new T[32];
    }


    /**
      * Append an item to the left of the deque.
      */
    void pushLeft(T item) {
      
      // Relength the queue when it is full
      if (length == capacity) {
        T* tmp = new int[2 * capacity];

        // Copy the items to the new array
        for (unsigned long i=0; i < capacity; i++) {
          tmp[i] = arr[(left + i) % capacity];
        }

        // Clear the old memory
        delete[] arr;

        arr = tmp;
        left = 0;
        right = capacity-1;
        capacity *= 2;
      }

      left = (left - 1 + capacity) % capacity;

      arr[left] = item;
      length++;
    }


    /**
      * Append an item to the right of the deque.
      */
    void pushRight(T item) {

      // Relength the queue when it is full
      if (length == capacity) {
        T* tmp = new int[2 * capacity];

        // Copy the items to the new array
        for (unsigned long i=0; i < capacity; i++) {
          tmp[i] = arr[(left + i) % capacity];
        }

        // Clear the old memory
        delete[] arr;

        arr = tmp;
        left = 0;
        right = capacity-1;
        capacity *= 2;
      }

      right = (right + 1) % capacity;

      arr[right] = item;
      length++;
    }


    T popLeft() {

      T res;

      if (length > 0) {
        res = arr[left];
        left = (left + 1) % capacity;
      }

      return res;
    }


    T popRight() {

      T res;

      if (length > 0) {
        res = arr[right];
        right = (right - 1 + capacity) % capacity;
      }

      return res;
    }


    T peekLeft() const {

      T res;

      if (length > 0) {
        res = arr[left];
      }

      return res;
    }


    T peekRight() const {

      T res;

      if (length > 0) {
        res = arr[right];
      }

      return res;
    }


    bool isEmpty() const {
      return (length == 0);
    }
};
