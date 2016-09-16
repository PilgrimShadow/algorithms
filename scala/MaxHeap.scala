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
class MaxHeap(val arr: Array[Int], var heapSize: Int) {

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
  def apply(index: Int) = arr(index)

  //-End Special Methods------------------------------------

  // We are using zero-based indexing.
  private def left(i: Int): Int = (2 * i) + 1

  private def right(i: Int): Int = 2 * (i + 1)

  private def parent(i: Int): Int = (i - 1) / 2

  // These methods allow a user of the heap to get the keys of the
  // children and parents of the given index.
  def leftKey(i: Int): Int = this.apply(left(i))

  def rightKey(i: Int): Int = this.apply(right(i))

  def parentKey(i: Int): Int = this.apply(parent(i))

  // Sort the array in place. This destroys the heap.
  def sort(): Array[Int] = {
    heapSize = length

    buildMaxHeap()

    for (i <- length - 1 to 1 by -1) {
      swap(arr, 0, i)

      heapSize -= 1

      maxHeapify(0)
    }

    arr
  }

  private def maxHeapify2(i: Int): Unit = {
    val Left = left(i)
    val Right = right(i)
    var largest = i


    if (Left < heapSize && arr(Left) > arr(largest)) {
      largest = Left
    }

    if (Right < heapSize && arr(Right) > arr(largest)) {
      largest = Right
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

    val l = left(i)  // Index of the left child if it exists
    val r = right(i) // Index of the right child if it exists

    if (l < heapSize) {
      var largest = if (arr(l) > arr(i)) l else i

      if (r < heapSize && arr(r) > arr(largest)) {
        largest = r
      }

      if (largest != i) {
        swap(arr, i, largest)
        maxHeapify(largest)
      }
    }
  }

  private def maxHeapify3(i: Int): Unit = {
    val Left: Int = left(i)
    val Right: Int = right(i)

    var largest = if (Left < heapSize && arr(Left) > arr(i)) Left else i

    if (Right < heapSize && arr(Right) > arr(largest)) {
      largest = Right
    }

    if (largest != i) {
      swap(arr, i, largest)
      maxHeapify3(largest)
    }
  }

  // Increase the value of the key at index i. Then, restore the heap property.
  def increaseKey(i: Int, k: Int): Unit = {
    if (k <= arr(i)) {
      throw new Error("new key is not greater than current key")
    }

    var j = i // Var for looping.
    arr(j) = k // Increase the key.

    // Float the new key up the heap until the heap property is restored.
    while (j > 0 && arr(j) > arr(parent(j))) {
      swap(arr, j, parent(j))
      j = parent(j)
    }

  }

  // Add a new element to the heap while maintaining the heap property.
  // Increment the heapSize, but throw an exception if the heap is full.
  def insert2(n: Int): MaxHeap = {
    if (heapSize == length) {
      throw new Error("Heap is full.")
    }

    arr(heapSize) = Int.MinValue
    increaseKey(heapSize, n)
    heapSize += 1
    this // for chaining
  }

  def insert(n: Int): MaxHeap = {
    if (heapSize == length) {
      throw new Error("Heap is full.")
    }

    arr(heapSize) = n

    var j = heapSize // Var for looping.
    // Float the new key up the heap until the heap property is restored.
    while (j > 0 && arr(j) > arr(parent(j))) {
      swap(arr, j, parent(j))
      j = parent(j)
    }

    heapSize += 1 // increment heapSize since an element has been added.
    this // for chaining
  }

}

object MaxHeap {

  def apply(arr: Array[Int]): MaxHeap = {
    new MaxHeap(arr, arr.length)
  }

  def apply(arr: Array[Int], heapSize: Int): MaxHeap = {
    new MaxHeap(arr, heapSize)
  }

  // Create an empty heap (heapSize = 0) with the given capacity.
  def apply(capacity: Int) = {
    new MaxHeap(Array.fill(capacity)(0), 0)
  }

  def apply(keys: Int*): MaxHeap = {
    new MaxHeap(keys.toArray, keys.length)
  }

}
