'''Insertion Sort


'''

def insertion_sort(arr):
  '''Sort the array by insertion sort.'''

  _insertion_sort(arr, 0, len(arr))

  # Return a reference for chaining
  return arr

def _insertion_sort(arr, p, r):
  '''Sort the given slice of the array by insertion sort.'''

  for i in range(p+1, r):
    t = arr[i]
    j = i-1

    while j >= p and t < arr[j]:
      arr[j+1] = arr[j]
      j -= 1

    arr[j+1] = t
  
