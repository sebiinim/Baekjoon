# 10814 나이순 정렬

import sys

N = int(sys.stdin.readline())

users = []

for _ in range(N):
    age, name = sys.stdin.readline().split()
    age = int(age)
    users.append([age, name])

# print(users)

sorted_users = sorted(users, key=lambda x: x[0])

# print(sorted_users)

for user in sorted_users:
    print(user[0], user[1])

# 배운 점&피드백
# 파이썬의 sort는 안정 정렬이므로 이미 가입 순서로 정렬되어 있는 리스트에
# 나이순 정렬을 추가 적용하면 나이가 같을 때 가입 순서 정렬은 유지된다.
