// 10828 스택
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
    // printf("-1\n");
    return -1;
  }
  return stack->data[stack->top];
}

int main() {
  int N;
  scanf("%d", &N);
  Stack stack;
  init(&stack);
  int pushNum;
  char command[10];

  for (int i = 0; i < N; i++) {
    scanf("%s", command);
    if (strcmp(command, "push") == 0) {
      scanf("%d\n", &pushNum);
      push(&stack, pushNum);
    } else if (strcmp(command, "pop") == 0) {
      printf("%d\n", pop(&stack));
    } else if (strcmp(command, "size") == 0) {
      printf("%d\n", size(&stack));
    } else if (strcmp(command, "empty") == 0) {
      printf("%d\n", isEmpty(&stack));
    } else if (strcmp(command, "top") == 0) {
      printf("%d\n", top(&stack));
    }
  }
  return 0;
}