# 2805 나무 자르기

import sys

input = sys.stdin.readline

N, M = map(int, input().split())

heights = sorted(list(map(int, input().split())))

l = heights[0]
r = heights[-1]

cut = (l + r) // 2

ans = 0

while True:
    cut_sum = 0
    for h in heights:
        cut_sum += max(0, h - cut)

    if cut_sum > M:
        if cut > ans:
            ans = cut  # 정답 후보
            l = cut
            cut = (l + r) // 2  # cut 증가
        else:
            break
    elif cut_sum < M:
        r = cut
        cut = (l + r) // 2  # cut 감소
    else:
        ans = cut  # 정답 확정
        break

print(ans)

# 배운 점
# 목표를 이진 탐색할 수도 있다
