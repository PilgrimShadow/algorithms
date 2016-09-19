import org.scalacheck.{Gen, Properties, Arbitrary}
import org.scalacheck.Prop.{forAll, BooleanOperators}

import math.Ordering
import collection.mutable

/**
  * Base class for tests of array-sorting methods
  */
abstract class GenericSortingTests[T](sort: Array[T] => Array[T], desc: String)(implicit ord: Ordering[T], arb: Arbitrary[Array[T]]) extends Properties(desc) {

  property("The array is sorted") = forAll { (arr: Array[T]) =>

    sort(arr)
    (0 until arr.length-1).forall( i => ord.lteq(arr(i), arr(i+1)) )
  }

  property("Result array is equal to input array") = forAll { (arr: Array[T]) =>

    val res = sort(arr)
    res == arr
  }

  property("Length of original array is unchanged") = forAll { (arr: Array[T]) =>

    val original_length = arr.length
    sort(arr)
    original_length == arr.length 
  }

  property("Array contains the same elements") = forAll { (arr: Array[T]) =>

    def counter[T](arr: Array[T]): Map[T, Int] = {

      val counts = mutable.Map[T, Int]()

      for (x <- arr) {
        counts(x) = counts.getOrElse(x, 0) + 1
      }

      return counts.toMap
    }

    // Element count before sorting
    val before = counter(arr)

    // Sort the array
    sort(arr)

    // Element count after sorting
    val after = counter(arr)

    // Element count was not changed
    before == after
  }
}
