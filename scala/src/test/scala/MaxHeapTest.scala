
import org.scalacheck.Gen
import org.scalacheck.Properties
import org.scalacheck.Prop.{forAll, BooleanOperators}

import com.jgdodson.algorithms.MaxHeap

// Refactor this into a class with a type parameter
object MaxHeapTest extends Properties("MaxHeap") {

  property("Max-Heap property is satisfied after init [Boolean]") = forAll { (arr: Array[Boolean]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("Max-Heap property is satisfied after init [Byte]") = forAll { (arr: Array[Byte]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("Max-Heap property is satisfied after init [Short]") = forAll { (arr: Array[Short]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("Max-Heap property is satisfied after init [Int]") = forAll { (arr: Array[Int]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("Max-Heap property is satisfied after init [Float]") = forAll { (arr: Array[Float]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("Max-Heap property is satisfied after init [Double]") = forAll { (arr: Array[Double]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("Max-Heap property is satisfied after init [Char]") = forAll { (arr: Array[Char]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("Max-Heap property is satisfied after init [String]") = forAll { (arr: Array[String]) =>
    val h = MaxHeap(arr)
    (1 until arr.length).forall(i => h.parentKey(i) >= h(i))
  }

  property("max-heap-2") = forAll { (arr: Array[Int]) =>
    forAll(Gen.choose(0, arr.length)) { heapSize =>
      val h = MaxHeap(arr, heapSize)
      (1 until heapSize).forall(i => h.parentKey(i) >= h(i))
    }
  }

  property("Inserting increments heapSize by one") = forAll { (arr: Array[Int], key: Int) =>
    forAll(Gen.choose(0, arr.length - 1)) { heapSize =>
      val h = MaxHeap(arr, heapSize)
      h.insert(key)
      h.heapSize == heapSize + 1
    }
  }

  property("Popping decrements heapSize by one") = forAll { (arr: Array[Int], key: Int) =>
    forAll(Gen.choose(1, arr.length)) { heapSize =>
      val h = MaxHeap(arr, heapSize)
      h.pop()
      h.heapSize == heapSize - 1
    }
  }

}
