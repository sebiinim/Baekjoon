#include <math.h>
#include <stdio.h>
double factorial(double n);

int main() { printf("%lf", factorial(12)); }

double factorial(double n) {
  if (n <= 1)
    return 1;
  else
    return n * factorial(n - 1);
}