package com.jgdodson.algorithms

import Helpers.swap
import math.Ordering

object BubbleSort {

  /**
    * Sort an Array of type T objects using bubblesort
    *
    * @param arr The array to be sorted
    * @param ord The ordering to use when sorting
    */
  def bubbleSort[T](arr: Array[T])(implicit ord: Ordering[T]): Array[T] = {

    // To get us going
    var swapped = true

    // The upper limit of each bubbling pass
    var j = arr.length - 1

    // Keep bubbling until no swaps are performed.
    while (swapped) {

      // Reset for this pass
      swapped = false

      // Bubble values up through the unsorted range
      for (i <- 0 until j) {
        if ( ord.gt(arr(i), arr(i+1)) ) {
          swap(arr, i, i+1)
          swapped = true
        }
      }

      // The largest value in arr[:j] bubbled to the top
      j -= 1
    }

  // Return a reference to the now-sorted array
  return arr
}

}
