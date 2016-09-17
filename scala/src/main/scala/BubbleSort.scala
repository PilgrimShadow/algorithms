package com.jgdodson.algorithms

import Helpers.swap
import math.Ordering

object BubbleSort {

  def bubbleSort[T](arr: Array[T])(implicit ord: Ordering[T]): Array[T] = {

    bubbleSort(arr, 0, arr.length)

    arr
  }

  /**
    * Sort the interval [p, r) of type T objects using bubblesort
    *
    * @param arr The array to be sorted
    * @param ord The ordering to use when sorting
    */
  def bubbleSort[T](arr: Array[T], p: Int, r: Int)(implicit ord: Ordering[T]): Array[T] = {

    if (r - p > 1) {
      // To get us going
      var swapped = true

      // The upper limit of each bubbling pass
      var upper = r-1

      // Keep bubbling until no swaps are performed.
      while (swapped) {

        // Reset for this pass
        swapped = false

        // Bubble values up through the unsorted range
        for (i <- 0 until upper) {
          if ( ord.gt(arr(i), arr(i+1)) ) {
            swap(arr, i, i+1)
            swapped = true
          }
        }

        // The largest value in arr[:upper] bubbled to the top
        upper -= 1
      }
    }

  // Return a reference to the now-sorted array
  return arr
}

}
