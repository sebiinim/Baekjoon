# 2164 카드2

# queue 이용해서 pop, insert하면 되겠다

import sys
from collections import deque

N = int(sys.stdin.readline())
q = deque(range(1, N + 1))


# for i in range(N):
#     queue.append(i + 1)
# print(queue)

while len(q) > 1:
    q.popleft()
    q.append(q.popleft())

print(q[0])

# 배운 점
# pop()은 리스트의 마지막 원소를 제거하고 pop(0)이 첫 번째를 제거
