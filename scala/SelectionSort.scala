package com.jgdodson.algorithms


import Helpers.swap
import math.Ordering

object SelectionSort {

  def selectionSort(arr: Array[Int]): Unit = {

    selectionSort(arr, 0, arr.length)
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
