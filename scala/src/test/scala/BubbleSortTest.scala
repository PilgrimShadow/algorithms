import org.scalacheck.Gen
import org.scalacheck.Properties
import org.scalacheck.Prop.{forAll, BooleanOperators}

import com.jgdodson.algorithms.BubbleSort.bubbleSort

object BubbleSortTest extends Properties("BubbleSort") {

  property("Sort the array [Int]") = forAll { (arr: Array[Int]) =>
    bubbleSort(arr)
    (0 until arr.length-1).forall(i => arr(i) <= arr(i+1))
  }


  property("Length of original array is unchanged") = forAll { (arr: Array[Int]) =>

    val original_length = arr.length

    bubbleSort(arr)

    original_length == arr.length 
  }
  
  property("Returned array is equal to input array") = forAll { (arr: Array[Int]) =>
    val ret = bubbleSort(arr)

    ret == arr
  }
}
