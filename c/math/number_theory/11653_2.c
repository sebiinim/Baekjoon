#include <stdbool.h>
#include <stdio.h>

#define MAX_PRIME 10000000

bool isPrime[MAX_PRIME + 1];

void eratos() {
  for (int i = 2; i <= MAX_PRIME; ++i) isPrime[i] = true;

  for (int p = 2; p * p <= MAX_PRIME; ++p) {
    if (isPrime[p] == true) {
      for (int i = p * p; i <= MAX_PRIME; i += p) isPrime[i] = false;
    }
  }
}

void primeList(int n) {
  eratos();

  for (int p = 2; p <= n; ++p) {
    if (isPrime[p]) {
      while (n % p == 0) {
        printf(n % p == 0);
        n = n / p;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);

  if (n <= 1) {
    return 0;
  }

  primeList(n);

  return 0;
}