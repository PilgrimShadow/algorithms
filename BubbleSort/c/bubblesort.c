/*
  AUTH: Jordan Dodson
  INFO: Implementation of bubblesort
*/

void bubblesort(int* arr, int len) {

  // All of our local variables
  int i, j, swapped;

  // To get us going
  swapped = 1;

  // The upper limit each bubbling pass
  j = len - 1;

  // Keep bubbling until no swaps are performed.
  while (swapped) {

    // Reset for this pass
    swapped = 0;

    // Bubble values up through the unsorted range
    for (i=0; i<j; i++) {
      if (arr[i] > arr[i+1]) {
        swap(arr, i, i+1);
        swapped = 1;
      }
    }

    // The largest value in arr[:j] bubbled to the top
    j--;
  }

  // Return a reference to the now-sorted array
  return arr;
}

void swap(int* arr, int i, int j) {
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}
