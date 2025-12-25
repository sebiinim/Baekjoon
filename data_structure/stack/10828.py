# 10828 스택

import sys

stack = []

N = int(sys.stdin.readline())

for _ in range(N):
    command = sys.stdin.readline().split()
    if command[0] == "push":
        stack.append(int(command[1]))
    elif command[0] == "pop":
        print(stack.pop() if stack else -1)
        # if len(stack) == 0:
        #     print(-1)
        #     continue
        # print(stack.pop())
    elif command[0] == "size":
        print(len(stack))
    elif command[0] == "empty":
        print(0 if stack else 1)
        # if len(stack) == 0:
        #     print(1)
        # else:
        #     print(0)
    elif command[0] == "top":
        print(stack[-1] if stack else -1)
        # if len(stack) == 0:
        #     print(-1)
        #     continue
        # print(stack[-1])

# print(stack)

# 배운 점 & 피드백
# python으로 BOJ 할 때는 input() 말고 import sys; sys.stdin.readline()을 사용하자. 속도 차이가 매우 큰가보다
# 출력도 out=[]; sys.stdout.write("\n".join(out)) 으로 해보자.
