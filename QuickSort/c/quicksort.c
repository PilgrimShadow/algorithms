/*
File: quicksort.c
Auth: Jordan Dodson
Date: 8/15/2015 
Info: An implementation of quicksort as found in CLRS (3rd ed.)
*/

// Libraries
#include <stdio.h>   // puts, printf
#include <stdlib.h>  // atoi
#include <math.h>
#include <stdbool.h> // bool, true, false

// Prototypes
void swap      (int *arr, int i, int j);
void quicksort (int *arr, int p, int r);
void quicksort_k (int *arr, int p, int r, int k);
void insertion_sort(int *arr, int p, int r);
void quickinsort(int *arr, int p, int r, int k);
void randomized_quicksort (int *arr, int p, int r);
bool is_sorted(int *arr, int p, int r);
int* random_array(int len);
void show      (int* arr, int len);

void usage(void) {
  puts("Enter some integers to be sorted.");
}

int main(int argc, char* argv[]) {

  if (argc <= 1) {
    usage();
    return 0;
  }

  // Allocate space for the array to be sorted.
  // Remember that the first argument is the name
  // of the invoking program.
  int arr[argc-1];
  
  // Convert command line arguments to ints.
  for(int i=1; i<argc; i++) {
    arr[i-1] = atoi(argv[i]);
  }

  // Sort the array of ints.
  quicksort(arr, 0, argc-1);

  // Display the contents of the now-sorted array.
  show(arr, argc-1);
}

void swap(int *arr, int i, int j) {
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}

/**
  * Partitions the array into two sections: one with all elements less than the
  * pivot element and one with all elements greater.
  *
  * This is the heart of the quicksort algorithm.
  *
  * The closed interval [p, r] is partitioned.
  *
  * TODO: Optimization --> Start i at the index of the first element GEQ than the pivot!
  * Start j at the following index.
  * 
  */
int partition(int *arr, int p, int r) {

  int i, j, pivot;

  pivot = arr[r];
  i = p;

  for (j=p; j<r; j++) {
    if (arr[j] < pivot) {
      swap(arr, i, j);
      i++;
    }
  }

  swap(arr, i, r);
  return i;
}


// Performs in-line swaps. 
int partition2(int *arr, int p, int r) {

  // Allocate 4*32 = 128 bytes
  int i, j, pivot, tmp;

  pivot = arr[r];
  i = p;

  // r - p loops
  for (j=p; j<r; j++) {
    if (arr[j] < pivot) {

      // Swap arr[i] and arr[j]
      tmp = arr[i];
      arr[i] = arr[j];
      arr[j] = tmp;

      // Increment i
      i++;
    }
  }

  swap(arr, i, r);
  return i;
}

/**
  * Another version of the quicksort partition algorithm
  *
  * PRE: arr not NULL, p <= r
  * POST: p <= q <= r
  *
  *
  *
  * TODO: If args are passed in registers, would it be faster to just reuse p and r?
  */
int partition3(int *arr, int p, int r) {

  int j, t, pivot;

  // sorting half-open interval [p, r)
  r--;

  // Randomly select the offset of the pivot element d in [0, r-p]
  j = p + (rand() % (r - p + 1));

  // Move pivot element to end of array
  t = arr[j];
  pivot  = t;  // Since we already have it
  arr[j] = arr[r];
  arr[r] = t;

  // Won't overflow since last item is pivot itself
  while (arr[p] < pivot) {
    p++;
  }

  // Partition
  for (j=p+1; j<r; j++) {
    if (arr[j] < pivot) {
      // Swap
      t = arr[p];
      arr[p] = arr[j];
      arr[j] = t;

      p++;
    }
  }

  // Swap
  t = arr[p];
  arr[p] = arr[r];
  arr[r] = t;

  return p;
}


// Page 179
/**
  * A randomized version of the partition subroutine.
  * 
  * arr : The array to be partitioned
  * p   : The leftmost index of the region to partition (inclusive)
  * q   : The rightmost index of the region to partition (inclusive)
  */
int randomized_partition(int *arr, int p, int r) {

  int i, j, d, pivot;

  // Randomly select the offset of the pivot element d in [0, r-p]
  d = rand() % (r - p + 1);

  // Move pivot element to end of array
  swap(arr, p + d, r);

  pivot = arr[r];
  j = p;

  for (i=p; i<r; i++) {
    if (arr[i] <= pivot) {
      swap(arr, i, j);
      j++;
    }
  }

  swap(arr, j, r);

  return j;
}

/**
  * A recursive implementation of the quicksort algorithm.
  */
void quicksort(int *arr, int p, int r) {

  int q;

  if (p < r) {
    q = partition3(arr, p, r);
    quicksort(arr, p, q-1);
    quicksort(arr, q+1, r);
  }
}

void randomized_quicksort(int *arr, int p, int r) {

  int q;

  if (p < r) {
    q = randomized_partition(arr, p, r);
    randomized_quicksort(arr, p, q-1);
    randomized_quicksort(arr, q+1, r);
  }
}

bool is_sorted(int *arr, int p, int r) {

  int i;

  for (i=p+1; i<r; i++) {
    if (arr[i] > arr[i-1]) {
      return false;
    }
  }

  return true;
}


int* random_array(int len) {
  int i, *arr;
  arr = (int*) malloc(len*sizeof(int));

  for (i=0; i<len; i++) {
    arr[i] = rand();
  }

  return arr;
}


void show(int* arr, int len) {
  for (int i=0; i<len-1; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d\n", arr[len-1]);
}

// [p, r)
void insertion_sort(int* arr, int p, int r) {

  int i, j, t;

  for (i=p+1; i<r; i++) {
    t = arr[i];
    j = i-1;

    while ((j>=p) && (t < arr[j])) {
      arr[j+1]=arr[j];
      j--;
    }

    arr[j+1] = t;
  }
}


// Partition [p, r) down to intervals of length <= k
void quicksort_k(int *arr, int p, int r, int k) {

  int q;

  if (r-p > k) {
    q = partition3(arr, p, r);
    quicksort_k(arr, p, q, k);
    quicksort_k(arr, q+1, r, k);
  }
}

void quickinsort(int *arr, int p, int r, int k) {

  quicksort_k(arr, p, r, k);
  insertion_sort(arr, p, r);
}

