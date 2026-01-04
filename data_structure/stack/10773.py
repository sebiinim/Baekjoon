# 10773 제로

import sys

k = int(sys.stdin.readline())

my_stack = []

for _ in range(k):
    n = int(sys.stdin.readline())
    if n == 0:
        my_stack.pop()
    else:
        my_stack.append(n)

print(sum(my_stack))
