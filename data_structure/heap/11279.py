# 11279 최대 힙

import sys, heapq

input = sys.stdin.readline

heap = []

# 날먹같긴한데 라이브러리는 쓰는 게 좋으니까...

N = int(input())

for _ in range(N):
    x = int(input())

    if x == 0:
        if heap:
            print(-heapq.heappop(heap))
        else:
            print(0)

    else:
        heapq.heappush(heap, -x)


# 파이썬의 heapq는 최소 힙.
# 최대 힙은 부호 바꿔서 구현한다
