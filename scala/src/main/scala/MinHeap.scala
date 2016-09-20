package com.jgdodson.algorithms

class MinHeap[T](implicit ord: Ordering[T]) extends MaxHeap[T](ord.reversed)
