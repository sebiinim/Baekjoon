# 1018 체스판 다시 칠하기

import sys
import math

M, N = map(int, sys.stdin.readline().split())

chess_map = []

for _ in range(M):
    chess_map.append(sys.stdin.readline().strip())

# print(chess_map)


# 시작 위치 [i][k]와 그곳의 color를 받아 오른쪽 아래 8*8 chess map에서 바꿔야 할 색깔 수 찾기
def count_change_chess_map(i, j, start_color):
    count = 0
    for p in range(i, i + 8):
        for q in range(j, j + 8):
            if ((p - i) + (q - j)) % 2 == 0 and chess_map[p][q] != start_color:
                count += 1
            elif ((p - i) + (q - j)) % 2 == 1 and chess_map[p][q] == start_color:
                count += 1
    return count


# 첫번째 점 찍고 바꿔야하는 값 개수 찾기
ret = math.inf
for i in range(M - 7):
    for j in range(N - 7):
        temp = min(count_change_chess_map(i, j, "W"), count_change_chess_map(i, j, "B"))
        if temp <= ret:
            ret = temp
print(ret)

# 배운 점&피드백
# 시간복잡도는 O((M-7)(N-7)*64*2) = O(MN)
# x = count_change_chess_map을 한 번만 수행하고 min(x, 64-x)를 하면 계산량이 반이 된다.
