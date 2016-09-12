

void insertion_sort(int* arr, int p, int r) {

  int i, j, t;

  for (i=p+1; i<r; i++) {
    j = i;
    t = arr[i];

    while ((j>p) && (arr[j] < arr[j-1])) {
      arr[j]=arr[j-1];
      j--;
    }

    arr[j] = t;
  }

}
