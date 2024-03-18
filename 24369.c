#include <stdio.h>

double caly(double a2, double a1, double a0, double x);

int main() {
  double a2, a1, a0, c, n0;

  scanf("%lf %lf %lf", &a2, &a1, &a0);
  scanf("%lf", &c);
  scanf("%lf", &n0);

  double ncor = a1 / ((-2) * (a2 - c));
  //(a2-c)n^2 + a1n + a0 >= 0
  // printf("a2 : %.0lf, a1 : %.0lf, a0 : %.0lf, c : %.0lf, n0 : %.0lf\n", a2, a1, a0, c, n0);
  if (a2 - c < 0) {
    printf("0\n");
  } else if (a2 - c > 0) {
    if (n0 <= ncor) {
      if (caly(a2 - c, a1, a0, ncor) >= 0)
        printf("1\n");
      else
        printf("0\n");
    } else {
      if (caly(a2 - c, a1, a0, n0) >= 0)
        printf("1\n");
      else
        printf("0\n");
    }
  } else {
    if (a1 > 0) {
      if ((-a0) / a1 <= n0)
        printf("1\n");
      else
        printf("0\n");
    } else if (a1 == 0) {
      if (a0 > 0)
        printf("1\n");
      else
        printf("1\n");
      //!!이부분이 왜 1이지? a0<=0이면 (a2-c)n ^2 + a1n + a0 >= 0가 false인데? (a0=0일때 빼고)
    } else
      printf("0\n");
  }
}

double caly(double a2, double a1, double a0, double x) {
  double res = a2 * x * x + a1 * x + a0;

  return res;
}