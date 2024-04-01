// 12789 도키도키 간식드리미
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10001

// Stack 구조체 생성
typedef struct {
  int data[MAX_SIZE];
  int top;
} Stack;

void init(Stack *stack) { stack->top = -1; }

int isEmpty(Stack *stack) { return stack->top == -1; }

int isFull(Stack *stack) { return stack->top == MAX_SIZE - 1; }

// push 명령, 기존 스택의 top 보다 하나 위에 데이터 저장
void push(Stack *stack, int item) {
  if (isFull(stack)) {
    printf("Stack Overflow\n");
    return;
  }
  stack->data[++stack->top] = item;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    return -1;
  }
  return stack->data[stack->top--];
}

int size(Stack *stack) { return stack->top + 1; }

int top(Stack *stack) {
  if (isEmpty(stack)) {
    return -1;
  }
  return stack->data[stack->top];
}

// 잘 되는 상태
int main() {
  int N;  // 총 학생 수
  scanf("%d", &N);
  int order = 1;        // 현재 받을 번호
  bool canGet = false;  // 받을 수 있는지

  Stack stack;
  init(&stack);

  int nowNum;  // 메인 줄 가장 앞 학생의 번호

  // 메인 줄 도는 부분
  for (int i = 0; i < N; ++i) {
    scanf("%d", &nowNum);

    // 지금 번호가 현재순서(order)이면 push하지 "않고" order 1 증가
    if (order == nowNum) {
      order++;
    } else {
      push(&stack, nowNum);
    }

    // 스택 최상단이 현재순서이면 pop하고 order 1 증가
    while ((!isEmpty(&stack)) && (order == top(&stack))) {
      pop(&stack);
      order++;
    }
  }

  if (isEmpty(&stack)) {
    canGet = true;
  }

  if (canGet) {
    printf("Nice\n");
  } else {
    printf("Sad\n");
  }

  return 0;
}