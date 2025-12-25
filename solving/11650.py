# 11650 좌표 정렬하기

# 2차원 평면 위 점 N개, x좌표->y좌표 순서 오름차순 정렬

N = int(input())
points = []

for _ in range(N):
    x, y = map(int, input().split())
    points.append((x, y))

# print(points)

sorted_points = sorted(sorted(points, key=lambda y: y[1]), key=lambda x: x[0])
# sorted_points = sorted(points, key = lambda p: (p[0], p[1]))    # 이렇게 쓰면 x, y순이다.
# sorted_points = sorted(points)    # 튜플에 그냥 sorted쓰면 알아서 x, y순으로 오름차순 정렬 해준단다...
# print(sorted_points)

for x, y in sorted_points:
    print(x, y)

# 배운 점
# sorted와 key=lambda를 사용해 리스트, 튜플을 원하는 원소 기준으로 정렬할 수 있다.
# 한 줄에 여러 정수 입력을 받을 때는 x, y = map(int, input().split()) 을 쓰자. 3개면 x, y, z
