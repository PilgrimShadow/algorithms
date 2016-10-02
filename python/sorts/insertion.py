'''Insertion Sort

'''

def insertion_sort(arr):
  '''Sort the array by insertion sort.'''

  _insertion_sort(arr, 0, len(arr))

  # Return a reference for chaining
  return arr

def _insertion_sort(arr, p, r):
  '''Sort the range [p, r) by insertion sort.'''

  for i in range(p+1, r):

    # the item being inserted
    t = arr[i]

    # index for testing insertion
    j = i-1

    while j >= p and t < arr[j]:
      arr[j+1] = arr[j]
      j -= 1

    # insert the item into its proper place
    arr[j+1] = t
  
