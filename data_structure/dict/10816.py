# 10816 숫자 카드 2

from collections import defaultdict

N = int(input())
cards = defaultdict(int)

cards_input = map(int, input().split())
for x in cards_input:
    cards[x] += 1
    # cards[x] = cards.get(x, 0) + 1 라고 하면 defaultdict 아니어도 가능!

# print(cards)

M = int(input())
nums = map(int, input().split())

for num in nums:
    print(cards.get(num, 0), end=" ")

# print(" ".join(str(cards[num]) for num in nums))

# 배운 점
# 여러 줄 입력은 map과 split 써서 처리하자

# 피드백
# defaultdict 없이 그냥 dict로도 가능하긴 함.
# print에 join섞어서 하는것도 배워보자
