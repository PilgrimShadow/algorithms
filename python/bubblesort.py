'''
  AUTH: Jordan Dodson
  INFO: Implementation of bubblesort
'''

from helpers import swap

def bubblesort(arr):

  # To get us going
  swapped = True

  # The upper limit each bubbling pass
  j = len(arr) - 1

  # Keep bubbling until no swaps are performed.
  while swapped:

    # Reset for this pass
    swapped = False

    # Bubble values up through the unsorted range
    for i in range(0, j):
      if arr[i] > arr[i+1]:
        swap(arr, i, i+1)
        swapped = True

    # The largest value in arr[:j] bubbled to the top
    j -= 1

  # Return a reference to the now-sorted array
  return arr

