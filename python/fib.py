# Iterate through fibonacci numbers less than n.
def fibs_less_than(n):
  a, b = 0, 1

  if a >= n:
    return

  while a < n:
    yield a
    a, b = b, a+b

