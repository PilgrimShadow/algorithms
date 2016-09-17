package com.jgdodson.algorithms

import math.Ordering

object InsertionSort {


  /**
    * Sort the array by insertion sort
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
    */
  def insertionSort[T](arr: Array[T], p: Int, r: Int)(implicit ord: Ordering[T]): Unit = {

    if (r - p > 1) {
    
      var top: T = arr(p)

      for (i <- p+1 until r) {
        top = arr(i)
        var next = i-1

        while ( (next >= p) && ord.lt(top, arr(next)) ) {
          arr(next+1) = arr(next)
          next -= 1
        }

        arr(next+1) = top
      }
    }
  }

}
