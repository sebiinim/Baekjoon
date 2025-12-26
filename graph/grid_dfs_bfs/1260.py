# 1260 DFS와 BFS

import sys
from collections import deque


N, M, V = map(
    int, sys.stdin.readline().split()
)  # 정점의 개수 N, 간선의 개수 M, 시작 정점 V

edges = [[] for _ in range(N + 1)]
for _ in range(M):
    x, y = map(int, sys.stdin.readline().split())
    edges[x].append(y)
    edges[y].append(x)

for i in range(len(edges)):
    edges[i].sort()

# print("edges:", edges)


# DFS
# 첫 점을 스택에 넣고 차례로 방문

s = deque()
s.append(V)

visited = [False] * (N + 1)

while s:
    node = s.pop()
    if visited[node]:
        continue
    visited[node] = True
    print(node, end=" ")

    # print("node:", node, end=" ")
    # visited.append(node)
    # print("visited:", visited, end=" ")

    # print("edges:", edges[node], end=" ")
    for i in reversed(edges[node]):
        if not visited[i]:
            s.append(i)
    # print("s:", s)
print()

# BFS
# 첫 점을 큐에 넣고 차례로 방문

q = deque()
q.append(V)

visited = [False] * (N + 1)

while q:
    node = q.popleft()
    if visited[node]:
        continue
    visited[node] = True
    print(node, end=" ")

    for i in edges[node]:
        if not visited[i]:
            q.append(i)
    # print("q:", q, end=" ")
    # print("visited:", visited)

# 배운 점
# sorted는 iterator를 반환한다. for같은 반복문에선 좋은데 list가 필요하면 list() 쓰자.
# DFS는 stack, BFS는 queue를 쓴다.
