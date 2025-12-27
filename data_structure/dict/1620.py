# 1620 나는야 포켓몬 마스터 이다솜

import sys

N, M = map(int, sys.stdin.readline().split())

pokedex = {}
quizzes = []

for i in range(N):
    pokedex[i + 1] = sys.stdin.readline().strip()

reversed_pokedex = {v: k for k, v in pokedex.items()}

for _ in range(M):
    quizzes.append(sys.stdin.readline().strip())

for quiz in quizzes:
    if quiz.isdigit():
        print(pokedex[int(quiz)])
    else:
        print(reversed_pokedex[quiz])
