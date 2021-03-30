import random
tc = 5000000
print(tc)
for i in range(tc - 1):
  x = random.randint(0, tc - 1)
  y = random.randint(0, tc - 1)
  print(x, y)