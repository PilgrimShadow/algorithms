/*
File: Stack.h
Auth: Jordan Dodson
Date: 4/4/2016
Info: A basic stack following the LIFO discipline.
*/

template <typename T>
class Stack {

  private:
    unsigned long next, length, capacity;
    T* arr;

  public:

    Stack() : next(0), length(0), capacity(32) {
      arr = new T[32];
    }

    /**
      * Add an item to the top of the stack.
      *
      * Parameters:
      *  item -> The item to add.
      *
      * Return: void
      */
    void push(T item) {

      // Check if the stack is full. Double the capacity if so.
      if (next == capacity) {

        // Allocate memory for the new array
        arr = (T*) realloc(arr, 2 * capacity * sizeof(T));

        if (arr == NULL) {
          perror("Failed to realloc.");
          return;
        }

        // Update state to reflect the new capacity.
        capacity *= 2;
      }

      arr[next++] = item;
      length++;
    }


    /**
      * Remove and return the item at the top of the stack.
      *
      * Parameters:
      *
      * Return: The item at the top of the stack.
      */
    T pop() {
      return arr[--next];
    }


    /**
      * Return the item at the top of the stack.
      *
      * Parameters:
      *
      * Return: The item at the top of the stack.
      */
    T peek() const {
      return arr[next - 1];
    }


    /**
      * Return true iff the stack is empty.
      *
      * Parameters:
      *
      * Return: Whether or not the stack is empty.
      */
    bool isEmpty() const {
      return (length == 0);
    }
};
