import org.scalacheck.{Gen, Properties, Arbitrary}
import org.scalacheck.Prop.{forAll, BooleanOperators}

import math.Ordering
import com.jgdodson.algorithms.MaxHeap

// Refactor this into a class with a type parameter
abstract class MaxHeapTest[T](desc: String)(implicit ord: Ordering[T], arb1: Arbitrary[Array[T]], arb2: Arbitrary[T]) extends Properties(desc) {

  property("Max-Heap property is satisfied after init") = forAll { (arr: Array[T]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => ord.gteq(h.parentKey(i), h(i)))
  }

  property("max-heap-2") = forAll { (arr: Array[Int]) =>
    forAll(Gen.choose(0, arr.length)) { heapSize =>
      val h = MaxHeap(arr, heapSize)
      (1 until heapSize).forall(i => h.parentKey(i) >= h(i))
    }
  }

  property("Inserting increments heapSize by one") = forAll { (arr: Array[T], key: T) =>
    forAll(Gen.choose(0, arr.length - 1)) { heapSize =>
      val h = MaxHeap(arr, heapSize)
      h.insert(key)
      h.heapSize == heapSize + 1
    }
  }

  property("Popping decrements heapSize by one") = forAll { (arr: Array[T], key: T) =>
    forAll(Gen.choose(1, arr.length)) { heapSize =>
      val h = MaxHeap(arr, heapSize)
      h.pop()
      h.heapSize == heapSize - 1
    }
  }

}
