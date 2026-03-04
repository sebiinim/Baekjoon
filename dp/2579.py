# 2579 계단 오르기

import sys

input = sys.stdin.readline

N = int(input())

stairs = [0]

# 도착점부터 각 계단에서의 최고 점수 저장

for i in range(N):
    stairs.append(int(input()))

dp = [0] * 303

if N < 3:
    print(sum(stairs))
    sys.exit(0)


dp[1] = stairs[1]
dp[2] = stairs[1] + stairs[2]
dp[3] = max(stairs[1], stairs[2]) + stairs[3]

for i in range(4, N + 1):
    dp[i] = max(dp[i - 2] + stairs[i], dp[i - 3] + stairs[i - 1] + stairs[i])

# for i in range(1, N + 1):
#     print(stairs[i], end=", ")
# print()

# for i in range(1, N + 1):
#     print(dp[i], end=", ")

print(dp[N])


# 피드백
# dp 시에는 예외 상황(입력이 1, 2개 뿐)을 고려해서 처리하자
