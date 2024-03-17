#include <stdio.h>

int main() {
  double a1, a0, c, n0;
  scanf("%lf %lf", &a1, &a0);
  scanf("%lf", &c);
  scanf("%lf", &n0);

  // printf("%lf %lf %lf %lf\n", a1, a0, c, n0);

  if (c > a1) {
    if (a0 / (c - a1) <= n0) {
      printf("1\n");
    } else
      printf("0\n");
  } else if (c < a1) {
    printf("0\n");
  } else {
    printf("1\n");
  }

  return 0;
}