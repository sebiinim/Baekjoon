# 1764 듣보잡

N, M = map(int, input().split())

listen = set()
see = set()

for i in range(N):
    listen.add(input())

for i in range(M):
    see.add(input())

listen_see = listen.intersection(see)

print(len(listen_see))
for name in sorted(listen_see):
    print(name)
