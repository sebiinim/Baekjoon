#include <stdio.h>

long long sigma(long long a, long long b);

int main() {
  long long n;
  scanf("%lld", &n);

  printf("%lld\n3\n", (n - 2) * (n - 1) * n / 6);
  return 0;
}
