// 10845 큐
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10001

// Queue 구조체 생성
typedef struct {
  int data[MAX_SIZE];
  int front;
  int back;
} Queue;

void init(Queue *queue) {
  queue->front = 0;
  queue->back = -1;
}

int isEmpty(Queue *queue) { return queue->front > queue->back; }

int isFull(Queue *queue) { return queue->back == MAX_SIZE - 1; }

// push 명령, back에 이어붙이기
void push(Queue *queue, int item) {
  if (isFull(queue)) {
    printf("Queue Overflow\n");
    return;
  }
  queue->data[++queue->back] = item;
}

// pop 명령, front에서
int pop(Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  }
  return queue->data[queue->front++];
}

// size 명령, back숫자 + 1
int size(Queue *queue) { return queue->back - queue->front + 1; }

// front명령,
int front(Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  }
  return queue->data[queue->front];
}

// back 명령
int back(Queue *queue) {
  if (isEmpty(queue)) {
    return -1;
  }
  return queue->data[queue->back];
}

int main() {
  int N;
  scanf("%d", &N);
  Queue Queue;
  init(&Queue);
  int pushNum;
  char command[10];

  for (int i = 0; i < N; i++) {
    scanf("%s", command);
    if (strcmp(command, "push") == 0) {
      scanf("%d\n", &pushNum);
      push(&Queue, pushNum);
    } else if (strcmp(command, "pop") == 0) {
      printf("%d\n", pop(&Queue));
    } else if (strcmp(command, "size") == 0) {
      printf("%d\n", size(&Queue));
    } else if (strcmp(command, "empty") == 0) {
      printf("%d\n", isEmpty(&Queue));
    } else if (strcmp(command, "front") == 0) {
      printf("%d\n", front(&Queue));
    } else if (strcmp(command, "back") == 0) {
      printf("%d\n", back(&Queue));
    }
  }
  return 0;
}