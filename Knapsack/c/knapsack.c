
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// What are some optimizations to reduce the number of subsolutions
// that must be solved? We can scale the weights so that the smallest is
// equal to one. Will scale the target by the same amount...The problem is resolution.
// It's about how many levels between the min and max. Values can be floats while
// weights remain ints. Could you give merely the weight-to-value ratio??? No. Any
// items with the same weight can be reduced to the one with the highest ratio. You can also
// divide all weights (and the target) by gcd(weights). Could you combine knapsack problems?
// What are some real-life applications where the entire sub-solution table is needed?

// What is required to handle floating-point weights?

void knapsack1 (int *weights, int *values, int *subs, int n, int w);
void knapsack2 (int *weights, int *values, int *subs, int n, int w);
void knapsack3 (int *weights, int *values, int *subs, int n, int w);
int  knapsack4 (int *weights, int *values, int *subs, int n, int w);
void knapsack_items_32 (const int *weights, const int *values, int *subs, int *sets, int n, int w);
void knapsack_item_vec_32 (const int *items, int *subs, int *sets, int n, int w);
int  knapsack32 (const int *weights, const int *values, int n, int w);

int main() {

  int weights[] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int values[]  = {13, 11, 2,  19, 4,  10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int subs[7];
  int sets[7];

  knapsack_items_32(weights, values, subs, sets, 15, 6);

  printf("knapsack32: %x\n", knapsack32(weights, values, 15, 6));

  printf("Calculation Complete\n");
  printf("%d %d %d %d %d %d %d\n", subs[0], subs[1], subs[2], subs[3], subs[4], subs[5], subs[6]);
  printf("%x %x %x %x %x %x %x\n", sets[0], sets[1], sets[2], sets[3], sets[4], sets[5], sets[6]);

  return 0;
}

// len(weights) == len(values) == n
// len(subs) == w+1
// weights > 0
// values  > 0
// n > 0
// w > 0
void knapsack1(int *weights, int *values, int *subs, int n, int w) {

  // TODO: OPT: Sort items by weight. Skip to first valid weight and
  // update with max(). No need to use if-statement to check weights after that.
  // Or just write a version that assumes input is thus sorted.

  // TODO: OPT: A loop is not required for the last item

  int i, j, t;

  // i - index of the item [0..N-1]
  // j - index of the 

  // Initialize with the first item
  for (j=0; j<=w; j++) {
    if (weights[0] > j) {
      subs[j] = 0;
    } else {
      subs[j] = values[0];
    }
  }

  // Iterate through items
  for (i=1; i<n; i++) {

    // Iterate through weight limits
    for (j=w; j>0; j--) {

      // No change if weight is too large
      if (weights[i] <= j) {

        // If we remove the zero column, must use an if-statement here
        // to check when weights[i] == j. This is to avoid negative indexing.

        // Value when including item i
        t = subs[j - weights[i]] + values[i];

        // Only change if candidate is larger
        if (t > subs[j]) {
          subs[j] = t;
        }
      }
    }
  }
}


// In this version, the index j corresponds to weight-1
// TODO: Ohhhhhh. I forgot. Keeping the zero at index zero is ok, since
// we are not working with a 2d-array!! And not having the if-statement
// will be faster, simpler
void knapsack2(int *weights, int *values, int *subs, int n, int w) {

  // TODO: OPT: Sort items by weight. Skip to first valid weight and
  // update with max(). No need to use if-statement to check weights after that.
  // Or just write a version that assumes input is thus sorted.

  // TODO: OPT: A loop is not required for the last item

  int i, j, t;

  // i - index of the item [0..N-1]
  // j - index of the 

  // Initialize with the first item
  for (j=0; j<w; j++) {
    if (weights[0] > j+1) {
      subs[j] = 0;
    } else {
      subs[j] = values[0];
    }
  }

  // TODO: DEBUG
  printf("%d %d %d %d\n", subs[0], subs[1], subs[2], subs[3]);

  // Iterate through items
  for (i=1; i<n; i++) {

    // Iterate through weight limits
    for (j=w-1; j>=0; j--) {

      // No change if weight is too large
      if (weights[i] <= j+1) {

        // If we remove the zero column, must use an if-statement here
        // to check when weights[i] == j+1. This is to avoid negative indexing.
        // The first column was holding a base case. (But multiple copies of it.)
        if (weights[i] == j+1) {
          t = values[i];
        } else {
          // Value when including item i
          t = subs[j - weights[i]] + values[i];
        }

        // Only change if candidate is larger
        if (t > subs[j]) {
          subs[j] = t;
        }
      }
    }

    // TODO: DEBUG
    printf("%d %d %d %d\n", subs[0], subs[1], subs[2], subs[3]);
  }

}

// Assumes items are sorted by weight (descending)
// What are the dynamics when ascending/descending? Is one more efficient?

// One advantage of using descending order is that you save the largest possible
// number of writes by skipping the last outer loop (since writes look like a lower
// triangle when items descend)

// There is still the problem of tracking which items correspond to each solution
// Could use a bit vector indicating which items are in the most recent solution?
void knapsack3(int *weights, int *values, int *subs, int n, int w) {

  int i, j, t;

  // Base case
  subs[0] = 0;

  j = 1;
  while ((weights[0] > j) && (j <= w)) {
    subs[j] = 0;
    j++;
  }

  for (;j<=w;j++) {
    subs[j] = values[0];
  }


  // Iterate through items
  for (i=1; i<n; i++) {

    j = w;

    // Will terminate since weights are >0
    // Furthermore, subs[0] will remain 0
    while (weights[i] <= j) {

      // Value when including item i
      t = subs[j - weights[i]] + values[i];

      // Only change if candidate is larger
      if (t > subs[j]) {
        subs[j] = t;
      }

      j--;
    }
  }
}

// Like version 3, but without the unnecessary last loop.
int knapsack4(int *weights, int *values, int *subs, int n, int w) {

  int i, j, t;

  // Base case
  subs[0] = 0;

  j = 1;
  while ((weights[0] > j) && (j <= w)) {
    subs[j] = 0;
    j++;
  }

  for (;j<=w;j++) {
    subs[j] = values[0];
  }


  // Iterate through items
  for (i=1; i<n-1; i++) {

    j = w;

    // Will terminate since weights are >0
    // Furthermore, subs[0] will remain 0
    while (weights[i] <= j) {

      // Value when including item i
      t = subs[j - weights[i]] + values[i];

      // Only change if candidate is larger
      if (t > subs[j]) {
        subs[j] = t;
      }

      j--;
    }
  }

  if (weights[i] <= w) {
    t = subs[w - weights[i]] + values[i];

    if (t > subs[j]) {
      subs[j] = t;
    }
  }

  return subs[w];
}


void knapsack5(int *items, int *subs, int n, int w) {

  int i, j, t;

  subs[0] = 0;

  // Initialize with the first item
  for (j=1; j<=w; j++) {
    if (items[0] > j) {
      subs[j] = 0;
    } else {
      subs[j] = items[1];
    }
  }

  // Iterate through items
  for (i=2; i<2*n; i+=2) {

    // Iterate through weight limits
    for (j=w; j>0; j--) {

      // No change if weight is too large
      if (items[i] <= j) {

        // If we remove the zero column, must use an if-statement here
        // to check when weights[i] == j. This is to avoid negative indexing.

        // Value when including item i
        t = subs[j - items[i]] + items[i+1];

        // Only change if candidate is larger
        if (t > subs[j]) {
          subs[j] = t;
        }
      }
    }
  }
}


// Keeps track of which items correspond to each solution
// Uses ints as bitvectors. Hence n<=32 (up to 32 items)
// len(subs) == len(sets) == w+1
// len(weights) == len(values) == n
void knapsack6(const int *weights, const int *values, int *subs, int *sets, int n, int w) {

  int i, j, t;

  // Base case
  subs[0] = 0;
  sets[0] = 0;

  // Now initialize the remaining one-item sub-solutions
  j = 1;

  // These sub-solutions do not include the first item
  while ((weights[0] > j) && (j <= w)) {
    subs[j] = 0;
    sets[j] = 0;
    j++;
  }

  // The remaining sub-solutions include the first item 
  for (;j<=w;j++) {
    subs[j] = values[0];
    sets[j] = 1;
  }

  // Iterate through the remaining items
  for (i=1; i<n; i++) {

    // Iterating in reverse through the sub-problems
    j = w;

    // Will terminate since weights are >0
    // Furthermore, subs[0] will remain 0
    while (weights[i] <= j) {

      // Knapsack value when including item i
      t = subs[j - weights[i]] + values[i];

      // Only change if including item i increases knapsack value
      if (t > subs[j]) {
        subs[j] = t;
        sets[j] = sets[j - weights[i]] | (1 << i);
      }

      // Continue to the next subproblem
      j--;
    }
  }
}

// items[] contains both weights AND values. Even indices store weights. The adjacent
// odd index contains the corresponding value.
void knapsack7(const int *items, int *subs, int *sets, int n, int w) {

  int i, j, t;

  // Base case
  subs[0] = 0;
  sets[0] = 0;

  // Now initialize the remaining one-item sub-solutions
  j = 1;

  // These sub-solutions do not include the first item
  while ((items[0] > j) && (j <= w)) {
    subs[j] = 0;
    sets[j] = 0;
    j++;
  }

  // The remaining sub-solutions include the first item 
  for (;j<=w;j++) {
    subs[j] = items[1];
    sets[j] = 1;
  }

  // Iterate through the remaining items
  for (i=2; i<2*n; i+=2) {

    // Iterating in reverse through the sub-problems
    j = w;

    // Will terminate since weights are >0
    // Furthermore, subs[0] will remain 0
    while (items[i] <= j) {

      // Knapsack value when including item i
      t = subs[j - items[i]] + items[i+1];

      // Only change if including item i increases knapsack value
      if (t > subs[j]) {
        subs[j] = t;
        sets[j] = sets[j - items[i]] | (1 << i);
      }

      // Continue to the next subproblem
      j--;
    }
  }
}

// A wrapper that handles some allocation
int Knapsack6(const int *weights, const int *values, int n, int w) {

  // Sub-solutions and correspondng item sets
  // ??? Would being adjacent (solutions and sets) in memory be easier
  // on the cache? A fun experiment!!!
  int *subs, *sets, ans;

  // Could be combined into a single malloc
  subs = malloc((w+1) * sizeof(int));
  sets = malloc((w+1) * sizeof(int));

  /*

  subs = malloc(2 * (w+1) * sizeof(int));
  sets = *subs[w+1]

  */


  // Do the work
  knapsack6(weights, values, subs, sets, n, w);

  ans = sets[w];

  // Will be a single free when only one malloc is used
  free(subs);
  free(sets);

  // Return the items in the optimal knapsack
  return ans;
}


int Knapsack7(const int *items, int n, int w) {

  int *subs, *sets, ans;

  // Could be combined into a single malloc
  subs = malloc((w+1) * sizeof(int));
  sets = malloc((w+1) * sizeof(int));

  // Do the work
  knapsack7(items, subs, sets, n, w);

  ans = sets[w];

  // Will be a single free when only one malloc is used
  free(subs);
  free(sets);

  // Return the items in the optimal knapsack
  return ans;
}


int Knapsack7(const int *items, int n, int w) {
