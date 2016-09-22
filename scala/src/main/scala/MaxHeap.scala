package com.jgdodson.algorithms

import Helpers.swap
import math.Ordering

/**
  * max-heap property: For all nodes other than the root, arr(parent(i)) >= arr(i)
  *
  * @param arr      The array that backs the heap.
  * @param heapSize The number of array elements to use for the heap.
  */
class MaxHeap[T](implicit ord: Ordering[T]) {

  //-Members------------------------------------------------

  protected val arr: Array[T] = ???
  protected var heapSize = 0

  //-Special Methods----------------------------------------

  // This allows one to index directly into the array backing the heap.
  def apply(index: Int): T = arr(index)

  //-Methods------------------------------------

  // We are using zero-based indexing.
  protected def left(i: Int): Int = (2 * i) + 1
  protected def right(i: Int): Int = 2 * (i + 1)
  protected def parent(i: Int): Int = (i - 1) / 2


  // These methods return the keys of the children and parents of the given index.
  def leftKey(i: Int): T = this.apply(left(i))
  def rightKey(i: Int): T = this.apply(right(i))
  def parentKey(i: Int): T = this.apply(parent(i))


  /**
    * Remove and return the largest item in the heap.
    *
    */
  def pop(): T = {

    if (heapSize < 1) {
      throw new Error("Popping item from empty MaxHeap")
    }

    val result = arr(0)

    swap(arr, 0, heapSize - 1)

    heapSize -= 1

    sinkHeapify(0)

    // Return the item from the top of the heap
    result
  }


  /**
    * Return the largest item in the heap.
    *
    */
  def peek(): T = {

    if (heapSize < 1) {
      throw new Error("Peeking at empty MaxHeap")
    }

    // Return the item from the top of the heap
    arr(0)
  }


  /**
    * Boolean indicating whether the heap is empty
    *
    */
  def isEmpty: Boolean = (heapSize == 0)


  /**
    * Sink an element down to its proper place in the heap.
    *
    *
    */
  protected def sinkHeapify(i: Int): Unit = {

    val l: Int = left(i)  // Index of the left child if it exists
    val r: Int = right(i) // Index of the right child if it exists

    if (l < heapSize) {
      var largest = if ( ord.gt(arr(l), arr(i)) ) l else i

      if ( r < heapSize && ord.gt(arr(r), arr(largest)) ) {
        largest = r
      }

      if (largest != i) {
        swap(arr, i, largest)
        sinkHeapify(largest)
      }
    }
  }


  /**
    * Float an element up to its proper place in the heap.
    *
    */
  protected def floatHeapify(i: Int): Unit = {
   
    var j = i
 
    while ( j > 0 && ord.gt(arr(j), arr(parent(j))) ) {
      swap(arr, j, parent(j))
      j = parent(j)
    }
  }


  /*
   * Insert an element into the heap.
   *
   */
  def insert(v: T): MaxHeap[T] = {

    // TODO: Could copy the object when adding it

    // TODO: Realloc here
    if (heapSize == arr.length) {
      throw new Error("Heap is full.")
    }

    arr(heapSize) = v

    // Float the new key up the heap until the heap property is restored.
    floatHeapify(heapSize)

    // Increment heapSize since an element has been added
    heapSize += 1

    // Return reference to heap for chaining
    this
  }
}


object MaxHeap {

  def apply[T](implicit ord: Ordering[T]): MaxHeap[T] = {
    new MaxHeap[T]
  }

  def apply[T](seq: Seq[T])(implicit ord: Ordering[T]): MaxHeap[T] = {

    val h = MaxHeap[T]

    for (item <- seq) {
      h.insert(item)
    }

    h
  }

}
