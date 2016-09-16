
import org.scalacheck.Gen
import org.scalacheck.Properties
import org.scalacheck.Prop.{forAll, BooleanOperators}

import myHeap.MaxHeap

object MaxHeapTest extends Properties("MaxHeap") {

  property("max-heap-1") = forAll { (arr: Array[Int]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("max-heap-2") = forAll { (arr: Array[Int]) =>
    forAll(Gen.choose(0, arr.length)) { heapSize =>
      val h = MaxHeap(arr, heapSize)
      (1 until heapSize).forall(i => h.parentKey(i) >= h(i))
    }
  }

  property("heap-insert-1") = forAll { (arr: Array[Int], key: Int) =>
    forAll(Gen.choose(0, arr.length - 1)) { heapSize =>
      val h = MaxHeap(arr, heapSize)
      h.insert(key)
      h.heapSize == heapSize + 1
    }
  }


}
