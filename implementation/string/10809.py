# 각 알파벳이 처음 등장하는 위치 찾기
# 있으면 그 인덱스 번호, 없으면 -1

# 문자열 입력
S = input()

# 위치 인덱스
index = list()

# 위치 찾기
for c in range(97, 123):
    i = chr(c)
    index.append(S.find(i))


for c in index:
    print(c, end=" ")
