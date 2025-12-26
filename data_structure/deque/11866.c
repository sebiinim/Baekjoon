#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

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

int isFull(Queue *queue) { return queue->back == (MAX_SIZE - 1); }

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
  int N, K;
  scanf("%d %d", &N, &K);

  Queue queue;
  init(&queue);

  // 1부터 n까지 기본 세팅
  for (int i = 1; i <= N; ++i) {
    push(&queue, i);
  }
  // printf("init succeed\n");

  printf("<");
  int cnt = 1;      // K주기 반복 위한 변수, cnt/K 형태로 활용
  int returnValue;  // pop한 값을 저장
  while (size(&queue) > 0) {
    returnValue = pop(&queue);

    if (cnt % K == 0) {  // K번째면 출력하고 버리기
      if (size(&queue) == 0) {
        printf("%d", returnValue);  // 큐에 남은 원소가 없으면 쉼표 출력 안 함
      } else {
        printf("%d, ", returnValue);
      }
    } else {  // K번째 아니면 다시 push하기
      push(&queue, returnValue);
    }
    cnt++;
  }
  printf(">");

  return 0;
}
