/*
File: LinkedList.h
Auth: Jordan Dodson
Date: 1/22/16
Info: Templated implementation of a standard linked list.
*/

#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

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

    Node* n = new Node;

    n->item = x;
    n->next = m_head;
    m_head = n;
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

      // Store a reference to the head before updating.
      ptr = m_head;

      // Advance the head of the list
      m_head = m_head->next;

      m_length--;

      // Deallocate the former head of the list.
      delete ptr;
    } else {
      throw 20;
    }

    return res;
  }


  /**
    * Return the item at the head of the list.
    */
  T peek() const {

    T res;

    if (m_length > 0) {
      res = m_head->item;
    } else {
      throw 20;
    }

    return res;
  }


  /**
    * Test whether the list contains the given item.
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

      ptr = ptr->next;
    }

    // Return false if the item was not found.
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
