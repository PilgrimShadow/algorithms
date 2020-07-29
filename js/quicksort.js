function quicksort(arr) {

  _quicksort(arr, 0, arr.length);
}

/**
 * Sort an array in place using the quicksort algorithm
 *
 */
function _quicksort(arr, start, end) {

  if (end <= start) {
    return;
  }

  const middle = partition(arr, start, end);
  _quicksort(arr, start, middle);
  _quicksort(arr, middle + 1, end);

}

/**
 * 
 * Partitions the sub-array [start, end) around a pivot
 */
function partition(arr, start, end) {

  // i < middle => arr[i] < pivot
  let pivotIndex = start;
  const pivot = arr[end - 1];

  while (pivotIndex < end-1 && arr[pivotIndex] < pivot) {
    pivotIndex += 1;
  }
  
  for (let i=pivotIndex+1; i<end-1; i+=1) {
    if (arr[i] < pivot) {
      swap(arr, i, pivotIndex);
      pivotIndex += 1;
    }
  }

  // Swap pivot into place
  swap(arr, pivotIndex, end - 1);

  return pivotIndex;
}

function swap(arr, i, j) {
  const tmp = arr[j];
  arr[j] = arr[i];
  arr[i] = tmp;
}

module.exports.default = quicksort;
