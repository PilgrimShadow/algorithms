'''Helper Functions


'''


def swap(arr, i, j):
  t = arr[i]
  arr[i] = arr[j]
  arr[j] = t

def is_ascending(arr):

  return all(arr[i] <= arr[i+1] for i in range(len(arr)-1))

def sort_test(sort_func, num_tests=100, max_length=1000):
  '''Test the quicksort implementation.

     num_tests -> number of tests to perform
     max_length -> max length of test arrays
  '''

  from random import randint

  # track how many tests were passed
  passed = 0

  # keeps track of progress bar
  progress = 0


  for i in range(num_tests):

    # generate a random array
    a = [randint(-10000, 10000) for _ in range(randint(0, max_length))]

    # sort the array with our quicksort method
    sort_func(a)

    # test that the array is sorted
    if is_ascending(a):
      passed += 1

    # progress bar
    if i / (num_tests / 10) > progress:
      progress += 1
      print('.', end='', flush=True)

  # display a summary of the tests
  print('Passed {:d} / {:d}'.format(passed, num_tests))
