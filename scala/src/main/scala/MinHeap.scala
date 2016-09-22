package com.jgdodson.algorithms

/**
  *
  *
  * min-heap property: For all nodes other than the root, arr(parent(i)) <= arr(i)
  */
class MinHeap[T](implicit ord: Ordering[T]) extends MaxHeap[T]()(ord.reverse)
