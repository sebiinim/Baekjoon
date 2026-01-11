# 7576 토마토

# 첫 Gold 문제

import sys
from collections import deque

M, N = map(int, sys.stdin.readline().split())

tomatoes = []

for _ in range(N):
    tomatoes.append(list(map(int, sys.stdin.readline().split())))

# print(f"tomatoes: {tomatoes}")

# BFS를 써야겠죠


def valid_point(x, y):
    return 0 <= x < M and 0 <= y < N and tomatoes[y][x] == 0


q = deque()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

# 1인 점 찾고 시작
for y in range(N):
    for x in range(M):
        if tomatoes[y][x] == 1:
            q.append((x, y))

# BFS
while q:
    x, y = q.popleft()

    for i in range(4):
        if valid_point(x + dx[i], y + dy[i]):
            q.append((x + dx[i], y + dy[i]))
            tomatoes[y + dy[i]][x + dx[i]] = (
                tomatoes[y][x] + 1
            )  # 여기서 tomatoes값이 바뀌면 다음 valid_point는 통과하지 못해 enqueue 횟수가 적어짐

# print(f"tomatoes2: {tomatoes}")

for y in range(N):
    for x in range(M):
        if tomatoes[y][x] == 0:
            sys.stdout.write("-1")
            sys.exit()


ans = -1
for y in range(N):
    for x in range(M):
        ans = max(ans, tomatoes[y][x])

print(ans - 1)

# 피드백
# visited, dist같은 추가 배열이 필요 없었다
# 생각해보니 정보이론적으로 tomatoes에서 최댓값을 찾으려면 O(MN)이 필요하다.
