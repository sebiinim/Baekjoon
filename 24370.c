#include <stdio.h>

double caly(double a2, double a1, double a0, double x);

int main() {
  double a2, a1, a0, c1, c2, n0;

  scanf("%lf %lf %lf", &a2, &a1, &a0);
  scanf("%lf %lf", &c1, &c2);
  scanf("%lf", &n0);

  // bigO
  int bigO = -1;
  if (a2 > c2) {
    bigO = 0;
  } else if (a2 < c2) {
    double ncor = (-a1) / ((-2) * (c2 - a2));
    // printf("ncor : %lf\n", ncor);
    if (n0 <= ncor) {
      if (caly(c2 - a2, -a1, -a0, ncor) >= 0) {
        bigO = 1;
      } else {
        bigO = 0;
      }
    } else {
      if (caly(c2 - a2, -a1, -a0, n0) >= 0) {
        bigO = 1;
      } else {
        bigO = 0;
      }
    }
  } else {  //(a2 == c2)
    if (a1 < 0) {
      if ((a0 / (-a1)) <= 0) {
        bigO = 1;
      } else {
        bigO = 0;
      }
    } else if (a1 == 0) {
      if (a0 <= 0) {
        bigO = 1;
      } else {
        bigO = 0;
      }
    } else {
      bigO = 0;
    }
  }

  // big theta
  int bigtheta = -1;
  double ncor = a1 / ((-2) * (a2 - c1));
  //(a2-c)n^2 + a1n + a0 >= 0
  // printf("a2 : %.0lf, a1 : %.0lf, a0 : %.0lf, c : %.0lf, n0 : %.0lf\n", a2, a1, a0, c, n0);
  if (a2 - c1 < 0) {
    bigtheta = 0;
  } else if (a2 - c1 > 0) {
    if (n0 <= ncor) {
      if (caly(a2 - c1, a1, a0, ncor) >= 0)
        bigtheta = 1;
      else
        bigtheta = 0;
    } else {
      if (caly(a2 - c1, a1, a0, n0) >= 0)
        bigtheta = 1;
      else
        bigtheta = 0;
    }
  } else {
    if (a1 > 0) {
      if ((-a0) / a1 <= n0)
        bigtheta = 1;
      else
        bigtheta = 0;
    } else if (a1 == 0) {
      if (a0 > 0)
        bigtheta = 1;
      else
        bigtheta = 1;
    } else
      bigtheta = 0;
  }

  // printf("bigO : %d, bigtheta : %d\n", bigO, bigtheta);

  if ((bigO == 1) && (bigtheta == 1)) {
    printf("1\n");
  } else
    printf("0\n");
}

double caly(double a2, double a1, double a0, double x) {
  double res = a2 * x * x + a1 * x + a0;

  return res;
}