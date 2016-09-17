import org.scalacheck.{Gen, Properties, Arbitrary}
import org.scalacheck.Prop.{forAll, BooleanOperators}

import math.Ordering

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
    // TODO: Use a multiset

    val before = Set(arr)
    sort(arr)
    val after = Set(arr)

    // Placeholder
    before == after
  }
}
