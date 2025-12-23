#include <math.h>
#include <stdio.h>
#include <string.h>
#define unitTime 100000000

double factorial(double n);

int main() {
  int n;
  scanf("%d", &n);

  char O[101][100];
  double nums[101][3];

  for (int i = 0; i < n; ++i) {
    scanf("%s %lf %lf %lf", &O[i], &nums[i][0], &nums[i][1], &nums[i][2]);
  }

  for (int i = 0; i < n; ++i) {
    // O(n)
    if (strcmp(O[i], "O(N)") == 0) {
      if ((nums[i][0] * nums[i][1]) <= nums[i][2] * unitTime) {
        printf("May Pass.\n");
      } else {
        printf("TLE!\n");
      }
    }

    // O(n^2)
    else if (strcmp(O[i], "O(N^2)") == 0) {
      if (nums[i][0] >= 31623) {
        printf("TLE!\n");
      } else {
        double result = (nums[i][0] * nums[i][0]);
        if (result <= unitTime * nums[i][2] / nums[i][1]) {
          printf("May Pass.\n");
        } else {
          printf("TLE!\n");
        }
      }
    }

    // O(n^3)
    else if (strcmp(O[i], "O(N^3)") == 0) {
      if (nums[i][0] >= 1001) {
        printf("TLE!\n");
      } else {
        double result = (nums[i][0] * nums[i][0] * nums[i][0]);
        if (result <= unitTime * nums[i][2] / nums[i][1]) {
          printf("May Pass.\n");
        } else {
          printf("TLE!\n");
        }
      }
    }

    // O(2^n)
    else if (strcmp(O[i], "O(2^N)") == 0) {
      if (nums[i][0] >= 30) {
        printf("TLE!\n");
      } else {
        double result = (double)pow(2, nums[i][0]) * nums[i][1];
        if (result <= unitTime * nums[i][2]) {
          printf("May Pass.\n");
        } else {
          printf("TLE!\n");
        }
      }
    }

    // O(n!)
    else if (strcmp(O[i], "O(N!)") == 0) {
      if (nums[i][0] >= 13) {
        printf("TLE!\n");
      } else {
        if ((factorial(nums[i][0]) * nums[i][1]) <= nums[i][2] * unitTime) {
          printf("May Pass.\n");
        } else {
          printf("TLE!\n");
        }
      }
    }

    else {
      printf("failed\n");
    }
  }
}

double factorial(double n) {
  if (n <= 1)
    return 1;
  else
    return n * factorial(n - 1);
}