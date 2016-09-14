'''
  AUTH: Jordan Dodson
  INFO: Implementation of quicksort in Python
'''


def quicksort(arr):
  _quicksort(arr, 0, len(arr)-1)


def _quicksort(arr, p, r):
  '''Sort the closed interval [p, r] recursively'''

  if p < r:
    q = partition(arr, p, r)
    _quicksort(arr, p, q-1)
    _quicksort(arr, q+1, r)


def partition(arr, p, r):

  pivot = arr[r]
  i = p

  while arr[i] < pivot:
    i += 1

  for j in range(i+1, r):
    if arr[j] < pivot:
      swap(arr, i, j)
      i += 1

  swap(arr, i, r)

  return i


def swap(arr, i, j):
  t = arr[i]
  arr[i] = arr[j]
  arr[j] = t
