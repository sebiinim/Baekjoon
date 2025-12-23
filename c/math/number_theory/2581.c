#include <stdbool.h>
#include <stdio.h>

bool findPrime(int n);

int main() {
  int M, N;
  scanf("%d %d", &M, &N);

  int sum = 0, firstPrimeNumber = 0;
  bool firstPrimeCheck = false;

  for (int i = M; i <= N; i++) {
    if (findPrime(i)) {
      sum += i;
      if (firstPrimeCheck == false) {
        firstPrimeNumber = i;
        firstPrimeCheck = true;
      }
    }
  }

  if (firstPrimeCheck == false) {
    printf("-1\n");
  } else {
    printf("%d\n%d", sum, firstPrimeNumber);
  }
}

bool findPrime(int n) {
  if (n == 1) return false;

  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}