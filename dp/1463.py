# 1463 1로 만들기

dp_list = [-1] * 1000001

dp_list[1] = 0
dp_list[2] = 1
dp_list[3] = 1


# def dp_min(n: int):
#     for i in range(4, n + 1):
#         if i % 3 == 0:
#             dp_list[i] = min(1 + dp_list[i // 3], dp_list[i])
#         if i % 2 == 0:
#             dp_list[i] = min(1 + dp_list[i // 2], dp_list[i])

#         dp_list[i] = min(1 + dp_list[i - 1], dp_list[i])


N = int(input())

for i in range(4, N + 1):
    dp_list[i] = 1 + dp_list[i - 1]

    if i % 3 == 0:
        dp_list[i] = min(1 + dp_list[i // 3], dp_list[i])
    if i % 2 == 0:
        dp_list[i] = min(1 + dp_list[i // 2], dp_list[i])


print(dp_list[N])

# 피드백
# 파이썬에서 1e6 top-down은 재귀 스택 상 위험하다.
# 가급적 dp는 bottom-up을 쓰자.
# dp[i] = 1 + dp[i-1] 부터 하거나 처음 배열을 INF로 초기화하면 min 사용 가능
