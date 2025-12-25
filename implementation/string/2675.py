# 문자열 반복, 각 문자를 R번씩 반복해 출력, 문자열 구현

T = int(input())
S = list()
l = list()

for i in range(T):
    i = input()
    S.append(i.split())

# print(S)

for i in range(T):  # 단어마다
    chars = list(S[i][1])  # 단어 각 문자 리스트
    # print(chars)

    for j in range(len(S[i][1])):
        print(chars[j] * int(S[i][0]), end="")
    print()
