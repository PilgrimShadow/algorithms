/*
File: DoublyLinkedList.h
Auth: Jordan Dodson
Date: 4/23/16
Info: Templated implementation of a doubly linked list.
*/

#ifndef _ALGORITHMS_DOUBLY_LINKED_LIST_H
#define _ALGORITHMS_DOUBLY_LINKED_LIST_H

// We will use a templated class to implement a linked list.
template <typename T>
class DoublyLinkedList {

private:

  // Structure for the nodes that will form the list
  struct Node {
    T item;     // The data at this node
    Node* next; // The next node
    Node* prev; // The previous node
  };

  // Points to the head of the list.
  Node* m_head;

  // The number of nodes in the list.
  unsigned long m_length;

public:

  /**
    * Default constructor.
    */
  DoublyLinkedList() : m_head(nullptr), m_length(0) { /* Empty body */ }


  /**
    * Insert an item at the head of the list.
    */
  void push(T x) {

    // Allocate memory to hold the new item
    Node* n = new Node;

    // Set up the new head node
    n->item = x;
    n->next = m_head;
    n->prev = nullptr;

    // Set up the former head node
    if (m_length  > 0) {
      m_head->prev = n;
    }

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

      if (m_length > 1) {
        m_head->next->prev = nullptr;
      }

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
    *
    * x : The item to search for.
    */
  bool contains(T x) const {

    // Used to iterate over the list.
    Node* ptr;

    // Begin searching at the head of the list
    ptr = m_head;

    // Return true as soon as the item is found
    while (ptr != nullptr) {
      if (ptr->item == x) {
        return true;
      }

      // Move to the next node
      ptr = ptr->next;
    }

    // Return false if the item was not found.
    return false;
  }


  /**
    * Remove the given item from the list.
    *
    * TODO: Under construction
    */
  bool remove(T x) {
    
    // Points to the last node searched
    Node *ptr;

    // Only attempt to remove if the list is non-empty
    if (m_length > 0) {

      // Begin searching at the head of the list
      ptr = m_head;

      // Search for the item in the rest of the list
      while (ptr != nullptr) {

        if (ptr->item == x) {

          if (ptr->prev != nullptr) {
            if (ptr->next != nullptr) {
              ptr->prev->next = ptr->next;
              ptr->next->prev = ptr->prev;
            } else {
              ptr->prev->next = nullptr;
            }
          } else {
            m_head = ptr->next;

            if (ptr->next != nullptr) {
              ptr->next->prev = nullptr;
            }
          }

          m_length--;

          delete ptr;

          return true;
        }

        // Move to the next node
        ptr = ptr->next;
      }
    } else {

      // Underflow
      throw 20;
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
