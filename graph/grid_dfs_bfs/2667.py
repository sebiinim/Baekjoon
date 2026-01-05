# 2667 단지번호붙이기

import sys
from collections import deque

N = int(sys.stdin.readline())

# houses = map(int, sys.stdin.readline().split())

houses = []

for _ in range(N):
    houses.append(sys.stdin.readline().rstrip())

# print("houses:", houses)

visited = [[False for _ in range(N)] for _ in range(N)]

# print("visited", visited)


def valid_point(nx, ny):
    a = 0 <= nx < N and 0 <= ny < N
    if not a:
        return False

    b = houses[nx][ny] == "1"
    c = not visited[nx][ny]

    return b & c


xs = [0, 0, -1, 1]
ys = [-1, 1, 0, 0]

q = deque()

danji_cnt = 0
danji_house_cnt_list = []

for i in range(N):
    for j in range(N):
        # print(f"{i}{j}")
        if valid_point(i, j):
            q.append([i, j])
            visited[i][j] = True
            danji_cnt += 1

            danji_house_cnt = 1
            while len(q) > 0:
                [x, y] = q.popleft()

                for k in range(4):
                    nx = x + xs[k]
                    ny = y + ys[k]

                    # print(f"[{nx}][{ny}]")
                    if valid_point(nx, ny):
                        danji_house_cnt += 1
                        q.append([nx, ny])
                        visited[nx][ny] = True
            danji_house_cnt_list.append(danji_house_cnt)

# print(visited)

sys.stdout.write(str(danji_cnt) + "\n")
sys.stdout.write("\n".join(map(str, sorted(danji_house_cnt_list))))

# 피드백&배운 점
# for문에서 i, j, k 등이 중복되어 있는지 확인하자
# sys.stdout.write를 애용하자.
# 파이썬 bool 논리는 and, or을 쓰자. &는 비트 연산자이다.
# 파이썬 and는 short-circuit이다
# 좌표는 list말고 tuple쓰자
# while q: 가 더 파이썬스럽다

# BFS를 쓰는 문제였다. xs, ys와 for k in range(4)를 기억하자.
