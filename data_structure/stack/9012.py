# 9012 괄호

import sys

k = int(sys.stdin.readline())


def vps(ps):
    res = 0
    for i in ps.strip():
        if i == "(":
            res += 1
            # print(res)
        else:
            res -= 1
            # print(res)
            if res < 0:
                return False
    return True if res == 0 else False


for _ in range(k):
    ps = sys.stdin.readline()
    print("YES") if vps(ps) else print("NO")

# 배운 점&피드백
# return res == 0 이 가장 파이썬스럽다
# 여기선 res라는 counter가 stack 역할이었고 괄호 종류가 늘어난다면 stack 필요
