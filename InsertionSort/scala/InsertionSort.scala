package com.jgdodson.algorithms

object InsertionSort {

  def insertionSort(arr: Array[Int]): Unit = {

    insertionSort(arr, 0, arr.length)
  }

  def insertionSort(arr: Array[Int], p: Int, r: Int): Unit = {

    var j = 0
    var t = 0

    for (i <- p+1 until r) {
      t = arr(i)
      j = i-1

      while (j >= p && t < arr(j)) {
        arr(j+1) = arr(j)
        j -= 1
      }

      arr(j+1) = t
    }
  }

}
