#include <stdio.h>

double caly(double a2, double a1, double a0, double x);

int main() {
  double a2, a1, a0, c, n0;

  scanf("%lf %lf %lf", &a2, &a1, &a0);
  scanf("%lf", &c);
  scanf("%lf", &n0);

  // printf("a2 : %.0lf, a1 : %.0lf, a0 : %.0lf, c : %.0lf, n0 : %.0lf\n", a2, a1, a0, c, n0);
  if (a2 > c) {
    printf("0\n");
  } else if (a2 < c) {
    double ncor = (-a1) / ((-2) * (c - a2));
    // printf("ncor : %lf\n", ncor);
    if (n0 <= ncor) {
      if (caly(c - a2, -a1, -a0, ncor) >= 0) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else {
      if (caly(c - a2, -a1, -a0, n0) >= 0) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    }
  } else {  //(a2 == c)
    if (a1 < 0) {
      if ((a0 / (-a1)) <= 0) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else if (a1 == 0) {
      if (a0 <= 0) {
        printf("1\n");
      } else {
        printf("0\n");
      }
    } else {
      printf("0\n");
    }
  }
}

double caly(double a2, double a1, double a0, double x) {
  double res = a2 * x * x + a1 * x + a0;
  return res;
}