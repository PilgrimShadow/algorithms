'''
  AUTH: Jordan Dodson
  INFO: 
'''

def selection_sort(arr):
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


def swap(arr, i, j):
  t = arr[i]
  arr[i] = arr[j]
  arr[j] = t
