/*
  Selection sort

  AUTH: Jordan Dodson
  INFO: 
*/

void swap(int *arr, int i, int j) {
  int t = arr[i];
  arr[i] = arr[j];
  arr[j] = t;
}

// Sort the array by selection sort
void selection_sort(int *arr, int len) {

  _selection_sort(arr, 0, len);

  // Return a pointer to the now-sorted array
  return arr;
}

// Sort the half-open interval [p, r) by selection sort
void selection_sort(int *arr, int p, int r) {

  int min_ind, i, j;

  for (i=p; i<r-1; i++) {
    min_ind = i;

    for (j=i+1; j<r; j++) {
      if (arr[j] < arr[min_ind]) {
        min_ind = j;
      }
    }

    swap(arr, i, min_ind);
  }
}

