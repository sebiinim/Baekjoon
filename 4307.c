// 4307 개미
#include <stdio.h>

int calculate1(int* len, int* position);
int calculate2(int* len, int* position);

int main() {
  int testnum;  // 테스트 케이스 개수
  scanf("%d", &testnum);

  int len[99999];  // 막대 길이 저장할 int 배열
  int antnum[99999];
  int positions[99999][100001];  // 테케 개수 * 개미 수
  // 테스트케이스 입력받기
  for (int i = 0; i < testnum; ++i) {
    scanf("%d %d", len[i], antnum[testnum]);  // 테케마다 개미 수
    for (int j = 0; j < antnum[testnum]; ++j) {
      scanf("%d", positions[testnum][j]);
    }
  }

  for (int i = 0; i < testnum; ++i) {
  }
}

// 가장 가운데 있는 애가 떨어지는 시간
int calculate1(int* len, int* position) {}

// 가장 끝에 있는 애가 반대편으로 떨어지는 시간
// 최대최소 써야할듯, qsort필요하겠는데?
int calculate2(int* len, int* position) {}