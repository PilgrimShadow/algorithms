'''
  AUTH: Jordan Dodson
  FILE: knapsack.py
  DATE: 2016-9-12
  INFO: Solution of the 0/1 knapsack problem
'''


# items = [(weight, value)]
def knapsack(items, w):

  # list of sub-solutions
  subs = []

  # set of item indices corresponding to each sub-solution
  sets = []

  # Initialize the array of sub-solutions with the first-item solution
  for j in range(w+1):
    if j < items[0][0]:
      subs.append(0)
      sets.append(set())
    else:
      subs.append(items[0][1])
      sets.append(set([0]))

  # Handle remaining items
  for i in range(1, len(items)):

    # Update sub-solutions to include the ith item
    for j in range(w, 0, -1):

      # Only (attempt to) update sub-solution if item has suitable weight
      if items[i][0] <= j:

        # Value when including item i
        t = subs[j - items[i][0]] + items[i][1];

        # Only change if including item i will increase knapsack value
        if t > subs[j]:
          subs[j] = t;
          sets[j] = sets[j - items[i][0]].union(set([i]));

  return list(zip(subs, sets))
