# 2750 수 정렬하기

# N개의 수 받아서 정렬하기
N = int(input())  # 바로 int를 붙이는게 정수 입력받는 의미가 직관적
# l = list()    # l은 1, i, I랑 헷갈리는 최악의 변수명, 숫자 list는 nums로 쓰자
nums = []  # list() 대신 [] 사용
for i in range(N):
    nums.append(int(input()))

# print(N)
# print(l)

for i in sorted(nums):
    print(i)

# 피드백
# 위에 써뒀다
# 정렬 문제
