package com.jgdodson.algorithms

import Helpers.swap
import math.Ordering

object SelectionSort {

  def selectionSort[T](arr: Array[T])(implicit ord: Ordering[T]): Array[T] = {

    selectionSort(arr, 0, arr.length)

    // Return a reference to the now-sorted array
    arr
  }

  def selectionSort[T](arr: Array[T], p: Int, r: Int)(implicit ord: Ordering[T]): Array[T] = {

    var t = 0
    var min_ind = 0

    for (i <- p until r-1) {
      min_ind = i

      for (j <- i+1 until r) {
        if ( ord.lt(arr(j), arr(min_ind)) ) {
          min_ind = j
        }
      }

      swap(arr, i, min_ind)
    }

    // Return a reference to the now-sorted array
    arr
  }

}
