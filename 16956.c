// 늑대와 양
#include <stdio.h>

int main() {
  int r, c;
  scanf("%d %d", &r, &c);

  char pasture[501][501];

  // 상태 입력받기
  for (int i = 0; i < r; i++) {
    scanf("%s", &pasture[i]);
  }

  // printf("\n");
  // for (int i = 0; i < r; i++) {
  //   for (int j = 0; j < c; j++) {
  //     printf("%c", pasture[i][j]);
  //   }
  //   printf("\n");
  // }

  // S 상하좌우에 W가 있는지 체크
  int impos = 1;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (pasture[i][j] == 'S' && ((pasture[i - 1][j] == 'W') || (pasture[i + 1][j] == 'W') || (pasture[i][j - 1] == 'W') || (pasture[i][j + 1] == 'W'))) {
        impos = 0;
        break;
      }
    }
    if (impos == 0) break;
  }

  // 불가능하면(S 상하좌우에 W가 있으면) 0출력하고 종료
  if (impos == 0) {
    printf("%d\n", impos);
    return 0;
  } else {
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if ((pasture[i][j] == 'S') && (pasture[i - 1][j] == '.')) pasture[i - 1][j] = 'D';
        if ((pasture[i][j] == 'S') && (pasture[i + 1][j] == '.')) pasture[i + 1][j] = 'D';
        if ((pasture[i][j] == 'S') && (pasture[i][j - 1] == '.')) pasture[i][j - 1] = 'D';
        if ((pasture[i][j] == 'S') && (pasture[i][j + 1] == '.')) pasture[i][j + 1] = 'D';
      }
    }
  }

  // printf("pasture status\n");
  printf("%d\n", impos);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%c", pasture[i][j]);
    }
    printf("\n");
  }
}