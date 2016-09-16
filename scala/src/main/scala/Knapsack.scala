package com.jgdodson.algorithms

object Knapsack {

  def knapsack(items: Vector[(Int, Int)], w: Int): Vector[(Int, Set[Int])]  = {

    val subs = Array.tabulate[Int](w+1)(_ => 0)
    val sets = Array.tabulate[Set[Int]](w+1)(_ => Set[Int]())
 
    // Initialize with the first-item solution
    for (j <- 0 to w) {
      if ( items(0)._1 <= j ) {
        subs(j) = items(0)._2
        sets(j)  = Set(0)
      }
    }

    // Handle remaining items
    for (i <- Range(1, items.length)) {

      // Update sub-solutions to include the ith item
      for (j <- Range(w, 0, -1)) {

        // Only (attempt to) update sub-solution if item has suitable weight
        if (items(i)._1 <= j) {

          // Value when including item i
          val t = subs(j - items(i)._1) + items(i)._2;

          // Only change if including item i will increase knapsack value
          if (t > subs(j)) {
            subs(j) = t;
            sets(j) = sets(j - items(i)._1) + i;
          }
        }
      }
    }

    subs.zip(sets).toVector
  }

}
