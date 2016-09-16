package com.jgdodson.algorithms

import Helpers.swap
import math.Ordering

// TODO: Generalize to be MaxHeap[T]
// TODO: Do we need the heapSize parameter, really?

/**
  *
  * max-heap property: For all nodes other than the root, arr(parent(i)) >= arr(i)
  * min-heap property: For all nodes other than the root, arr(parent(i)) <= arr(i)
  *
  * @param arr      The array that backs the heap.
  * @param heapSize The number of array elements to use for the heap.
  */
class MaxHeap[T](val arr: Array[T], var heapSize: Int)(implicit ord: Ordering[T]) {

  val length: Int = arr.length

  if (heapSize < 0) {

    throw new Error("Heap size should be positive.")

  } else if (heapSize > arr.length) {

    throw new Error("Heap size cannot exceed array length")

  }

  // Build a heap at init
  buildMaxHeap()

  //-Special Methods----------------------------------------

  // This allows one to index directly into the array backing the heap.
  def apply(index: Int): T = arr(index)

  //-End Special Methods------------------------------------

  // We are using zero-based indexing.
  private def left(i: Int): Int = (2 * i) + 1

  private def right(i: Int): Int = 2 * (i + 1)

  private def parent(i: Int): Int = (i - 1) / 2

  // These methods allow a user of the heap to get the keys of the
  // children and parents of the given index.
  def leftKey(i: Int): T = this.apply(left(i))

  def rightKey(i: Int): T = this.apply(right(i))

  def parentKey(i: Int): T = this.apply(parent(i))

  // Sort the array in place. This destroys the heap.
  def sort(): Array[T] = {
    heapSize = length

    buildMaxHeap()

    for (i <- length - 1 to 1 by -1) {
      swap(arr, 0, i)

      heapSize -= 1

      maxHeapify(0)
    }

    // Return a reference to the now-sorted array
    arr
  }

  private def maxHeapify2(i: Int): Unit = {
    val l: Int = left(i)
    val r: Int = right(i)
    var largest: Int = i


    if ( l < heapSize && ord.gt(arr(l), arr(largest)) ) {
      largest = l
    }

    if ( r < heapSize && ord.gt(arr(r), arr(largest)) ) {
      largest = r
    }

    if (largest != i) {
      swap(arr, i, largest)
      maxHeapify(largest)
    }
  }


  // Builds a heap with size determined by heapSize.
  private def buildMaxHeap(): Unit = {
    // heapSize - 1 is the index of the last heap element. The parent
    // of this element is the last interior element of the binary tree.
    for (i <- parent(heapSize - 1) to 0 by -1) {
      maxHeapify(i)
    }
  }



  private def maxHeapify(i: Int): Unit = {

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

  private def maxHeapify3(i: Int): Unit = {
    val l: Int = left(i)
    val r: Int = right(i)

    var largest = if ( l < heapSize && ord.gt(arr(l), arr(i)) ) l else i

    if ( r < heapSize && ord.gt(arr(r), arr(largest)) ) {
      largest = r
    }

    if (largest != i) {
      swap(arr, i, largest)
      maxHeapify3(largest)
    }
  }

  // Increase the value of the key at index i. Then, restore the heap property.
  def increaseKey(i: Int, k: T): Unit = {
    if ( ord.lteq(k, arr(i)) ) {
      throw new Error("new key is not greater than current key")
    }

    var j = i  // Var for looping.
    arr(j) = k // Increase the key.

    // Float the new key up the heap until the heap property is restored.
    while ( j > 0 && ord.gt(arr(j), arr(parent(j))) ) {
      swap(arr, j, parent(j))
      j = parent(j)
    }

  }


  def insert(v: T): MaxHeap[T] = {
    if (heapSize == length) {
      throw new Error("Heap is full.")
    }

    arr(heapSize) = v

    var j = heapSize // Var for looping.

    // Float the new key up the heap until the heap property is restored.
    while ( j > 0 && ord.gt(arr(j), arr(parent(j))) ) {
      swap(arr, j, parent(j))
      j = parent(j)
    }

    heapSize += 1 // increment heapSize since an element has been added.
    this // for chaining
  }

}

object MaxHeap {

  def apply[T](arr: Array[T])(implicit ord: Ordering[T]): MaxHeap[T] = {
    new MaxHeap(arr, arr.length)
  }

  def apply[T](arr: Array[T], heapSize: Int)(implicit ord: Ordering[T]): MaxHeap[T] = {
    new MaxHeap(arr, heapSize)
  }

  /*
  def apply[T](keys: T*): MaxHeap[T] = {
    new MaxHeap(keys.toArray[T], keys.length)
  }
  */

}
