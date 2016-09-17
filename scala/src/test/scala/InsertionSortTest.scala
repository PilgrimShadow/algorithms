import org.scalacheck.Gen
import org.scalacheck.Properties
import org.scalacheck.Prop.{forAll, BooleanOperators}

import com.jgdodson.algorithms.InsertionSort.insertionSort

object InsertionSortTest extends Properties("InsertionSort") {

  property("Sort the array [Int]") = forAll { (arr: Array[Int]) =>
    insertionSort(arr)
    (0 until arr.length-1).forall(i => arr(i) <= arr(i+1))
  }

}
