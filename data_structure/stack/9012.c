// 9012 괄호
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
  int N;
  scanf("%d", &N);
  Stack stack;
  init(&stack);

  bool isVPS = true;

  for (int i = 0; i < N; i++) {
    init(&stack);
    isVPS = true;

    char words[100][60];
    scanf("%s", &words[i]);

    for (int j = 0; j < 60; j++) {
      if (words[i][j] == '(') {
        push(&stack, 1);
      } else if ((words[i][j]) == ')') {
        if (isEmpty(&stack)) {
          isVPS = false;
          break;
        } else {
          pop(&stack);
        }
      }
    }
    if (isVPS && (isEmpty(&stack))) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }

  return 0;
}