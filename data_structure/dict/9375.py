# 9375 패션왕 신해빈

import sys
from collections import defaultdict

k = int(sys.stdin.readline())


def calc_comb():
    n = int(sys.stdin.readline())

    fashion_items = defaultdict(list)

    for _ in range(n):
        name, kind = sys.stdin.readline().split()
        fashion_items[kind].append(name)

    # print(fashion_items)

    # print(len(fashion_items))

    res = 1
    for v in fashion_items.values():
        res *= len(v) + 1

    return res - 1


for _ in range(k):
    print(calc_comb())

# 배운 점&피드백
# type은 예약어다..
# fashion_items.values() 를 직접 순회하는게 좋다
# 어차피 kind별 cnt만 필요하니 cnt만 저장해도 좋다
