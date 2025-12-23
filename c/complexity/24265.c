#include <stdio.h>

double sigma(double n);

int main() {
  double n;
  scanf("%lf", &n);
  double cnt = sigma(n - 1);

  printf("%.0lf\n2\n", cnt);
}

double sigma(double n) {
  double sum = 0;
  for (double i = 1; i <= n; i++) {
    sum += i;
  }

  return sum;
}