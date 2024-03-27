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
    // printf("-1\n");
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

int main() {
  int N;  // 총 학생 수
  scanf("%d", &N);
  int order = 1;       // 현재 받을 번호
  bool canGet = true;  // 받을 수 있는지

  Stack stack;
  init(&stack);
  // printf("stacksize : %d\n", size(&stack));

  int nowNum;  // 메인 줄 가장 앞 학생의 번호

  // 메인 줄 도는 부분
  for (int i = 0; i < N; ++i) {
    scanf("%d", &nowNum);

    if (order == nowNum) {
      order++;
      // printf("order\n");
    } else {
      if ((!isEmpty(&stack)) && (top(&stack) == nowNum)) {
        pop(&stack);
        order++;
      }
      push(&stack, nowNum);
    }

    while ((!isEmpty(&stack)) && (order == top(&stack))) {
      pop(&stack);
      order++;
    }
  }

  if (isEmpty(&stack)) {
    printf("Nice\n");
    return 0;
  }

  // 서브 줄이 빠질 수 있는지
  int finalSize = size(&stack);  // 서브 줄 사람 수
  // printf("finalSize : %d\n", finalSize);
  int prenum = pop(&stack);  // 서브 줄 최상단 값 미리 저장해두기
  while (finalSize--) {
    if (prenum > pop(&stack)) {
      canGet = false;
      break;
    }
  }

  if (canGet) {
    printf("Nice\n");
  } else {
    printf("Sad\n");
  }

  return 0;
}