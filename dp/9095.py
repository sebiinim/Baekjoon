# 9095 1, 2, 3 더하기

import sys

input = sys.stdin.readline

dp = [0] * 11

dp[1], dp[2], dp[3] = 1, 2, 4

for i in range(4, 11):
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3]

T = int(input())

for i in range(T):
    n = int(input())
    print(dp[n])

# 피드백
# dp를 할 때는 그 길이만큼 list를 [0] * 11로 만들어놓고 시작하자
