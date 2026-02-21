# 1715 카드 정렬하기

import sys, heapq

input = sys.stdin.readline

# 최솟값 뽑아서 계속 더하기

N = int(input())

heap = []  # 최소 힙

for _ in range(N):
    heapq.heappush(heap, int(input()))

if N == 1:
    print(0)
    sys.exit(0)

elif N == 2:
    print(heapq.heappop(heap) + heapq.heappop(heap))
    sys.exit(0)

ans = 0
while len(heap) >= 2:
    a = heapq.heappop(heap)
    b = heapq.heappop(heap)

    ans += a + b
    heapq.heappush(heap, a + b)
    # print(ans, heap)

# print(heap)

print(ans)

# 피드백
# 최소 힙을 사용하는 문제였다
# 처음에 문제 이해를 잘못했고 방법 떠올리기도 늦어서 꽤 오래 걸린 문제
