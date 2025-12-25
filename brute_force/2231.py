# 분해합
# M의 분해합이 N <=> M은 N의 생성자.
# e.g)245의 분해합은 256(254+2+5+4), 245는 256의 생성자.

N = int(input())  # 분해합이 N인 M 찾기
# brute-force로 1부터 N-1까지 다 분해합을 만들면서 N이 되는 M 찾기


# 분해합을 구하는 함수
def sepSum(n: int):
    l = list(str(n))
    ret = 0
    for i in l:
        ret += int(i)
    return n + ret


# brute-force
# printed = 0
for i in range(1, N):
    if N == sepSum(i):
        print(i)
        # printed = 1
        break

else:
    print(0)

# 피드백
# sepSum -> sep_sum 으로 이름 규칙 지키기
# sep_sum같은 자릿수 합은 n%10 으로 자릿수 낮춰가면서 더하는 식 구현이 좋다.
# printed라는 플래그 변수 대신 for-else문으로 break가 안 나왔을 경우에만 else 실행할 수 있다.
# brute-force쓰는 문제
