# 1654 랜선 자르기

import sys

input = sys.stdin.readline

K, N = map(int, input().split())

len_lines = []

for _ in range(K):
    len_lines.append(int(input()))

len_lines = sorted(len_lines)

l = 1

r = len_lines[-1]

ans = 0

mid = (l + r) // 2

sum_len_lines = 0

while l <= r:
    sum_len_lines = 0
    for k in range(K):
        sum_len_lines += len_lines[k] // mid

    if sum_len_lines < N:
        # ret 감소
        r = mid - 1
        mid = (l + r) // 2
        # print(f"dec: {ret}")

    else:
        # 종료 혹은 ret 증가
        l = mid + 1
        mid = (l + r) // 2
        # print(f"inc: {ret}")

print(mid)

# 배운 점
# l = 0 으로 초기화하자
# sum_len_lines 같은 합 변수는 매 반복마다 초기화해줘야 한다.
# 이진 탐색은 mid = (l + r) // 2 후에 l = mid + 1, r = mid - 1로 구현한다.
