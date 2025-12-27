# 17219 비밀번호 찾기

import sys

N, M = map(int, sys.stdin.readline().split())

site_pw = {}
for _ in range(N):
    site, pw = sys.stdin.readline().split()
    site_pw[site] = pw

# print(site_pw)

for _ in range(M):
    site = sys.stdin.readline().strip()
    print(site_pw[site])

# 배운 점&피드백
# dict쓰는 기본 문제. 쉽구만!
