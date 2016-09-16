package com.jgdodson.algorithms


object Helpers {

  def swap[T](arr: Array[T], i: Int, j: Int): Unit = {
    val t: T = arr(i)
    arr(i) = arr(j)
    arr(j) = t
  }

}
