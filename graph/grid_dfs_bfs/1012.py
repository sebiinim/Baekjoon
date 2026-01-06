# 1012 유기농 배추

import sys
from collections import deque


def valid_point(x, y, M, N):
    return 0 <= x < M and 0 <= y < N and (not visited[y][x]) and ((x, y) in cabbages)


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def BFS(x, y, M, N):
    q = deque([(x, y)])
    visited[y][x] = True

    while q:
        (px, py) = q.popleft()
        for k in range(4):
            nx = px + dx[k]
            ny = py + dy[k]

            if valid_point(nx, ny, M, N):
                visited[ny][nx] = True
                q.append((nx, ny))


T = int(sys.stdin.readline())

for _ in range(T):
    M, N, K = map(int, sys.stdin.readline().split())

    visited = [[False for _ in range(M)] for _ in range(N)]
    # print(visited)

    cabbages = set()
    for _ in range(K):
        x, y = map(int, sys.stdin.readline().split())
        cabbages.add((x, y))

    cnt_earthworm = 0

    for y in range(N):
        for x in range(M):
            if valid_point(x, y, M, N):
                cnt_earthworm += 1
                BFS(x, y, M, N)

    sys.stdout.write(str(cnt_earthworm) + "\n")
