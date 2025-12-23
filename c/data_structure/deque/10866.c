// 10866 덱
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10001

// node 구조체 생성
typedef struct node {
  int data;
  struct node* prev;
  struct node* next;
} Node;

// Deque 구조체 생성
typedef struct Deque {
  Node* head;
  Node* tail;
} Deque;

void DequeInit(Deque* deque) {
  deque->head = NULL;
  deque->tail = NULL;
}

int isEmpty(Deque* deque) {
  if (deque->head == NULL) {
    return 1;
  } else {
    return 0;
  }
}

// 덱의 앞에 데이터 추가
void push_front(Deque* deque, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = deque->head;

  if (isEmpty(deque)) {
    deque->tail = newNode;
  } else {
    deque->head->prev = newNode;
  }

  newNode->prev = NULL;
  deque->head = newNode;
}

// 덱의 뒤에 데이터 추가
void push_back(Deque* deque, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->prev = deque->tail;

  if (isEmpty(deque)) {
    deque->head = newNode;
  } else {
    deque->tail->next = newNode;
  }

  newNode->next = NULL;
  deque->tail = newNode;
}

int pop_front(Deque* deque) {
  Node* pfNode = deque->head;
  int pfdata;

  if (isEmpty(deque)) {
    return -1;
  }

  pfdata = deque->head->data;
  deque->head = deque->head->next;
  free(pfNode);

  if (deque->head == NULL) {
    deque->tail = NULL;
  } else {
    deque->head->prev = NULL;
  }

  return pfdata;
}

int pop_back(Deque* deque) {
  Node* pbNode = deque->tail;
  int pbdata;

  if (isEmpty(deque)) {
    return -1;
  }

  pbdata = deque->tail->data;
  deque->tail = deque->tail->prev;
  free(pbNode);

  if (deque->tail == NULL) {
    deque->head = NULL;
  } else {
    deque->tail->next = NULL;
  }

  return pbdata;
}

int front(Deque* deque) {
  if (isEmpty(deque)) {
    return -1;
  }
  return deque->head->data;
}

int back(Deque* deque) {
  if (isEmpty(deque)) {
    return -1;
  }
  return deque->tail->data;
}

int size(Deque* deque) {
  int sizeCnt = 0;
  Node* current = deque->head;

  while (current != NULL) {
    sizeCnt++;
    current = current->next;
  }

  return sizeCnt;
}

int main() {
  int N;
  scanf("%d", &N);
  Deque Deque;
  DequeInit(&Deque);
  int pushFrontNum, pushBackNum;
  char command[20];

  for (int i = 0; i < N; i++) {
    scanf("%s", command);
    if (strcmp(command, "push_front") == 0) {
      scanf("%d\n", &pushFrontNum);
      push_front(&Deque, pushFrontNum);
    } else if (strcmp(command, "push_back") == 0) {
      scanf("%d\n", &pushBackNum);
      push_back(&Deque, pushBackNum);
    } else if (strcmp(command, "pop_front") == 0) {
      printf("%d\n", pop_front(&Deque));
    } else if (strcmp(command, "pop_back") == 0) {
      printf("%d\n", pop_back(&Deque));
    } else if (strcmp(command, "size") == 0) {
      printf("%d\n", size(&Deque));
    } else if (strcmp(command, "empty") == 0) {
      printf("%d\n", isEmpty(&Deque));
    } else if (strcmp(command, "front") == 0) {
      printf("%d\n", front(&Deque));
    } else if (strcmp(command, "back") == 0) {
      printf("%d\n", back(&Deque));
    }
  }
  return 0;
}