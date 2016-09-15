package com.jgdodson.algorithms

/*
  AUTH: Jordan Dodson
  INFO: Implementation of bubblesort
*/


object BubbleSort {

  def bubbleSort(arr: Array[Int]): Array[Int] = {

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
        if (arr(i) > arr(i+1)) {
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

  def swap(arr: Array[Int], i: Int, j: Int): Unit = {
    val t = arr(i)
    arr(i) = arr(j)
    arr(j) = t
  }

}
