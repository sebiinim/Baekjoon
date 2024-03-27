#include <stdio.h>

// 가까운쪽으로 떨어지는 시간
int calculate1(int testlen, int positions) {
  if ((double)testlen / 2 < positions) {
    return testlen - positions;
  } else {
    return positions;
  }
}

// 먼 쪽으로 떨어지는 시간
int calculate2(int testlen, int positions) {
  if ((double)testlen / 2 < positions) {
    return positions;
  } else {
    return testlen - positions;
  }
}

int main() {
  int testnum;  // 테스트케이스 개수
  scanf("%d", &testnum);

  int testlen[100001];    // 테스트케이스의 막대 길이
  int testant[100001];    // 테스트케이스의 개미 수
  int positions[100001];  // 개미 위치
  int falltime1[100001] = {
      0,
  };
  int falltime2[100001] = {
      0,
  };

  // 테스트케이스 입력받기
  for (int i = 0; i < testnum; ++i) {
    scanf("%d %d", &testlen[i], &testant[i]);  // 테케마다 막대길이, 개미 수
    for (int j = 0; j < testant[i]; ++j) {
      scanf("%d", &positions[j]);
    }

    for (int j = 0; j < testant[i]; ++j) {
      if (calculate1(testlen[i], positions[j]) > falltime1[i]) {
        falltime1[i] = calculate1(testlen[i], positions[j]);
      }

      if (calculate2(testlen[i], positions[j]) > falltime2[i]) {
        falltime2[i] = calculate2(testlen[i], positions[j]);
      }
    }
  }

  for (int i = 0; i < testnum; ++i) {
    printf("%d %d\n", falltime1[i], falltime2[i]);
  }

  // printf("end\n");
  return 0;
}
