# 2178 미로 탐색

import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split())

maze = []
for _ in range(N):
    maze.append(list(sys.stdin.readline().strip()))

# print(maze)

q = deque()


dx = [-1, 1, 0, 0]  # 상, 하
dy = [0, 0, -1, 1]  # 좌, 우

visited = [[0 for _ in range(M)] for _ in range(N)]
dist = [[1 for _ in range(M)] for _ in range(N)]


def valid_point(nx, ny):
    a = 0 <= nx < N and 0 <= ny < M
    if not a:
        return False
    b = maze[nx][ny] == "1"
    c = not visited[nx][ny]
    # print(f"[{nx}][{ny}] = {a},{b},{c}")
    # return (
    #     (0 <= nx < N and 0 <= ny < M) and (maze[nx][ny] == 1) and (not visited[nx][ny])
    # )
    return a and b and c


q.append([0, 0])
visited[0, 0] = 1

while len(q) > 0:
    [x, y] = q.popleft()  # 가장 왼쪽 원소 pop, 방금 append한 시작점 [0, 0]
    # print(
    #     f"dist[{x}][{y}] = {dist[x][y]}",
    # )

    # pop한 좌표가 도착점이면 break
    if x == N - 1 and y == M - 1:
        print(dist[x][y])
        break

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        # print(valid_point(nx, ny))
        # 갈 수 있는 칸인지 확인
        if valid_point(nx, ny):

            q.append([nx, ny])
            visited[nx][ny] = 1
            dist[nx][ny] = dist[x][y] + 1

print(dist[N - 1][M - 1])

# BFS 연습하기
# 큐, 미로를 리스트로 저장, 방문 체크, 거리 계산, 방향 벡터 필요
# 시작 칸을 큐에 넣기&방문 처리, 큐에서 꺼내고 상하좌우 탐색(미로 안인가, 벽이 아닌가, 방문했는가)
# 가능하면 큐에 넣고 방문처리, 큐가 빌 때까지 반복
