#include <stdbool.h>
#include <stdio.h>

#define MAX_PRIME 10000000

bool isPrime[MAX_PRIME + 1];  // 소수 여부를 저장하는 배열

void sieveOfEratosthenes() {
  // 배열 초기화
  for (int i = 2; i <= MAX_PRIME; ++i) isPrime[i] = true;

  // 에라토스테네스의 체 알고리즘 수행
  for (int p = 2; p * p <= MAX_PRIME; ++p) {
    if (isPrime[p] == true) {
      // p의 배수들을 소수가 아니라고 표시
      for (int i = p * p; i <= MAX_PRIME; i += p) isPrime[i] = false;
    }
  }
}

void primeFactorization(int n) {
  // 에라토스테네스의 체로 소수 배열 생성
  sieveOfEratosthenes();

  // 주어진 수를 소인수분해
  for (int p = 2; p <= n; ++p) {
    if (isPrime[p]) {
      while (n % p == 0) {
        printf("%d\n", p);
        n /= p;
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

  primeFactorization(n);

  return 0;
}
