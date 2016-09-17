import org.scalacheck.{Gen, Properties, Arbitrary}
import org.scalacheck.Prop.{forAll, BooleanOperators}

import math.Ordering

// What can I reference in the argument to Properties?

abstract class GenericSortingTests[T](sort: Array[T] => Array[T], desc: String)(implicit ord: Ordering[T], arb: Arbitrary[Array[T]]) extends Properties(desc) {

  property("Sort the array [T]") = forAll { (arr: Array[T]) =>
    sort(arr)
    (0 until arr.length-1).forall( i => ord.lteq(arr(i), arr(i+1)) )
  }

}
