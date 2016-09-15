package com.jgdodson.algorithms

object SelectionSort {

  def selectionSort(arr: Array[Int]): Unit = {

    selectionSort(arr, 0, arr.length)
  }

  def selectionSort(arr: Array[Int], p: Int, r: Int): Unit = {

    var t = 0
    var min_ind = 0

    for (i <- p until r-1) {
      min_ind = i

      for (j <- i+1 until r) {
        if (arr(j) < arr(min_ind)) {
          min_ind = j
        }
      }

      t = arr(i)
      arr(i) = arr(min_ind)
      arr(min_ind) = t
    }
  }

}
