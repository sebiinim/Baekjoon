# 1920 수 찾기

import sys

input = sys.stdin.readline

N = int(input())

nums = list(map(int, input().split()))

M = int(input())

mums = list(map(int, input().split()))

snum = set(nums)

for m in mums:
    if m in snum:
        print(1)
    else:
        print(0)

# 배운 점
# set은 hash table 덕에 탐색 시간이 O(1)이다!
# binary_search로도 풀 수 있는데 일단 set으로 해결
