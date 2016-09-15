
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

