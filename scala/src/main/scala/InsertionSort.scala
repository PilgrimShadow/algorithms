package com.jgdodson.algorithms


import math.Ordering


object InsertionSort {


  /**
    *
    *
    *
    *
    */
  def insertionSort[T](arr: Array[T])(implicit ord: Ordering[T]): Array[T] = {

    insertionSort(arr, 0, arr.length)

    // Return a reference to the now-sorted array
    arr
  }


  /**
    * Sort the range [p, r) by insertion sort
    *
    *
    *
    */
  def insertionSort[T](arr: Array[T], p: Int, r: Int)(implicit ord: Ordering[T]): Unit = {

    var j = 0
    var t: T = arr(p)

    for (i <- p+1 until r) {
      t = arr(i)
      j = i-1

      while ( (j >= p) && ord.lt(t, arr(j)) ) {
        arr(j+1) = arr(j)
        j -= 1
      }

      arr(j+1) = t
    }
  }

}
