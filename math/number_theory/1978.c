#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool findPrime(int n) {
  if (n == 1) return false;

  for (int i = 2; i < n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int N, cnt = 0;
  scanf("%d", &N);

  int nums[100];
  for (int i = 0; i < N; i++) {
    scanf("%d", &nums[i]);
  }

  for (int i = 0; i < N; i++) {
    if (findPrime(nums[i])) {
      cnt++;
    }
  }

  printf("%d", cnt);

  return 0;
}