import com.jgdodson.algorithms.Quicksort.quicksort

class quicksortTestBoolean extends GenericSortingTests[Boolean](quicksort[Boolean], "quicksort [Boolean]")

class quicksortTestByte extends GenericSortingTests[Byte](quicksort[Byte], "quicksort [Byte]")

class quicksortTestShort extends GenericSortingTests[Short](quicksort[Short], "quicksort [Short]")

class quicksortTestInt extends GenericSortingTests[Int](quicksort[Int], "quicksort[Int]")

class quicksortTestLong extends GenericSortingTests[Long](quicksort[Long], "quicksort [Long]")

class quicksortTestFloat extends GenericSortingTests[Float](quicksort[Float], "quicksort [Float]")

class quicksortTestDouble extends GenericSortingTests[Double](quicksort[Double], "quicksort [Double]")


class quicksortTestChar extends GenericSortingTests[Char](quicksort[Char], "quicksort [Char]")

class quicksortTestString extends GenericSortingTests[String](quicksort[String], "quicksort [String]")
