#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int static compare(const void* first, const void* second) {
  if (*(int*)first > *(int*)second)
    return 1;
  else if (*(int*)first < *(int*)second)
    return -1;
  else
    return 0;
}

int main() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    printf("0\n");
    return 0;
  }

  int difficulty[300099], sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &difficulty[i]);
    sum += difficulty[i];  // 합계를 미리 계산
  }
  int cutn = floor(n * 0.15 + 0.5);
  // printf("cutn : %d\n", cutn);

  qsort(difficulty, n, sizeof(int), compare);
  // for (int i = 0; i < n; ++i) {
  //   printf("%d ", difficulty[i]);
  // }

  for (int i = 0; i < cutn; ++i) {
    sum -= difficulty[i];  // 잘린 부분의 합을 빼기
  }

  for (int i = n - 1; i > n - cutn - 1; --i) {
    sum -= difficulty[i];  // 잘린 부분의 합을 빼기
  }

  // printf("sum : %d\n", sum);
  double avg = (double)sum / (n - 2 * cutn);

  avg = floor(avg + 0.5);
  printf("%.0lf\n", avg);
}
