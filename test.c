#include <stdio.h>

double caly(double a2, double a1, double a0, double x) {
  double res = a2 * x * x + a1 * x + a0;

  return res;
}

int main() { printf("%.0lf\n", caly(1, 1, 4, 8)); }