'''The Knapsack Problem

  AUTH: Jordan Dodson
  DATE: 2016-9-12
  INFO: Solution of the 0/1 knapsack problem
'''


# items = [(weight, value)]
def knapsack(items, w):
  '''Solve the knapsack problem.'''

  # How to handle this error
  if len(items) == 0:
    pass

  # list of sub-solutions
  subs = []

  # item indices corresponding to each sub-solution
  sets = []

  # Initialize the array of sub-solutions with the first-item solution
  for j in range(w+1):
    if items[0][0] > j:
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

        # Optimal knapsack value when including item i
        t = subs[j - items[i][0]] + items[i][1]

        # Only change if including item i will increase knapsack value
        if t > subs[j]:
          subs[j] = t

          sets[j] = sets[j - items[i][0]].copy()
          sets[j].add(i)

  return list(zip(subs, sets))
