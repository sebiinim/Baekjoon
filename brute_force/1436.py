# 1436 영화감독 숌

# 6이 적어도 3개 이상 연속으로 들어가는 수

# 666, 1666, 2666, ..., 6661, 6662, ..., 6666,

import sys

N = int(sys.stdin.readline())

k = 0
devil_num = []

while len(devil_num) < N:
    k += 1
    if "666" in str(k):
        devil_num.append(k)

print(devil_num[-1])

# 시간복잡도 = k*logk
# str(k)와 666 in str이 각각 logk 이다.
# 전체 반복을 k번정도 한다.
