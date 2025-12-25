# 1181 단어 정렬

# N개의 단어 받아 길이 오름차순 -> 사전순 정렬, 중복은 제거

N = int(input())
words = []
for i in range(N):
    word = input()
    if word not in words:
        words.append(word)

# print(words)

# print(sorted(sorted(words, key=len)))
# print(sorted(words))
# print()
for x in sorted(sorted(words), key=len):
    print(x)

# 개선코드
# words = sorted(words, key=lambda w: (len(w), w))
# for x in words:
#     print(x)

# 배운 점
# sorted는 안정 정렬이다

# 피드백
# 중복 제거는 set이 잘 한다. words = set()하고 words.add(word)로 개선하자
# sorted의 lambda에 기준을 여러 개 넣을 수 있다. len(w)으로 먼저 길이비교하고 w로 사전비교 가능
