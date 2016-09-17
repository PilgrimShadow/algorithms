
import org.scalacheck.Gen
import org.scalacheck.Properties
import org.scalacheck.Prop.{forAll, BooleanOperators}

import com.jgdodson.algorithms.Quicksort.quicksort

object QuicksortTest extends Properties("Quicksort") {

  property("Sort the array [Int]") = forAll { (arr: Array[Int]) =>
    quicksort(arr)
    (0 until arr.length-1).forall(i => arr(i) <= arr(i+1))
  }

}
