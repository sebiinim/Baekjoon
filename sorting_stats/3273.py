# 3273 두 수의 합

import sys

N = int(sys.stdin.readline())

nums = []

nums = sorted(list(map(int, sys.stdin.readline().split())))  # 입력 받고 바로 정렬

x = int(sys.stdin.readline())

# print(nums)

nums = list(filter(lambda n: n < x, nums))  # 구하는 값 x보다 큰 수는 자르기

# print(nums)

# 투 포인터 풀이 (O(NlogN))
l, r = 0, len(nums) - 1
count = 0

while l < r:
    s = nums[l] + nums[r]
    if s == x:
        count += 1
        l += 1
        r -= 1
    elif s < x:
        l += 1
    elif s > x:
        r -= 1
print(count)

# 배운 점 & 피드백
# 반복문 안에서 배열을 수정하면 안 된다
# 투 포인터라는 방법을 배웠다!
# 선형 구조 & 구간/쌍/합/길이 & 정렬됨 3가지 조건을 모두 만족 시 사용하자


# 시간 초과 1
# count = 0
# idx = 0
# for i in nums:
#     idx += 1
#     if i >= x:
#         continue
#     for j in nums[idx:]:
#         if i + j > x:
#             break
#         if i + j == x:
#             count += 1

# print(count)

# 시간 초과 2
# count = 0
# for i in nums:
#     if (x - i) in nums:
#         count += 1
#         nums.remove(x - i)    # <- 이건 그냥 틀렸다, 반복문 안에서 배열 수정은 금지

# print(int(count / 2))
