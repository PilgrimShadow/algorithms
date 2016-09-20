package com.jgdodson.algorithms

import Helpers.swap
import math.Ordering

/**
  * max-heap property: For all nodes other than the root, arr(parent(i)) >= arr(i)
  * min-heap property: For all nodes other than the root, arr(parent(i)) <= arr(i)
  *
  * @param arr      The array that backs the heap.
  * @param heapSize The number of array elements to use for the heap.
  */
class MaxHeap[T](implicit ord: Ordering[T]) {

  //-Members------------------------------------------------

  protected val arr = Array.tabulate[T](16)(_ => null)
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

    maxHeapify(0)

    // Return the item from the top of the heap
    result
  }


  /**
    * Return the largest item in the heap.
    *
    */
  def peek(): T = {

    if (heapSize < 1) {
      throw new Error("Peeking item from empty MaxHeap")
    }

    // Return the item from the top of the heap
    arr(0)
  }


  def isEmpty: Boolean = (heapSize == 0)

  /**
    * Sink an element down to its proper place in the heap.
    *
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
        maxHeapify(largest)
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

  def apply[T](arr: Array[T])(implicit ord: Ordering[T]): MaxHeap[T] = {
    new MaxHeap(arr, arr.length)
  }

  def apply[T](arr: Array[T], heapSize: Int)(implicit ord: Ordering[T]): MaxHeap[T] = {
    new MaxHeap(arr, heapSize)
  }

}
