#include <stdio.h>

int main() {
  double a1, a0, c, n0;
  scanf("%lf %lf", &a1, &a0);
  scanf("%lf", &c);
  scanf("%lf", &n0);

  // printf("%.0lfn + %.0lf >= %.0lfn,  n>=%.0lf\n", a1, a0, c, n0);
  // printf("%.2lf < %0.lf\n", (-a0 / (a1 - c)), n0);

  if (a1 > c) {
    if ((-a0) / (a1 - c) <= n0)
      printf("1\n");
    else
      printf("0\n");
  } else if ((a1 == c) && (a0 >= 0)) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  return 0;
}