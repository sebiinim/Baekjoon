# 1874 스택 수열

import sys
from collections import deque

# [1 2 3 4 5 6 7 8]
# [1 2 3 4] / []
# [1 2] / [4 3]
# [1 2 5 6] / [4 3]
# [1 2 5] / [4 3 6]
# [1 2 5 7 8] / [4 3 6]
# [] / [4 3 6 8 7 5 2 1]

n = int(sys.stdin.readline())

source_list = deque()
for i in range(n):
    source_list.append(i + 1)

# print("source_list:", source_list)
# [4 3 6 8 7 5 2 1]
# [1 2 3 4 5 6 7 8]

# [3 1 2]
# [1 2 3]

# 각 수의 위치 찾기(오름차순)

target_list = []

for _ in range(n):
    target_list.append(int(sys.stdin.readline().strip()))

# print(target_list)

cur = 1

stack = []

res_list = []

valid_check = True

for num in target_list:
    while cur <= num:
        res_list.append("+")
        stack.append(cur)
        cur += 1

        # if num == stack[-1]:
        #     res_list.append("-")
        #     # print("-", stack.pop())
        #     stack.pop()
        # else:
        #     valid_check = False
        #     # print("NO")
    if stack[-1] == num:
        res_list.append("-")
        stack.pop()
    else:
        valid_check = False

    # else:
    #     while source_list and source_list[0] <= num:
    #         stack.append(source_list.popleft())
    #         res_list.append("+")
    #         # print("+", stack[-1])
    #     stack.pop()
    #     res_list.append("-")
    #     # print("-", stack.pop())

if valid_check:
    for i in res_list:
        print(i)
else:
    print("NO")

# for num in target_list:
#     if num in stack:
#         if num == stack[-1]:
#             print("-", stack.pop())
#             # stack.pop()
#         else:
#             print("NO")
#     else:
#         while source_list and source_list[0] <= num:
#             stack.append(source_list.pop(0))
#             print("+", stack[-1])
#         # stack.pop()
#         print("-", stack.pop())


# 피드백&배운 점
# if num in target_list 같은 코드는 복잡도가 O(len) = O(n) 이라서 쓰지 말자
#
