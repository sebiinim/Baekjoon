#include <stdio.h>

int main() {
  double a1, a0, c1, c2, n0;
  scanf("%lf %lf", &a1, &a0);
  scanf("%lf %lf", &c1, &c2);
  scanf("%lf", &n0);

  // big O
  int bigO = -1;
  if (c2 > a1) {
    if (a0 / (c2 - a1) <= n0) {
      bigO = 1;
    } else
      bigO = 0;
  } else if (c2 < a1) {
    bigO = 0;
  } else {
    bigO = 1;
  }

  // big theta
  int bigT = -1;
  if (a1 > c1) {
    if ((-a0) / (a1 - c1) <= n0)
      bigT = 1;
    else
      bigT = 0;
  } else if ((a1 == c1) && (a0 >= 0)) {
    bigT = 1;
  } else {
    bigT = 0;
  }

  // printf("bigO : %d, bigT : %d\n", bigO, bigT);
  if ((bigO == 1) && (bigT == 1)) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  return 0;
}