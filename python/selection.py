'''Selection sort

  AUTH: Jordan Dodson
  INFO: 
'''

from helpers import swap

def selection_sort(arr):
  '''Sort the array by selection sort'''

  _selection_sort(arr, 0, len(arr))
  return arr


def _selection_sort(arr, p, r):
  '''Sort the half-open interval [p, r) by selection sort'''

  for i in range(p, r-1):
    min_ind = i

    for j in range(i+1, r):
      if arr[j] < arr[min_ind]:
        min_ind = j

    swap(arr, i, min_ind)


