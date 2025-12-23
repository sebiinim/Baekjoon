#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int findLeastPrimeNumber(int i);
bool isPrime(int n);

int main() {
  int n, i = 2;
  scanf("%d", &n);

  if (n == 1) return 0;

  while (n >= i /*종료조건 생각하자*/) {
    if (n % i == 0) {
      printf("%d\n", i);
      n = n / i;
    } else {
      // i보다 큰 소수 찾아서 그 값으로 바꾸자
      i = findLeastPrimeNumber(i);
    }
  }
}

// i보다 큰 최소의 소수 찾기
int findLeastPrimeNumber(int i) {
  for (int j = i + 1;; j++) {
    if (isPrime(j)) {
      return j;
    }
  }
}

bool isPrime(int n) {
  if (n == 1) return false;

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return false;
  }
  return true;
}