# 2798 블랙잭

# 입력:
# 첫째 줄에 카드의 개수 N, 목표 숫자 M
# 둘째 줄에 카드에 쓰인 수들(N개)

# 출력:
# M을 넘지 않으면서 M에 가장 가까운 카드 3장의 합 구하기

# 입력받기
N, M = input().split()
N = int(N)
M = int(M)

# card_nums = list()
# l = input().split()
# for i in range(len(l)):
#     card_nums.append(int(l[i]))

card_nums = list(
    map(int, input().split())
)  # 입력 파싱을 이렇게 할 수 있다. 꼭 배워두자

# print(card_nums)

# ret = 0
# for i in range(0, N - 2):
#     for j in range(i + 1, N - 1):
#         s = card_nums[i]
#         if (s + card_nums[j]) > M:
#             continue
#         s += card_nums[j]
#         for k in range(j + 1, N):
#             if (s + card_nums[k]) > M:
#                 continue
#             else:
#                 ret = max(ret, s + card_nums[k])

best = 0
for i in range(0, N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            s = card_nums[i] + card_nums[j] + card_nums[k]
            if s <= M and s > best:
                best = s

print(best)


# 피드백
# 파이썬 내장함수인 sum을 변수명으로 썼다.
# 불필요한 가지치기가 많다. 3개 다 더해서 마지막에 검사해 조건을 모아 실수를 줄이자.
