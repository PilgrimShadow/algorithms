/*
File: heap.c
Auth: Jordan Dodson
Date: 8/21/2015
Info: A simple implementation of a heap following the code in CLRS.
*/

#include <stdlib.h>

// Macros for computing parent and child indices
#define PARENT(i) ((i-1) / 2)
#define LEFT(i) (2*i + 1)
#define RIGHT(i) (2*(i+1))

void swap(int* arr, int i, int j) {
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}


typedef struct {
  int size, length;
  int* arr;
} Heap;


Heap* createHeap(int length) {
  Heap* h = (Heap *) malloc(sizeof(Heap));
  h->arr  = (int *)  malloc(length * sizeof(int));
  h->size = 0;
  h->length = length;
  return h;
}


void maxHeapify(Heap* h, int i) {
  int l, r, largest;

  l = LEFT(i);
  r = RIGHT(i);
  
  if (l < h->size) {
    if (h->arr[l] > h->arr[i]) {
      largest = l;
    } else {
      largest = i;
    }

    if (r < h->size && h->arr[r] > h->arr[largest]) {
      largest = r;
    }

    if (largest != i) {
      swap(h->arr, i, largest);
      maxHeapify(h, largest);
    }
  }  
}

// An implementation of maxHeapify without recursion
// Could use the sliding method of insertion sort here
void maxHeapifyLoop(Heap* h, int i) {

  // Indices of the left child, right child, and the node
  // with the largest key
  int l, r, largest;

  // The index of the last interior node
  const int stop = PARENT(h->size - 1);

  // Go until we reach the parent of the last element.
  // It is the last element with any children.
  while (i <= stop) {

    l = LEFT(i);
    r = RIGHT(i);

    if (l < h->size && h->arr[l] > h->arr[i]) {
      largest = l;
    } else {
      largest = i;
    }

    if (r < h->size && h->arr[r] > h->arr[largest]) {
      largest = r;
    }

    if (largest != i) {
      swap(h->arr, i, largest);
      i = largest; // largest will be greater than i
    } else {
      break;  // No more work needed
    }
  }
}


// Build a max heap
void buildMaxHeap(Heap* h) {
  int start = PARENT(h->size - 1);

  for (int i = start; i >= 0; i--) {
    maxHeapify(h, i);
  }
}


// Insert an item into a heap while preserving the heap-property.
void heap_insert(Heap* h, int item) {
  int i;

  h->arr[h->size] = item;
  i = h->size;
  h->size++;

  // Float the element up
  while (i != 0 && item > h->arr[PARENT(i)]) {
    swap(h->arr, i, PARENT(i));
    i = PARENT(i);
  }
}

void heap_insert2(Heap* h, int item) {

  int i;

  h->arr[h->size] = item;
  i = h->size;
  h->size++;

  // Use the sliding technique of insertion sort.
  while (i > 0 && item > h->arr[PARENT(i)]) {
    h->arr[i] = h->arr[PARENT(i)];
    i = PARENT(i);
  }

  // Insert the new item in its proper place
  h->arr[i] = item;
}

int heap_max(const Heap* h) {
  return h->arr[h->size - 1];
}

int heap_extract_max(Heap* h) {
  int max;

  max = h->arr[0];
  h->arr[0] = h->arr[h->size-1];
  h->size--;
  maxHeapify(h, 1);

  return max;
}

void heap_delete(Heap* h, int i) {

  // To remove the last element, just decrement the size
  if (i == h->size - 1) {
    h->size--;
  } else {
    h->arr[i] = h->arr[h->size - 1];
    h->size--;
    maxHeapify(h, i); 
  }
}
