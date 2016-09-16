package com.jgdodson.algorithms


import Helpers.swap
import InsertionSort.insertionSort
import math.Ordering


object Quicksort {

  def quicksort[T](arr: Array[T])(implicit ord: Ordering[T]): Array[T] = {

    quicksort(arr, 0, arr.length)

    // Return a reference to the now-sorted array
    return arr
  }


  def quicksort[T](arr: Array[T], p: Int, r: Int)(implicit ord: Ordering[T]): Unit = {

    if ( r-p > 1 ) {
      val q = partition(arr, p, r)
      quicksort(arr, p,   q)
      quicksort(arr, q+1, r)
    }
  }


  def quickinsort[T](arr: Array[T], p: Int, r: Int, n: Int)(implicit ord: Ordering[T]): Unit = {

    if ( r-p > n ) {
      val q = partition(arr, p, r)
      quickinsort(arr, p,   q, n)
      quickinsort(arr, q+1, r, n)
    } else if ( r-p > 1 ) {
      insertionSort(arr, p, r)
    }

  }


  // Partition the half-open interval [p, r)
  private def partition[T](arr: Array[T], p: Int, r: Int)(implicit ord: Ordering[T]): Int = {

    var i = p
    val pivot = arr(r-1)

    while ( ord.lt(arr(i), pivot) ) {
      i += 1
    }

    for (j <- i+1 until r) {
      if ( ord.lt(arr(j), pivot) ) {

        swap(arr, i, j)
        i += 1
      }
    }

    // Swap pivot element into place
    swap(arr, i, r)

    return i
  }

}
