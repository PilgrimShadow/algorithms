package com.jgdodson.algorithms


import scala.math.{ceil, sqrt}
import collection.mutable

object Math {

  def properDivisors(n: Int): Set[Int] = {

    val s = mutable.Set[Int](1)

    val step  = n%2 + 1
    val start = step + 1
    val stop  = ceil(sqrt(n.toDouble)).toInt

    // Alternate FP version
    // Range(start, stop, step).filter(i => n % i == 0).flatMap(i => Set(i, n/i)).toSet

    for (i <- start to stop by step) {
      if (n % i == 0) {
        s.add(i)
        s.add(n/i)
      }
    }

    s.toSet
  }

  def gcd(a: Int, b: Int): Int = {

    if (b==0) a
    else gcd(b, a%b)
  }

}
