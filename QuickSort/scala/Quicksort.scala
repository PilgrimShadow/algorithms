package com.jgdodson.algorithms

object Quicksort {

  def quicksort(arr: Array[Int]): Unit = {

    quicksort(arr, 0, arr.length-1)

  }

  def quicksort(arr: Array[Int], p: Int, r: Int): Unit = {

    if (p < r) {
      val q = partition(arr, p, r)
      quicksort(arr, p, q-1)
      quicksort(arr, q+1, r)
    }
  }

  // Partition the closed interval [p, r]
  private def partition(arr: Array[Int], p: Int, r: Int): Int = {

    var t = 0
    var i = p
    val pivot = arr(r);

    for (j <- p until r) {
      if (arr(j) < pivot) {

        // Swap
        t = arr(i)
        arr(i) = arr(j)
        arr(j) = t

        i += 1;
      }
    }

    // Swap pivot element into place
    t = arr(i)
    arr(i) = arr(r)
    arr(r) = t

    return i
  }

}
