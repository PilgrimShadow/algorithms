/*
File: LinkedList.h
Auth: Jordan Dodson
Date: 1/22/16
Info: Templated implementation of a standard linked list.
*/

#ifndef _ALGORITHMS_LINKED_LIST_H
#define _ALGORITHMS_LINKED_LIST_H

// We will use a templated class to implement a linked list.
template <typename T>
class LinkedList {

private:

  // Structure for the nodes that will form the list
  struct Node {
    T item;
    Node* next;
  };

  // Points to the head of the linked list.
  Node* m_head;

  // Stores the number of items in the linked list.
  unsigned long m_length;

public:

  /**
    * Default constructor.
    */
  LinkedList() : m_head(nullptr), m_length(0) { /* Empty body */ }


  /**
    * Insert an item at the head of the list.
    */
  void push(T x) {

    // Allocate memory to hold the new item
    Node* n = new Node;

    // Set up the new node
    n->item = x;
    n->next = m_head;

    // Insert the new node at the head of the list
    m_head = n;

    // Increment the length of the list
    m_length++;
  }


  /**
    * Remove and return the item at the head of the list.
    */
  T pop() {

    Node* ptr;
    T res;

    if (m_length > 0) {

      // Get the item at the head of the list
      res = m_head->item;

      // Store a reference to the head before updating it
      ptr = m_head;

      // Advance the head of the list
      m_head = m_head->next;

      // Decrement the length of the list
      m_length--;

      // Deallocate the former head of the list
      delete ptr;

    } else {

      // Underflow
      throw 20;
    }

    return res;
  }


  /**
    * Return the item at the head of the list.
    */
  T peek() const {

    if (m_length > 0) {
      return m_head->item;
    } else {

      // Underflow
      throw 20;
    }
  }


  /**
    * Test whether the list contains the given item.
    */
  bool contains(T x) const {

    // Used to iterate over the list.
    Node* ptr;

    // Begin searching at the head of the list
    ptr = m_head;

    while (ptr != nullptr) {

      // Return true as soon as the item is found
      if (ptr->item == x) {
        return true;
      }

      // Move to the next item
      ptr = ptr->next;
    }

    // Return false if the item was not found.
    return false;
  }


  /**
    * Remove the given item from the list.
    */
  bool remove(T x) {
    
    // Points to the last node searched
    Node *ptr;

    // Used when removing and deallocating a node
    Node *tmp;

    // Begin searching at the head of the list
    ptr = m_head;

    // Only attempt to remove if the list is non-empty
    if (m_length > 0) {

      // Check if the item is at the head
      if (ptr->item == x) {
        this->pop();
        return true;
      }

      // At this point, we have established the invariant
      // mentioned earlier: that ptr points to the last
      // node searched.

      // Search for the item in the rest of the list
      while (ptr->next != nullptr) {

        if (ptr->next->item == x) {

          tmp = ptr->next;
 
          ptr->next = ptr->next->next;

          m_length--;

          delete tmp;

          return true;
        }

        // Move to the next node
        ptr = ptr->next;
      }
    }

    // Return false if the item was not found
    return false;
  }


  bool removeAll(T x) {


    return false;
  }


  /**
    * Return true iff the list is empty.
    */
  bool isEmpty() const {
    return (m_length == 0);
  }


  /**
    * Return the number of items in the list.
    */
  unsigned long length() const {
    return m_length;
  }

};

#endif
