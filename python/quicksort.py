'''Quicksort

  AUTH: Jordan Dodson
  INFO: Implementation of quicksort for instructive purposes.
'''

from helpers import swap, sort_test

def quicksort(arr):
  '''Sort the array by quicksort'''
  _quicksort(arr, 0, len(arr))


def _quicksort(arr, p, r):
  '''Sort the range [p, r) recursively'''

  if r - p > 1:
    q = partition(arr, p, r)
    _quicksort(arr, p, q)
    _quicksort(arr, q+1, r)


def partition(arr, p, r):
  '''Partition the range [p, r) around a pivot'''

  pivot = arr[r-1]
  i = p

  while arr[i] < pivot:
    i += 1

  for j in range(i+1, r-1):
    if arr[j] < pivot:
      swap(arr, i, j)
      i += 1

  # Swap pivot element into place
  swap(arr, i, r-1)

  # Return the partition index
  return i


if __name__ == '__main__':
  sort_test(quicksort, 1000, 1000)
